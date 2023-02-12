#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    int i,j,start_add1;
    char name[30],line[30],name1[30],start_add[10];
    printf("\nEnter the program name: ");
    scanf("%s",&name);
    FILE *f1=fopen("abs.txt","r");
    fscanf(f1,"%s",line);
    for(i=2,j=0;j<6,i<8;i++,j++)
        name1[j]=line[i];
    name[j]='\0';
    if(strcmp(name,name1)==0)
    {
        printf("\nProgram name verified \n");
        do
        {
            fscanf(f1,"%s",line);
            if(line[0]=='T')
            {
                for(i=2,j=0;i<8,j<6;i++,j++)
                {
                    start_add[j]=line[i];
                }
                start_add[j]='\0';
                start_add1=atoi(start_add);
                i=12;
                while(line[i]!='$')
                {
                    if(line[i]!='^')
                    {printf("%d\t%c%c\n",start_add1,line[i],line[i+1]);
                    i+=2;
                    start_add1++;}
                    else
                        i++;
                }
            }
            else if(line[0]=='E')
                fclose(f1);
        }while(!feof(f1));
    }
}