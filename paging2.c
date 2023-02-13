//paging

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
int i,n,pages[30],f,page,offset,c;
printf("\nEnter the number of pages in logical memory: ");
scanf("%d",&n);
printf("\nEnter the number of frames in physical memory: ");
scanf("%d",&f);
for(i =0;i<n;i++)
	pages[i]=-1;
printf("\nEnter the page table: ");
printf("\nPage no Frame no");
for(i=0;i<n;i++)
{
	printf("\n %d \t  ",i);
	scanf("%d",&pages[i]);
	if(pages[i]>f)
	{
		printf("\nEntered frame number exceeds the number of frames in memory\n");
		exit(0);
	}
}
do
{
x : printf("\nEnter the logical address (page number anf offset): ");
scanf("%d %d",&page,&offset);
if(page<n)
{
	if(pages[page]==-1)
	{
		printf("\nThe page is not loaded into any frame. do you want to enter again? (1 for yes, 0 for no): ");
		scanf("%d",&c);
		if(c==1)
			goto x;
		else
			exit(0);
	}
	else
	{
		printf("\nThe physical address is: (%d, %d)",pages[page],offset);
		printf("do you want to enter again? (1 for yes, 0 for no): ");
		scanf("%d",&c);
	}
}
else
{
	printf("\nThe entered page number exceeds the number of pages in logical memory");
	printf("do you want to enter again? (1 for yes, 0 for no): ");
	scanf("%d",&c);
}
}while(c==1);
}
