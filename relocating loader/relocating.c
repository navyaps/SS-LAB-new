#include<stdio.h>
#include<string.h>

char bitmask[30],bit[12]={0};
void convert(char h[12]);
void main()
{
    int load,add,len,address,tlen,addr,i,actual_address,length,opcode;
    char input[30],pn[20],relocbit;
    FILE *f1,*f2;
    printf("\nEnter the program load address: ");
    scanf("%x",&load);
    f1=fopen("RLINPUT.txt","r");
    f2=fopen("RLOUT.txt","w");
    fscanf(f1,"%s",input);
    while(strcmp(input,"E")!=0)
    {
        if(strcmp(input,"H")==0)
        {
            fscanf(f1,"%s",pn);
            fscanf(f1,"%x",&add);
            fscanf(f1,"%x",&len);
            fscanf(f1,"%s",input);
        }
        if(strcmp(input,"T")==0)
        {
            fscanf(f1,"%x",&address);
            address+=load;
            fscanf(f1,"%x",&tlen);
            fscanf(f1,"%s",bitmask);
            convert(bitmask);
            length=strlen(bit);
            if(length>=11)
                length=10;
            for(i=0;i<length;i++)
            {
                fscanf(f1,"%x",&opcode);
                fscanf(f1,"%x",&addr);
                relocbit=bit[i];
                if(relocbit=='0')
                    actual_address=addr;
                else
                    actual_address=addr+load;
                fprintf(f2,"\n%x\t%x%x",address, opcode,actual_address);
                address+=3;
            }
            fscanf(f1,"%s",input);
        }
    }
    printf("\nContents of output file: \n ");
    fclose(f2);
    f2=fopen("RLOUT.txt","r");
    char c;
    c=fgetc(f2);
    while(c!=EOF)
    {
        printf("%c",c);
        c=fgetc(f2);
    }
    fclose(f1);
    fclose(f2);
}
void convert(char h[])
{   strcpy(bit,"");
    for(int i=0;i<strlen(h);i++)
    {
        switch(h[i])
        {
            case '0':   strcat(bit,"0");
                        break; 
            case '1':   strcat(bit,"1");
                        break; 
            case '2':   strcat(bit,"10");
                        break; 
            case '3':   strcat(bit,"11");
                        break; 
            case '4':   strcat(bit,"100");
                        break; 
            case '5':   strcat(bit,"101");
                        break; 
            case '6':   strcat(bit,"110");
                        break; 
            case '7':   strcat(bit,"111");
                        break; 
            case '8':   strcat(bit,"1000");
                        break; 
            case '9':   strcat(bit,"1001");
                        break; 
            case 'A':   strcat(bit,"1010");
                        break; 
            case 'B':   strcat(bit,"1011");
                        break; 
            case 'C':   strcat(bit,"1100");
                        break; 
            case 'D':   strcat(bit,"1101");
                        break; 
            case 'E':   strcat(bit,"1110");
                        break; 
            case 'F':   strcat(bit,"1111");
                        break;  
        }
    }
}

