#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

void printHeader();
void loading();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void moneyInvest(float *balance);
void moneyDonate(float *balance);
void menuExit();
void errorMessage();
void mainMenu();
int safeInput();

int main() {
    printHeader();

    int option;
    float balance = 888.88;
    int choose;
    bool continueTransactions = true;

    while (continueTransactions) {
        mainMenu();

        printf("\t\t\t\t\t =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("\t\t\t\t\t Your Selection:\t");
        option = safeInput();

        switch (option) {
            case 1:
                system("CLS");
                checkBalance(balance);
                break;
            case 2:
                system("CLS");
                balance = moneyDeposit(balance);
                break;
            case 3:
                system("CLS");
                balance = moneyWithdraw(balance);
                break;
            case 4:
                system("CLS");
                moneyInvest(&balance);
                break;
            case 5:
                system("CLS");
                moneyDonate(&balance);
                break;
            case 6:
                system("CLS");
                menuExit();
                return 0;
            default:
                errorMessage();
                break;
        }

        printf("\n\t\t\t\t\t =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\t\t\t\t\t Do you wish to have another transaction? (y/n): \n\n");
        printf("\t\t\t\t\t [ 1 ] Yes \n");
        printf("\t\t\t\t\t [ 2 ] No \n\n");
        printf("\t\t\t\t\t =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n");
        printf("\t\t\t\t\t Your Selection:\t");
        choose = safeInput();

        system("CLS");

        if (choose == 2) {
            continueTransactions = false;
            menuExit();
        }
    }

    return 0;
}

void printHeader() {
    printf("\n\n");
    printf("\t  ================                =======              ============        ========     ======        ======= \n");
    Sleep(200);
    printf("\t  =====       =====            =====   =====            =====  =====         =====       =====        =====   \n");
 	Sleep(200);
    printf("\t  ====         ======         =====     =====           =====   =====        =====       =====      =====     \n");
    Sleep(200);
    printf("\t  =====       =======        =====       =====          =====    =====       =====       =====    =====       \n");
     Sleep(200);
    printf("\t  ===============           ===================         =====     =====      =====       ======== ====        \n");
     Sleep(200);
    printf("\t  =====       =======      =====================        =====      =====     =====       =====    =====       \n");
     Sleep(200);
    printf("\t  =====        ======     ======           ======       =====       =====    =====       =====       =====     \n");
     Sleep(200);
    printf("\t  =====       =====      ======             ======      =====        =====   =====       =====          =====  \n");
     Sleep(200);
    printf("\t  ==============      ==========         ==========    =======         ============      =======         ======= \n");
     Sleep(200); 
    printf("\n\n\n");
    Sleep(190);
    printf("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=+=+=+\n");
    Sleep(180);
    printf("\t\t\t\t        Created by Under Coder JUAN | BJORN | JHERSON |        \n");
    Sleep(170);
    printf("\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=+=+=+\n");
    Sleep(160);
    printf("\n\n\n");
    Sleep(150);
    printf("\t\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=\n");
    Sleep(140);
    printf("\t\t\t\t\t      Welcome to the IT BANK                \n");
    Sleep(120);
    printf("\t\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=++=+=+=+=+=+=+=+=+\n");
    Sleep(110);
    printf("\n\n\n");
    loading();
}

void loading() {
    int DotTime = 480;

    printf("\t\t\t\t\t\t\t Loading");
    for (int LoadingDot = 0; LoadingDot < 8; LoadingDot++) {
        printf(".");
        Sleep(DotTime);
    }

    printf("\n\t\t\t\t\t\t\t Please Wait");
    for (int LoadingDot = 0; LoadingDot < 8; LoadingDot++) {
        printf(".");
        Sleep(DotTime);
    }
    system("CLS");
}

void checkBalance(float balance) {
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t Hello!\n");
    printf("\t\t\t\t\t\t Your Current Balance is: %.2f \n", balance);
}

float moneyDeposit(float balance) {
    float amount;
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t Enter the Amount to Deposit in Pesos: ");
    amount = safeInput();

    balance += amount;
    printf("\n\n\n\n\n\n");
    printf("\t\t\t--------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t Deposit Successful. Current Balance: %.2f Pesos\n", balance);

    return balance;
}

float moneyWithdraw(float balance) {
    float amount;
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t Enter the Amount to Withdraw in Pesos: ");
    scanf("%f", &amount);

    if (amount > balance) {
        printf("\n\n\n\n\n\n");
        printf("\t\t\t--------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t Insufficient Funds. Withdrawal Canceled.\n");
    } else {
        balance -= amount;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t--------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t Withdrawal Successful. Current Balance: %.2f Pesos\n", balance);
    }

    return balance;
}

void moneyInvest(float *balance) {
    float investPercentage;
    
    printf("\n\n\n\n\n\n");
    printf("\t\t Enter the Percentage (0 to 100) of your Balance to Invest with a 5 percent Interest rate: ");
    scanf("%f", &investPercentage);
 
    if (investPercentage < 0 || investPercentage > 100) {
        printf("\n\n\n\n\n\n");
        printf("\t\t\t--------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t Invalid Percentage. Please enter a value between 0 and 100.\n");
    } else {
        // Calculate the investment amount and interest earned
        float investmentAmount = (investPercentage / 100) * (*balance);
        float interestRate = 0.05;  // Assume a 5% interest rate
        float earnedInterest = investmentAmount * interestRate;

        // Update the balance with the earned interest
        *balance += earnedInterest;

        printf("\n\n\n\n\n\n");
        printf("\t\t\t--------------------------------------------------------------------------------\n\n\n");
        printf("\t\t\t\t You invested %.2f Pesos and earned %.2f Pesos in Interest.\n\n", investmentAmount, earnedInterest);
        printf("\t\t\t\t\t Current Balance: %.2f Pesos\n", *balance);
    }
}

void moneyDonate(float *balance) {
    float donationAmount;
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t Enter the Amount you want to Donate in Pesos: ");
    scanf("%f", &donationAmount);

    if (donationAmount <= 0 || donationAmount > *balance) {
        printf("\n\n\n\n\n\n");
        printf("\t\t\t--------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t Invalid Donation Amount. Please enter a Valid Amount.\n");
    } else {
        *balance -= donationAmount;
        printf("\n\n\n\n\n\n");
        printf("\t\t\t--------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t Thank you for your Donation of %.2f Pesos.\n\n", donationAmount);
        printf("\t\t\t\t\t Current Balance: %.2f Pesos\n", *balance);
    }
}

void menuExit() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t Thank you for using the IT BANK Machine. Goodbye!\n\n\n\n\n\n\n\n");
    printf("\n\n\n\n\n");
}

