#include <stdio.h>
#include <stdlib.h>
#include "jobs.h"
#include "scheduler.h"

// Priority Scheduling -- Jobs with highest priority (lowest number) run first
//   -- If two jobs with same priority, lower index runs first
void priority(int n_jobs, Job* jobs)
{
    qsort(jobs, n_jobs, sizeof(Job), jobcmp);
    for(int i = 0; i < n_jobs; i++){
        jobs[i].run_job(jobs[i].time);
    }
}

// Priority Scheduling with Round Robin -- Jobs with highest priority (lowest number)
//    run first
//    -- If two jobs have same priority, run both in round robin 
//    -- Time slice for round robin passed as a parameter
void priority_rr(int n_jobs, Job* jobs, int time_slice)
{
    qsort(jobs, n_jobs, sizeof(Job), jobcmp);
    int last_sent = -1;
    for(int i = 0; i < n_jobs - 1; i++){
        if(jobs[i].priority != jobs[i+1].priority){
            //then we need to send previous data
            if(last_sent+1 == i){
                jobs[i].run_job(jobs[i].time);
            }
            else{
                int total_time = 0;
                for(int tt = last_sent+1; tt <= i; tt++) total_time = total_time + jobs[tt].time;
                while(total_time > 0){
                    for(int j = last_sent + 1; j <= i; j++){
                        if(jobs[j].time == 0){
                            //printf("job complete, time %d\n", jobs[j].time);
                        }
                        else if(jobs[j].time < time_slice){ 
                            jobs[j].run_job(jobs[j].time);
                            total_time = total_time - jobs[j].time;
                            //printf("job %d run, time %d\n", j, jobs[j].time);
                        }
                        else if(jobs[j].time >= time_slice){
                            jobs[j].run_job(time_slice);
                            total_time = total_time - time_slice;
                            //printf("job %d run for time slice %d, time %d\n", j, time_slice, jobs[j].time);
                        }
                        else printf("we shouldn't get here\n");
                    }
                }
                last_sent = i;
            }
        }
        else if(jobs[i].priority == jobs[i+1].priority && i == n_jobs - 2){
            //pretty much just move on except if the last case is the same
           if(i + 1 == n_jobs - 1){
              int total_time = 0;
              for(int tt = last_sent+1; tt <= i; tt++) total_time = total_time + jobs[tt].time;
              while(total_time > 0){
                  for(int j = last_sent + 1; j <= i; j++){
                      if(jobs[j].time == 0){
                          //printf("job, complete, time %d\n", jobs[j].time);
                      }
                      else if(jobs[j].time < time_slice){
			  jobs[j].run_job(jobs[j].time);
 			  total_time -= jobs[j].time;
			  //printf("job %d run, time %d\n", j, jobs[j].time);
		      }
		      else if(jobs[j].time >= time_slice){
		          jobs[j].run_job(time_slice);
			  total_time -= time_slice;
			  //printf("job %d run for time slice %d, time %d\n", j, time_slice, jobs[j].time);
      		      }
		      else printf("we shouldn't get here\n");
                  }
                  
              } 
           }  
        }
        else printf("no priority?\n");
    }    
}


