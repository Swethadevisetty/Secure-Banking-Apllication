#ifndef BANK_H
#define BANK_H

#define SIZE 200
#define BUFFER_SIZE 1000
#define IP_ADDRESS "172.31.16.226"
#define PORT_NUMBER 8050

// Creating a structure to store
// data of the user
typedef struct pass {
        char username[SIZE];
        int date, month, year;
        char pnumber[SIZE];
        char adharnum[SIZE];
        char fname[SIZE];
        char lname[SIZE];
        char fathname[SIZE];
        char mothname[SIZE];
        char address[SIZE];
        char typeaccount[SIZE];
        long int accountno;
}pass;

typedef struct userpassword{
        char password[SIZE];
}userpassword;

typedef struct balance{
        double depositAmt;
}balance;

typedef struct loginUnamePword{
	char uname[SIZE];
	char pword[SIZE];
}loginUnamePword;

void displayMenu(char*);
void account(void);
void login();
void homepage(char*);
void deposit(char*);
int withdraw(char*,double);
void checkBalance(char*);
void editDetails(char*);



#endif

	
