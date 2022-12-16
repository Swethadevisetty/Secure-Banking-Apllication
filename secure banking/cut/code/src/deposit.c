#include<stdlib.h>
#include<string.h>
#include "bank.h"
#include<stdio.h>

void deposit(char uname[])
{
    struct balance b1;
    double dep_amt;
    FILE *ftranact;
    FILE *fu;
    FILE *fp;
    char utranact[SIZE]=" ";
    char ch[SIZE]=" ";    
    char *ptr;
    char tranactFile[SIZE]=" ";
    double balance;

    printf("Enter the amount to be deposited : \n");
    scanf("%lf",&dep_amt);
    strcpy(tranactFile,uname);
    strcat(tranactFile,"Transaction.dat");
    ftranact=fopen(tranactFile,"r");
    if(ftranact == NULL)
    {
    	printf("error in opening file..");
        exit(1);
    }
    // for reading the amount stored in transactions.dat file
    fread(&ch , 8,1,ftranact);
    fclose(ftranact);
    
    FILE *p=fopen(tranactFile,"w");
    if(p == NULL)
    {
    	printf("error in opening file..");
        exit(1);
    }
	// for convertng string into double datatype as to perform addition thatis deposit action
    balance = strtod(ch, &ptr);
    
    b1.depositAmt=balance+dep_amt;
    printf("Depositing amount is %lf",dep_amt); 
    fwrite(&b1,sizeof(b1),1,p);
    fclose(p);
    
    fu=fopen("allTransactions.dat","a");
    if(fu == NULL)
    {
        printf("error in opening file..");
        exit(1);
    }
	// writing to the file that amount is deposited
    fprintf(fu,"%s  deposited %lf amount",uname,dep_amt);
    fclose(fu);
    
    strcpy(utranact,uname);
    strcat(utranact,"passbook.dat");
    
    fp=fopen(utranact,"a");
    if(fp == NULL)
    {
        printf("error in opening file..");
        exit(1);
    }

    fprintf(fp,"%lf is deposited",dep_amt);
    fclose(fp);
    homepage(uname);
    return;
    
}

