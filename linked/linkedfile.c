//linked file allocation

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
};

int count,a[30]={0};
struct node *f[10];
struct node* p;

void linked()
{
int i,c,n,b;
char s[10];
printf("\nEnter the number of blocks used to allocate file %d: ",count+1);
scanf("%d",&n); 
struct node* temp;
for(i=0;i<n;i++)
{
temp=(struct node*)malloc(sizeof(struct node));
printf("\nEnter the block number of block %d: ",i+1);
scanf("%d",&b);
if(a[b]==1)
{
	printf("\nThe block is already allocated. Do you want to enter again? (1 for yes, 0 for no): ");
	scanf("%d",&c);
	p=f[count];
	while(p->link!=NULL)
	{
	a[p->data]=0;
	p=p->link;
	}
	a[p->data]=0;
	f[count]=NULL;
	if(c==1)
		linked();
	else
		exit(0);
}
a[b]=1;
temp->data=b;
temp->link=NULL;
if(i==0)
{
	f[count]=temp;
}
else
{
	p=f[count];
	while(p->link!=NULL)
	{
		p=p->link;
	}	
	p->link=temp;
}
}
count++;
printf("\nFile directory");
for(i=0;i<count;i++)
{
printf("\nFile %d -->",i+1);
p=f[i];
while(p->link!=NULL)
{printf(" b%d-->",p->data);
p=p->link;
}
printf(" b%d-->NULL \n\n",p->data);

}
printf("\nDo you want to allocate more files? (1 for yes, 0 for no): ");
scanf("%d",&c);
if(c==1)
	linked();
else
	exit(0);
}

void main()
{
count=0;
linked();
}

