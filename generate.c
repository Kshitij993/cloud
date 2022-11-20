#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int a[50][12],i,j;
	FILE *f;
	for(i=0;i<50;i++)
 	{
		for(j=0;j<12;j++)
  		{
			a[i][j]= (rand()% (50-1+1));
		}
	}
	f=fopen("array.txt","a");
	for(i=0;i<50;i++)
	{
		for(j=0;j<12;j++)
		{
			fprintf(f,"%d",a[i][j]);
			fprintf(f,"%c",',');
		}
		fprintf(f,"\n");
	}
	fclose(f);
}
