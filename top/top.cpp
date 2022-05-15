#include <thread>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <string.h>
#include <iomanip>
#include <sstream>
#define PROC_STAT_COUNT (10)

void findallthread(int pid, std::vector<int>& thrdslst)
{
	char cmd[100]={0};
	sprintf(cmd, "ls /proc/%d/task/ > tid",pid);
    system(cmd);
    system("sed ':a;N;$!ba;s/\\n/,/g' > tids");
    std::ifstream t("./tids");
    std::stringstream buffer;
    buffer << t.rdbuf();

	std::cout<<" file content"<<buffer.str() <<std::endl;

	std::string parsed;
	std::stringstream input_stringstream(buffer.str());

	if (std::getline(input_stringstream,parsed,','))
	{
		if(parsed.length()>0){
			std::cout<<parsed <<std::endl;
			thrdslst.push_back(atoi(parsed.c_str()));
		}
	}
	return;

}
struct pstat
  {
    long unsigned int utime_ticks;
    long int cutime_ticks;
    long unsigned int stime_ticks;
    long int cstime_ticks;
    long unsigned int vss; //virtual memory size in bytes
    long unsigned int rss; //Resident  Set  Size in bytes
    long unsigned int cpu_total_time;
  };

/*
* read /proc data into the passed struct pstat
* returns 0 on success, -1 on error
*/
int get_usage(const int pid, const int tid, struct pstat *result)
{
  // convert  pid to string
  //std::cout << "[get_usage] : pid \t=" << pid << std::endl;

  char tid_s[256] = {0};
  snprintf(tid_s, sizeof(tid_s) - 1, "/proc/%d/task/%d/stat", pid,tid);

  FILE *fpstat = ::fopen(tid_s, "r");
  if (fpstat == NULL)
  {
    ::perror("[get_usage] : stat_filepath FOPEN ERROR ");
    return -1;
  }

  char pid_s[256] = {0};
  snprintf(pid_s, sizeof(pid_s) - 1, "/proc/%d/stat", pid);

  FILE *fstat = ::fopen(pid_s, "r");
  if (fstat == NULL)
  {
    ::perror("[get_usage] : fstat FOPEN ERROR ");
    ::fclose(fpstat);
    return -1;
  }

  //read values from /proc/pid/star
  long int rss;
  ::memset(result, 0, sizeof(struct pstat));
  if (::fscanf(fpstat, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %lu"
                       "%lu %ld %ld %*d %*d %*d %*d %*u %lu %ld",
               &result->utime_ticks, &result->stime_ticks,
               &result->cutime_ticks, &result->cstime_ticks, &result->vss, &rss) == EOF)
  {
    ::fclose(fpstat);
    ::fclose(fstat);
    return -1;
  }
  ::fclose(fpstat);
  result->rss = rss;

  //read+calc cpu total time from /proc/stat
  long unsigned int cpu_time[PROC_STAT_COUNT];
  ::memset(cpu_time, 0, sizeof(cpu_time));
  if (::fscanf(fstat, "%*s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
               &cpu_time[0], &cpu_time[1], &cpu_time[2], &cpu_time[3],
               &cpu_time[4], &cpu_time[5], &cpu_time[6], &cpu_time[7],
               &cpu_time[8], &cpu_time[9]) == EOF)
  {
    ::fclose(fstat);
    return -1;
  }

  ::fclose(fstat);

  for (int i = 0; i < PROC_STAT_COUNT; ++i)
  {
    result->cpu_total_time += cpu_time[i];
  }

  return 0;
}

/*
* calculates the elapsed CPU usage between 2 measuring points. in percent
*/
void calc_cpu_usage_pct(const struct pstat *cur_usage, const struct pstat *last_usage, double *ucpu_usage, double *scpu_usage)
{
  const long unsigned int total_time_diff = cur_usage->cpu_total_time - last_usage->cpu_total_time;
  *ucpu_usage = 100 * (((cur_usage->utime_ticks + cur_usage->cutime_ticks) - (last_usage->utime_ticks + last_usage->cutime_ticks)) / (double)total_time_diff);
  //std::cout << "ucpu_usage\t" << *ucpu_usage << "%" << std::endl;
  *scpu_usage = 100 * ((((cur_usage->stime_ticks + cur_usage->cstime_ticks) - (last_usage->stime_ticks + last_usage->cstime_ticks))) / (double)total_time_diff);
  //std::cout << "scpu_usage\t" << *scpu_usage << "%" << std::endl;
}

int pidof(const char *process_name)
{
  FILE *fp;
  char pidofCmd[100] = {0};
  int pidValue = -1;

  if (process_name != NULL)
  {
    ::strncpy(pidofCmd, "pidof ", strlen("pidof "));
    ::strncat(pidofCmd, process_name, strlen(process_name));
    ::strncat(pidofCmd, " > /tmp/pidof", strlen(" > /tmp/pidof"));
    ::system(pidofCmd);
    fp = ::fopen("/tmp/pidof", "r");
    if (fp == NULL)
    {
      std::cout << "unable to open File : /tmp/pidof" << std::endl;
//      ::syslog(LOG_ERR, "[%s] unable to open file (/tmp/pidof)", __FILENAME__);
      return -1;
    }
    ::fscanf(fp, "%d", &pidValue);
    ::fclose(fp);
  }

  return pidValue;
}

int main(int argv, char** argc)
{



	while(1){
		std::vector<int> thrdslst;
		int pid = pidof("EsserApp");
		if(pid> 0){
		findallthread(pid,thrdslst);
		pstat last_usage[thrdslst.size()],cur_usage[thrdslst.size()];
		int i = 0;
		for(int thrd : thrdslst){
			get_usage(pid,thrd, &last_usage[i]);
			i++;
		}
		::sleep(2);
		i = 0;
		for(int thrd : thrdslst){
			get_usage(pid,thrd, &cur_usage[i]);
			i++;
		}
		i = 0;
		double ucpu_usage,scpu_usage,Cpu_Percentage;
		for(int thrd : thrdslst){
			calc_cpu_usage_pct(&cur_usage[i], &last_usage[i], &ucpu_usage, &scpu_usage);
			Cpu_Percentage = ucpu_usage + scpu_usage;
			// cat /proc/<pid>/task/<thrd>/comm
			char pid_s[256] = {0};
			snprintf(pid_s, sizeof(pid_s) - 1, "/proc/%d/task/%d/comm", pid,thrd);
		    std::ifstream t(pid_s);
		    std::stringstream buffer;
		    buffer << t.rdbuf();
			printf("Thread %s Utilization for Gateway Application = %lf %%\n",buffer.str().c_str(), Cpu_Percentage);
			i++;
		}

	}
		else{
		printf("Esserapp not running\n");
		sleep(2);
		}
	}

}



