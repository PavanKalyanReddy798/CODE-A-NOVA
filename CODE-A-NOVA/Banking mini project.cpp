#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to store bank account details
struct account 
{
    int acc_no;
    char name[50];
    float balance;
};

// function declarations
void createAccount();
void deposit();
void withdraw();
void checkBalance();

int main() 
{
    int choice;

    // simple menu driven program
    while (1) 
	{
        printf("\n\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// function to create new account
void createAccount() 
{
    FILE *fp;
    struct account a;

    fp = fopen("bank.dat", "ab");  // append mode

    if (fp == NULL) 
	{
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &a.acc_no);

    printf("Enter Name: ");
    scanf(" %[^\n]", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(a), 1, fp);   // write data into file

    fclose(fp);

    printf("Account created successfully.\n");
}

// function to deposit money
void deposit() 
{
    FILE *fp;
    struct account a;
    int acc, found = 0;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    if (amount <= 0) 
	{
        printf("Invalid amount.\n");
        return;
    }

    fp = fopen("bank.dat", "rb+");  // read and write mode

    if (fp == NULL)
	 {
        printf("File not found.\n");
        return;
    }

    while (fread(&a, sizeof(a), 1, fp))
	 {
        if (a.acc_no == acc) 
		{
            a.balance += amount;

            fseek(fp, -sizeof(a), SEEK_CUR);  // move pointer back
            fwrite(&a, sizeof(a), 1, fp);     // overwrite record

            found = 1;
            printf("Deposit successful.\n");
            break;
        }
    }

    if (!found)
	 {
        printf("Account not found.\n");
    }

    fclose(fp);
}

// function to withdraw money
void withdraw()
 {
    FILE *fp;
    struct account a;
    int acc, found = 0;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    printf("Enter Withdraw Amount: ");
    scanf("%f", &amount);

    if (amount <= 0) 
	{
        printf("Invalid amount.\n");
        return;
    }

    fp = fopen("bank.dat", "rb+");

    if (fp == NULL) 
	{
        printf("File not found.\n");
        return;
    }

    while (fread(&a, sizeof(a), 1, fp))
	 {
        if (a.acc_no == acc) 
		{
            if (a.balance >= amount) 
			{
                a.balance -= amount;

                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);

                printf("Withdraw successful.\n");
            }
			 else 
			{
                printf("Insufficient balance.\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) 
	
	{
        printf("Account not found.\n");
    }

    fclose(fp);
}

// function to check balance
void checkBalance()
 {
    FILE *fp;
    struct account a;
    int acc, found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    fp = fopen("bank.dat", "rb");

    if (fp == NULL)
	 {
        printf("File not found.\n");
        return;
    }

    while (fread(&a, sizeof(a), 1, fp))
	 {
        if (a.acc_no == acc)
		 {
            printf("\nName: %s", a.name);
            printf("\nBalance: %.2f\n", a.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }

    fclose(fp);
}

