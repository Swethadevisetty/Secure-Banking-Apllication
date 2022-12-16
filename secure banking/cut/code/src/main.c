// Including the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//Main menu switch cases
	int ch ;
	while(1)
        {
	printf("==========================================================================\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$   Secure Banking   $$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("==========================================================================\n");
	printf("1.Create Account\n");
	printf("2.Already user login\n");
	printf("3.Exit\n");
	printf("Enter your choice:");

	scanf("%d",&ch);
	
	switch(ch)
        {
                case 1: account();
                        break;
		        case 2: login();
                        break;
                case 3: exit(0);

        }
    }
}
