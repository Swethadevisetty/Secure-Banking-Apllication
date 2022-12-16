#include<stdlib.h>
#include<string.h>
#include "bank.h"
#include<stdio.h>

int withdraw(char usname[],double withdraw_amt)
{
	if(usname == NULL)
		return EXIT_FAILURE;
	if(withdraw_amt <= 0)
		return EXIT_FAILURE;
    struct balance b1;
    FILE *ftranact;
    FILE *fu;
    FILE *fp;
    char utranact[SIZE]=" ";
    char tranactFile[SIZE]=" ";
    double balance ;
    strcpy(tranactFile,usname);
    strcat(tranactFile,"Transaction.dat");
    ftranact=fopen(tranactFile,"r");
    if(ftranact==NULL)
    {
        printf("FILE NOT OPEN");
    }
	// for reading the amount stored in transactions.dat file
    fread(&balance , 8, 1, ftranact);
    printf("Current Balance before withdrawal = %lf \n",balance);
    if(balance >= withdraw_amt)
    { 
    	FILE *p=fopen(tranactFile,"w");
        b1.depositAmt = balance - withdraw_amt;
        printf("balance after withdrawal=%lf\n",b1.depositAmt);
    	fwrite(&b1,sizeof(b1),1,p);
    	fclose(p);
        printf("AMOUNT IS WITH DRAWN\n"); 

	return EXIT_SUCCESS;
    }
    
    else
    {
        printf("INSUFFICIENT AMOUNT \n");
       
	return EXIT_FAILURE;
    }

    fu=fopen("allTransactions.dat","a");
    // writing to the file that amount is withdrawn
    fprintf(fu,"%s  withdrawn %lf amount",usname,withdraw_amt);
    fclose(fu);
    strcpy(utranact,usname);
    strcat(utranact,"passbook.dat");
    fp=fopen(utranact,"a");
    fprintf(fp,"%lf is withdrawn",withdraw_amt);
    fclose(fp);

	return EXIT_SUCCESS; 
}

