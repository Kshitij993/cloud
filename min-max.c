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
/*
 printf("pid \tarrival \tcpu \n");
 for(i=0;i<n;i++)
 	printf("%d \t %d \t\t %d \n",p[i].processid,p[i].arrival,p[i].cpu);
*/
 for(i=0;i<n;i++)
  {
   for(j=0;j<n-1;j++)
    {
     if(p[j].cpu<p[j+1].cpu && p[j].arrival>p[j+1].arrival)
      {
       t=p[j];
       p[j]=p[j+1];
       p[j+1]=t;
      }
    }
   }

  int ts=0,id,ideal=0;
 for(i=0;i<n;i++)
  {
   if(ts<p[i].arrival)
    {
      id=p[i].arrival-ts;
    }
    else
    {
     id=0;
    } 
   ideal=ideal+id;
   ts=ts+id+p[i].cpu;
   ct[i]= ts;
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
 int utilization = (((ct[n-1]-ideal)*100)/ct[n-1]);
 float avg_wt=0;
 for(i=0;i<n;i++)
	 avg_wt=avg_wt+rt[i];
 avg_wt=avg_wt/n;
 FILE *f;
 f=fopen("min-max.txt","a");
 fprintf(f,"%f",avg_wt);
 fprintf(f,"\n");
 /*
 printf("CPU Ideal time = %d \n",ideal);
 printf("CPU Utilization = %d percent\n",utilization);
 */
}
