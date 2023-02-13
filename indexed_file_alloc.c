//indexed file allocation

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int files[30],n,indBlock,indexBlock[30]={-1};

void recurse2();

void recurse1()
{
printf("\nEnter the index block: ");
scanf("%d",&indBlock);
if(files[indBlock]==0)
{
	printf("\nEnter the number of disk blocks used to store the file: ");
	scanf("%d",&n);
	printf("\nEnter the disk block numbers: ");
	recurse2();
}
else
{
	printf("\nThe block is already allocated. ");
	exit(0);
}
}

void recurse2()
{
int i,flag=0,block_num;
for(i=0;i<n;i++)
{
	scanf("%d",&block_num);
	if(files[block_num]==0)
		{
			flag++;
			indexBlock[i]=block_num;
		}
}
if(flag==n)
{	files[indBlock]=1;
	for(i=0;i<n;i++)
	{
		files[indexBlock[i]]=1;
	}	
	printf("\nFile allocation is done! Content of index block: ");
	for(i=0;i<n;i++)
		printf("\nDisk block %d: %d",i,indexBlock[i]);
}
else{
	printf("\nSome of the blocks are already allocated. Try again");
	for(i=0;i<30;i++)
		indexBlock[i]=-1;
}
printf("\nDo you want to enter more files?\n"); 
printf("Enter 1 for Yes, Enter 0 for No: "); 
int ch;
scanf("%d", &ch); 
if (ch == 1) 
	recurse1(); 
else 
	exit(0);
}


void main()
{
for(int i=0;i<30;i++)
	files[i]=0;
recurse1();
}
