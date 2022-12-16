//Including necessary headers
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include "bank.h"

void account(void)
{
	//Variables declaration
        char confirmPassword[SIZE];
        FILE *fp;
        FILE *fu;
        FILE *fpass;
	    FILE *ftranact;
        struct balance b1;
	    struct pass u1;
        struct userpassword p1;
        char fileName[SIZE] = " ";
        char passwordFile[SIZE] = " ";
        char tranactFile[SIZE] = " ";
        char ch;
      	char var[50];
    	int key = 2;
    	FILE *fptr,*fpts;
 label:
        // Input the personal information to create a new account.
        
        printf("Welcome To Online Banking");
        printf("\n\n!!!!!CREATE ACCOUNT!!!!!");
        printf("\nFIRST NAME:  ");
        scanf("%s", u1.fname);
        printf("\nLAST NAME: ");
        scanf("%s", u1.lname);
        printf("\nFATHER's NAME: ");
        scanf("%s", u1.fathname);
        printf("\nMOTHER's NAME: ");
        scanf("%s", u1.mothname);
        printf("\nADDRESS:  ");
        scanf("\n%[^\n]s", u1.address);
        printf("\nACCOUNT TYPE");
        printf("\n\t1.Savings account\n\t2.Current account\n\t3.Fixed Deposit\nEnter your choice:  ");
        scanf("%s", u1.typeaccount);
        printf("\nDATE OF BIRTH..");
        printf("\nDATE- ");
        scanf("%d", &u1.date);
        printf("\nMONTH- ");
        scanf("%d", &u1.month);
        printf("\nYEAR- ");
        scanf("%d", &u1.year);
        printf("\nAADHAR NUMBER: ");
        scanf("%s", u1.adharnum);
        printf("\nPHONE NUMBER: ");
        scanf("%s", u1.pnumber);
    	printf("\n ENTER AMOUNT FOR INITIAL DEPOSIT:  ");
    	scanf("%lf", &b1.depositAmt);
		//Taking username
        printf("\nUSERNAME: ");
        scanf("%s", u1.username);
    	//Creating the file with username as filename
        strcpy(fileName, u1.username);
        strcat(fileName, ".dat");
        //Taking password
        printf("\nPASSWORD: ");
        scanf("%s", p1.password);
        strcpy(var,p1.password);
    	fptr = fopen("pass.txt","w");
    	//Checking whether file opened or not
    	if(fptr == NULL)
	{
		printf("error");
		exit(1);
	}
	//encryting the password
	for(int j = 0;var[j]!= '\0';++j)
	{
		ch = var[j];
    	if(ch >= 'a' && ch <= 'z')
    	{
		    ch = ch+key;
		 if(ch > 'z')
		{
			ch = ch - 'z'+'a'-1;
		}
			var[j] = ch;
	}
	else if(ch >= 'A' && ch <= 'Z')
	{
			ch = ch+key;
			if(ch>'z'){
			ch = ch - 'Z'+'A'-1;
	}
			var[j] = ch;
	}
		else if(ch >= '0' && ch <= '9')
		{
			ch = ch+key;
			if(ch > '9')
			{
				ch = ch-'9'+'0'-1;
			}
			var[j] = ch;
		}
	}
        fprintf(fptr,"encryption %s",var);
	fclose(fptr);
	//decryption of password
	fptr = fopen("pass.txt","r");
	fpts = fopen("dec.txt","w");
	for(int k = 0; var[k] != '\0';++k)
	{
		ch = var[k];
		if(ch >= 'a' && ch <= 'z')
		{
			ch = ch - key;
			if(ch < 'a')
			{
			  ch = ch+'z'-'a'+1;
			}
			var[k] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z')
		{
			ch = ch-key;
			if(ch < 'A'){
			ch = ch+'Z'-'A'+1;
		}
			var[k] = ch;
		}
		else if(ch >= '0' && ch <= '9')
		{
			ch = ch-key;
			if(ch >'9')
			{
				ch = ch-'9'+'0'-1;
			}
			var[k] = ch;
		}
	}
	fprintf(fpts,"decryption %s",var);
	fclose(fptr);
	//Again taking password and compare whether passwords match
    printf("\nRETYPE PASSWORD:  ");
    scanf("%s", confirmPassword);
   if(strcmp( var, confirmPassword) == 0)
    {
        // Opening file to
        // write data of a user
        fp = fopen(fileName, "a+");
		if(fp == NULL)
	    {
        	        printf("error in opening file..");
                	exit(1);
    	}
               // Writing to the file about user information
                fprintf(fp, "First name: %s\n", u1.fname);
                fprintf(fp, "Last name: %s\n", u1.lname);
                fprintf(fp, "Father name: %s\n", u1.fathname);
                fprintf(fp, "Mother name: %s\n", u1.mothname);
                fprintf(fp, "Address: %s\n", u1.address);
                fprintf(fp, "Account type: %s\n", u1.typeaccount);
                fprintf(fp, "Date of birth: %d/%d/%d\n", u1.date, u1.month, u1.year);
                fprintf(fp, "Aadhar number: %s\n", u1.adharnum);
                fprintf(fp, "Phone number: %s\n", u1.pnumber);
                fprintf(fp, "Password: %s\n", p1.password);
                fprintf(fp, "Username: %s\n", u1.username);
               // Closing file
                fclose(fp);
               //writing to the file -> all username and password file
                fu = fopen("userNameAndPassword.dat", "a");
			if(fu == NULL)
                {
                        printf("error in opening file..");
                        exit(1);
                }
                fprintf(fu, "%s\t%s\tActive\n", u1.username, p1.password);

                fclose(fu);

                strcpy(passwordFile, u1.username);
                strcat(passwordFile, "Pass.dat");

                //writing to the file -> password of indiviuals
                fpass = fopen(passwordFile, "w");
                if(fpass == NULL)
                {
                        printf("error in opening file..");
                        exit(1);
                }

		fwrite(&p1, sizeof(p1), 1, fpass);
                //closing the file
		fclose(fpass);
		
		strcpy(tranactFile, u1.username);
		strcat(tranactFile, "Transaction.dat");
		//File to keep track of last transaction amount	
		ftranact = fopen(tranactFile, "w");
		if(ftranact == NULL)
                {
                        printf("error in opening file..");
                        exit(1);
                }

		fwrite(&b1, sizeof(b1), 1, ftranact);
		fclose(ftranact);

                printf("PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....\n");
		sleep(3);
                printf("ACCOUNT CREATED SUCCESSFULLY....\n");
                u1.accountno=rand();
                printf("Account no: %ld",u1.accountno);
                fu = fopen("accountdetails.dat", "a");
			    if(fu == NULL)
                {
                        printf("error in opening file..");
                        exit(1);
                }
                fprintf(fu,"username password accountno\n");
                fprintf(fu, "%s\t%s\t%ld\n", u1.username, p1.password,u1.accountno);

                fclose(fu);
                printf("\t\t\t\nWELCOME, %s %s\n",u1.fname, u1.lname);
                printf("\t\t\t..........................\n");
                printf("\t\t\t==== YOUR ACCOUNT INFO ====\n");
            printf("\t\t\t***************************\n");
            printf("NAME..%s %s\n", u1.fname,u1.lname);
            printf("FATHER's NAME..%s %s\n",u1.fathname,u1.lname);
            printf("MOTHER's NAME..%s\n",u1.mothname);
            printf("AADHAR CARD NUMBER..%s\n",u1.adharnum);
            printf("MOBILE NUMBER..%s\n",u1.pnumber);
            printf("DATE OF BIRTH.. %d-%d-%d\n",u1.date, u1.month, u1.year);
            printf("ADDRESS..%s\n", u1.address);
            printf("ACCOUNT TYPE..%s\n",u1.typeaccount);
		// Calling hompage 
                homepage(u1.username);
        }
        else
        {
		//if password and retype password doesn't match, then the goto lable
                goto label;
        }
        return;
}


