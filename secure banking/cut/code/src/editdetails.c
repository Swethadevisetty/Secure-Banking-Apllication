#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bank.h"

void Pass_Update(char uname[])
{
    char fileName[SIZE] = " ";
    FILE *fp;
    strcpy(fileName,uname);
    struct userpassword p1;
    //opening the file
    fp=fopen(strcat(fileName, "Pass.dat"), "w");
    //checking the file opening success or not
    if(fp == NULL)
    {
        printf("error in file opening");
  
    }
    else
    {
	char c[50];
	printf("Enter new password for update \n");
	scanf("%s",c);
        strcpy(p1.password,c);
        fwrite(&p1,sizeof(p1),1,fp);
        fclose(fp);
        printf("done");

    }
   
}
//updating details
void Details_update()
{
    printf("Details_update");
    
}
void editDetails(char ch[])
{
        int ch1;
        printf("\t\t 1. Password updation \n\t\t 2.update details\n\t\t");
        printf("Enter the option:\n");
        scanf("%d", &ch1);

        switch(ch1)
        {
                case 1: Pass_Update(ch);
                        break;
                case 2: Details_update();
                        break;
                
        }
}

