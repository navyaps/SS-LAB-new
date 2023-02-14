//non preemptive sjf

#include<stdio.h>

struct process
{
	int id,at,bt,tt,wt;
}p[10];

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}

void main()
{
int n,check_ar,i,j,comp_t,min_bt;
float total_tt,total_wt,avg_tt,avg_wt;
printf("\nEnter the number of processes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("\nEnter the arrival and burst time of process %d: ",i+1);
	scanf("%d %d",&p[i].at,&p[i].bt);
	p[i].id=i+1;
	if(i==0)
		check_ar=p[i].at;
	if(check_ar!=p[i].at)
		check_ar=1;
}
//bubble sort based on arrival time if arrival times are different
if(check_ar==1)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				swap(&p[j].id,&p[j+1].id);
				swap(&p[j].at,&p[j+1].at);
				swap(&p[j].bt,&p[j+1].bt);
			}
		}
	}
}

//sort based on burst time when arrival times are different
if(check_ar==1)
{
	comp_t=p[0].at+p[0].bt;
	p[0].tt=comp_t-p[0].at;
	p[0].wt=p[0].tt-p[0].bt;
	total_tt=p[0].tt;
	total_wt=p[0].wt;
	
	for(i=1;i<n;i++)
	{
		min_bt= p[i].bt;
		for(j=i+1;j<n;j++)
		{
			if(p[j].bt<min_bt&&p[j].at<=comp_t)
			{
				min_bt=p[j].bt;
				swap(&p[j].id,&p[i].id);
				swap(&p[j].at,&p[i].at);
				swap(&p[j].bt,&p[i].bt);
			}
		}
		comp_t+=p[i].bt;
		p[i].tt=comp_t-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		total_tt+=p[i].tt;
		total_wt+=p[i].wt;
	}
}
else
{
	for(i=0;i<n;i++)
	{
		min_bt= p[i].bt;
		for(j=i+1;j<n;j++)
		{
			if(p[j].bt<min_bt&&p[j].at<=comp_t)
			{
				min_bt=p[j].bt;
				swap(&p[j].id,&p[i].id);
				swap(&p[j].at,&p[i].at);
				swap(&p[j].bt,&p[i].bt);
			}
		}
		comp_t+=p[i].bt;
		p[i].tt=comp_t-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		total_tt+=p[i].tt;
		total_wt+=p[i].wt;
	}
}
avg_wt=total_wt/n;
avg_tt=total_tt/n;

printf("\nPROCESS  ARRIVAL TIME  BURST TIME  TURN AROUND TIME  WAITING TIME");
for(i=0;i<n;i++)
{
printf("\n  %d          %d           %d             %d             %d      ",i+1,p[i].at,p[i].bt,p[i].tt,p[i].wt);
}
printf("\nAverage turn around time= %f",avg_tt);
printf("\nAverage waiting time= %f",avg_wt);
}
