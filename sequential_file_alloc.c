//sequential file allocation
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int files[50];
void recurse()
{
int start,n,i,c,flag=0;
char fname[20];
printf("\nEnter the name of file to be allocated: ");
scanf("%s",fname);
printf("\nEnter the block number of the first block and the number of blocks to be allocated: ");
scanf("%d %d",&start,&n);
if(files[start]==0)
{
	for(i=0;i<n;i++)
	{
		if(files[i]==0)
			flag++;
	}
	if(flag==n)
	{	
		printf("\nFile %s : ",fname);
		for(i=start;i<start+n;i++)
		{
			files[i]=1;
			printf("%d ",i);
		}	
		printf("\nFile allocated. Do you want to enter again? (1 for yes, 0 for no): ");
		scanf("%d",&c);
		if(c==1)
			recurse();
		else
			exit(0);
	}
	else
	{
		printf("\nSome of the blocks are already allocated. Do you want to enter again? (1 for yes, 0 for no): ");
		scanf("%d",&c);
		if(c==1)
			recurse();
		else
			exit(0);
	}	
}
else
{
	printf("\nThe first block is already allocated. Do you want to enter again? (1 for yes, 0 for no): ");
	scanf("%d",&c);
	if(c==1)
		recurse();
	else
		exit(0);
}
}

void main()
{
for(int i=0;i<50;i++)
	files[i]=0;
recurse();
}
