//Including necessary header
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "bank.h"

void login(char username[],char password[])
{
	//Variable declaration
    int ch;
    FILE *fu;
    char username1[50],password1[50];
	double amount=0;
	struct pass u1;
	struct userpassword p1;

	printf("Enter the username:");
	scanf("%s",username1);
	printf("Enter the password:");
	scanf("%s",password1);

	while(1)
	{
		//Banking system option displayed to the user
	    printf("\t\tBANKING SYSTEM\n");
        printf("\t\t 1. Withdraw\n\t\t 2. Balance Check\n\t\t 3. Edit Details or set new password\n\t\t 4. deposit\n\t\t 5.Signout\n");
	
	//Taking the choice from the user
        printf("Enter the option:\n");
        scanf("%d", &ch);
	
	//Switch the cases according to the user option
        switch(ch)
        {
	    case 1: printf("Enter the amount to withdraw : ");
	            scanf(" %lf", &amount);
		    withdraw(username1, amount);
                        break;
            case 2: checkBalance(username1);
                        break;
            case 3: editDetails(username1);
                        break;
            case 4: deposit(username1);
                        break;
            case 5: exit(1);
            default:printf("Enter the correct value");
            break;
        }
     }
}


