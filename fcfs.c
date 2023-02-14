//fcfs

#include<stdio.h>

struct process
{
int at,bt,tt,wt;
};

struct process p[10];
void main()
{
int n,comp_t,i;
float avg_tt,avg_wt,total;
printf("\nEnter the number of processes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("\nEnter the arrival and burst time of process %d: ",i+1);
	scanf("%d %d",&p[i].at,&p[i].bt);
}
comp_t=0;
total=0;
for(i=0;i<n;i++)
{
	comp_t+=p[i].bt;
	p[i].tt=comp_t-p[i].at;
	total+=p[i].tt;
}
avg_tt=total/n;

total=0;
for(i=0;i<n;i++)
{
	p[i].wt=p[i].tt-p[i].bt;
	total+=p[i].wt;
}
avg_wt=total/n;

printf("\nPROCESS  ARRIVAL TIME  BURST TIME  TURN AROUND TIME  WAITING TIME");
for(i=0;i<n;i++)
{
printf("\n  %d          %d           %d             %d             %d      ",i+1,p[i].at,p[i].bt,p[i].tt,p[i].wt);
}
printf("\nAverage turn around time= %f",avg_tt);
printf("\nAverage waiting time= %f",avg_wt);
}
