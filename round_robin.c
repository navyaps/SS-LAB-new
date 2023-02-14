//round robin 

#include<stdio.h>

struct process
{
	int id,at,bt,tt,wt;
}p[10];

int queue[30],front=-1,rear=-1;

void insert(int p)
{
if(front==-1)
	front++;
queue[++rear]=p;
}

int delete()
{
int q=queue[front];
front++;
return q;
}

void main()
{
int i,n,temp[30],exist[30],tq,q,comp_t;
float total_tt,total_wt,avg_tt,avg_wt;
printf("\nEnter the number of processes: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
	printf("\nEnter the arrival and burst time of process %d: ",i+1);
	scanf("%d %d",&p[i].at,&p[i].bt);
	p[i].id=i+1;
	temp[i]=p[i].bt;
}

printf("\nEnter the time quantum: ");
scanf("%d",&tq);

insert(0);
exist[0]=1;

while(front<=rear)
{
q=delete();
if(p[q].bt>=tq)
{
	comp_t+=tq;
	p[q].bt-=tq;
}
else
{
	comp_t+=p[q].bt;
	p[q].bt=0;
}
for(i=0;i<n;i++)
{
	if(p[i].at<=comp_t&&exist[i]==0)
	{
		insert(i);
		exist[i]=1;
	}
}

if(p[q].bt==0)
{
	p[q].tt=comp_t-p[q].at;
	p[q].wt=p[q].tt-temp[q];
	total_tt+=p[q].tt;
	total_wt+=p[q].wt;
}
else
{
	insert(q);
}
}
avg_tt=total_tt/n;
avg_wt=total_wt/n;
printf("\nPROCESS  ARRIVAL  BURST  TURN AROUND  WAITING");
for(i=0;i<n;i++)
{
printf("\n  %d       %d      %d        %d         %d   ",p[i].id,p[i].at,temp[i],p[i].tt,p[i].wt);
}
printf("\nAverage turn around time: %f",avg_tt);
printf("\nAverage waiting time: %f",avg_wt);
}
