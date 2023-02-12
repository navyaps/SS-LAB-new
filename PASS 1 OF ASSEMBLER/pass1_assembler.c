#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void display()
{
FILE *f1,*f2,*f3,*f4;
char str;
printf("\nContents of INPUT.txt: \n");
f1=fopen("INPUT.txt","r");
str=fgetc(f1);
while (str!=EOF)
{
    printf("%c",str);
    str=fgetc(f1);
}
fclose(f1);

printf("\nContents of SYMTAB.txt: \n");
f2=fopen("SYMTAB.txt","r");
str=fgetc(f2);
while (str!=EOF)
{
    printf("%c",str);
    str=fgetc(f2);
}
fclose(f2);

printf("\nContents of OPTAB.txt: \n");
f3=fopen("OPTAB.txt","r");
str=fgetc(f3);
while (str!=EOF)
{
    printf("%c",str);
    str=fgetc(f3);
}
fclose(f3);

printf("\nContents of INTERMEDIATE.txt: \n");
f4=fopen("INTERMEDIATE.txt","r");
str=fgetc(f4);
while (str!=EOF)
{
    printf("%c",str);
    str=fgetc(f4);
}
fclose(f4);
}


void main()
{
int start_add, locctr;
char label[20],opcode[20],operand[20],code[20],mneumonic[20];
FILE *f1,*f2,*f3,*f4;
f1=fopen("INPUT.txt","r");
f2=fopen("SYMTAB.txt","w");
f3=fopen("INTERMEDIATE.txt","w");

fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
if(strcmp(opcode,"START")==0)
{
    start_add=atoi(operand);
    locctr=start_add;
    fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
}
else
{
    locctr=0;
}
while(strcmp(opcode,"END")!=0)
{
    if(strcmp(label,"----")!=0)
    {
        fprintf(f2,"%s\t%d\n",label,locctr);
    }
    f4=fopen("OPTAB.txt","r");
    fscanf(f4,"%s\t%s",code,mneumonic);
    while(strcmp(code,"END")!=0)
    {
        if(strcmp(code,opcode)==0)
        {
            locctr+=3;
            break;
        }
        fscanf(f4,"%s\t%s",code,mneumonic);
    }
    if(strcmp(opcode,"WORD")==0)
    {
        locctr+=3;
    }
    else if(strcmp(opcode,"RESW")==0)
    {
        locctr+=3*atoi(operand);
    }
    else if(strcmp(opcode,"RESB")==0)
    {
        locctr+=atoi(operand);
    }
    else if(strcmp(opcode,"BYTE")==0)
    {
        locctr+=strlen(operand)-2;
    }
    fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    fscanf(f1,"%s\t%s\t%s",label,opcode,operand);   
}
fprintf(f3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
int prog_len=locctr-start_add;

fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
display();
}