void errorMessage() {
    printf("\n\n");
    printf("\t--------------------------------------------------------------------------------------------------");
    printf("\n\n\n");
    printf("\t\t\t\t\t Invalid Option. Please choose a Valid Option.\n");
}

void mainMenu() {
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t Hello!\n");
    printf("\t\t\t\t\t\t Welcome to IT BANK \n\n");
    printf("\t\t\t\t\t =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t\t\t\t Please choose one of the options below\n\n");
    printf("\t\t\t\t\t [ 1 ]  Check Balance\n");
    printf("\t\t\t\t\t [ 2 ]  Deposit\n");
    printf("\t\t\t\t\t [ 3 ]  Withdraw\n");
    printf("\t\t\t\t\t [ 4 ]  Invest\n");
    printf("\t\t\t\t\t [ 5 ]  Donate\n");
    printf("\t\t\t\t\t [ 6 ]  Proceed to Exit\n\n");
}

int safeInput() {
    int value;

    while (true) {
        printf(" ");
        if (scanf("%d", &value) == 1) {
            break;
        } else {
            while (getchar() != '\n');  // Clear input buffer
            printf("\n\n");
            printf("\t--------------------------------------------------------------------------------------------------");
            printf("\n\n\n");
            printf("\t\t\t\t\t Invalid input. Please enter a number. Thank you!\n");
        }
    }
    return value;
}
