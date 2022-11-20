#include<stdio.h>
#include<stdlib.h>
struct processDetails
{
 int processid;
 int arrival;
 int cpu;
};

int main(int argc, char* argv[])
{
 int i,n,a,b,c,j;
 n=(argc-1)/3;
 int tt[n],rt[n],ct[n];
 struct processDetails p[n],t;
 i=1;
 j=0;
 while(i<argc)
  {
   p[j].processid=atoi(argv[i]);
   i++;
   p[j].arrival=atoi(argv[i]);
   i++;
   p[j].cpu=atoi(argv[i]);
   i++;
   j++;
  }
 for(i=0;i<n;i++)
  {
   for(j=0;j<n-1;j++)
    {
     if(p[j].arrival>p[j+1].arrival)
      {
       t=p[j];
       p[j]=p[j+1];
       p[j+1]=t;
     }
    }
   }
 int ts=p[0].arrival;
 int id,ideal=0;
 for(i=0;i<n;i++)
  {
   if(p[i].arrival> ts)
    {
      id=p[i].arrival-ts;
    }
   else
    {
     id=0; 
    }
   ideal=ideal+id;
   ts=ts+p[i].cpu+id;
   ct[i]=ts;
   tt[i]=ct[i]-p[i].arrival;
   rt[i]=ct[i]-p[i].cpu-p[i].arrival;
  }
/*
 printf("\n\n");
 printf("pid \tarrival \tcpu \t ct \t tt \t wt \n");
 for(i=0;i<n;i++)
 {
  printf("%d\t%d\t\t %d \t %d \t %d \t %d\n",p[i].processid,p[i].arrival,p[i].cpu,ct[i],tt[i],rt[i]);
 }
 */
 float avg_tt=0,avg_rt=0,avg_ct=0;
 for(i=0;i<n;i++)
 {
 	avg_tt=avg_tt+tt[i];
 	avg_rt=avg_rt+rt[i];
	avg_ct=avg_ct+ct[i];
 }
 avg_tt=(avg_tt/n);
 avg_rt=(avg_rt/n);
 avg_ct=(avg_ct/n);
 /*
 printf("Average TT = %f \n",avg_tt);
 printf("Average WT = %f \n",avg_rt);
 printf("Average CT = %f \n",avg_ct);
 */
 FILE *f;
 f=fopen("fcfs.txt","a");
 fprintf(f,"%f",avg_rt);
 fprintf(f," ");
 fprintf(f,"%f",avg_tt);
 fprintf(f," ");
 fprintf(f,"%f",avg_ct);
 fprintf(f,"\n");
 /*
 printf("CPU Ideal time = %d \n",ideal);
 printf("CPU Utilization = %d percent\n",utilization);
 */
}
