#include<stdio.h>
#include<stdlib.h>

struct process
 {
  int process_id;
  int arrival,cpu;
 };

 struct status
 {
  int pid;
  int timeleft;
  int starttime;
  int endtime;
 };
 
int max_endtime(struct status a[] , int n)
 {
  int i,m=a[0].endtime;
  for(i=0;i<n;i++)
   {
    if(m<a[i].endtime)
     m=a[i].endtime;
   }
 }
 
int is_not_complete(struct status a[],int n)
 {
   int p=a[0].timeleft,i;
   for(i=0;i<n;i++)
    p=p || a[i].timeleft;
   return p;
 }
 
void main(int argc, char* argv[])
 {
  int n,i,j,q,time=0;
  n=(argc-1)/3;
  i=1;j=0;
  struct process p[n],t;
  struct status s[n];
  while(i<argc)
   {
     p[j].process_id= atoi(argv[i]);
     i++;
     p[j].arrival= atoi(argv[i]);
     i++;
     p[j].cpu= atoi(argv[i]);
     i++;
     j++;
   }
  for(i=0;i<n;i++)
   {
    for(j=0;j<n-1;j++)
     {
      if(p[j].arrival > p[j+1].arrival )
       {
        t=p[j];
        p[j]=p[j+1];
        p[j+1]=t;
       }
     }
   }
  for(i=0;i<n;i++)
   {
    s[i].pid = p[i].process_id;
    s[i].timeleft=p[i].cpu;
    s[i].starttime=-1;
    s[i].endtime=-1;
   }
  //printf("Enter the Quantum time : ");
  //scanf("%d",&q);
  q=2;
  int it=0,ideal=0;
  while(is_not_complete(s,n))
   { 
     it=0; 
     for(i=0;i<n;i++)
       {
        if(p[i].arrival <= time && s[i].timeleft!=0)
         {
          it++;
          if(s[i].starttime==-1)
            s[i].starttime=time;
            
           if(s[i].timeleft<q)
            {
             time=time+s[i].timeleft;
             s[i].timeleft=0;
             s[i].endtime=time;
            }
           else
            {
             time=time+q;
             s[i].timeleft=s[i].timeleft-q;
             s[i].endtime=time;
            }
          }
       }
      if(it==0)
       {
        ideal=ideal+1;
        time++;
       } 
    }  
 float avg_tt=0,avg_wt=0,avg_ct=0;
 //printf("\n\n");
 //printf("pid \tarrival \tcpu \t ct \t tt \t wt \n");
 for(i=0;i<n;i++)
 {
	// printf("%d\t%d\t\t %d \t %d \t %d \t %d\n",p[i].process_id,p[i].arrival,p[i].cpu,s[i].endtime,s[i].endtime-p[i].arrival,s[i].endtime-p[i].arrival-p[i].cpu);
	 avg_wt=avg_wt+(s[i].endtime-p[i].arrival-p[i].cpu);
	 avg_tt=avg_tt+(s[i].endtime);
	 avg_ct=avg_ct+(s[i].endtime-p[i].arrival);
 }
 avg_wt=avg_wt/n;
 int et=max_endtime(s,n);
 int utilization = (((et-ideal)*100)/et);
 FILE *f;
 f=fopen("round-robin.txt","a");
 fprintf(f,"%f",avg_wt);
 fprintf(f," ");
 fprintf(f,"%f",avg_tt);
 fprintf(f," ");
 fprintf(f,"%f",avg_ct);
 fprintf(f,"\n");
 
 /*
 printf("Average TT = %f \n",avg_tt);
 printf("Average WT = %f \n",avg_rt);
 printf("Average CT = %f \n",avg_ct);
 printf("CPU Ideal time = %d \n",ideal);
 printf("CPU Utilization = %d percent\n",utilization);
 */
}
