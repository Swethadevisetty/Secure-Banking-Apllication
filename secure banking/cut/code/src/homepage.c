//Including necessary header
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bank.h"

void homepage(char username[])
{
	//Variable declaration
    int ch;
	double amount=0;
	while(1)
	{
		//Banking system option displayed to the user
	printf("\t\tBANKING SYSTEM\n");
        printf("\t\t \n\t\t 1. Withdraw\n\t\t 2. Balance Check\n\t\t 3. Edit Details or set new password\n\t\t 4. deposit\n\t\t 5.Signout\n");
	
	//Taking the choice from the user
        printf("Enter the option:\n");
        scanf("%d", &ch);
	
	//Switch the cases according to the user option
        switch(ch)
        {
	        case 1: printf("Enter the amount to withdraw : ");
		       scanf(" %lf", &amount);
		       withdraw(username, amount);
                        break;
                case 2: checkBalance(username);
                        break;
                case 3: editDetails(username);
                        break;
                case 4: deposit(username);
                        break;
                case 5: exit(1);
	        default:printf("Enter the correct value");
                break;
        }
     }
}


