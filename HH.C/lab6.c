#include <stdio.h>

// Function for deposit
float deposit(float balance, float amount) {
    return balance + amount;
}

// Function for withdrawal
float withdraw(float balance, float amount) {
    return balance - amount;
}

int main() {
    float balance, amount;
    int choice;

    printf("Enter opening balance: ");
    scanf("%f", &balance);

    if (balance < 0) {
        printf("Error: Opening balance cannot be negative!\n");
        return 0;
    }

    printf("\n--- Banking Menu ---\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check balance\n");
    printf("Enter choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter deposit amount: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Error: Amount must be positive!\n");
            } else {
                balance = deposit(balance, amount);
                printf("Deposit successful! Updated balance: Rs. %.2f\n", balance);
            }
            break;

        case 2:
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Error: Amount must be positive!\n");
            } else if (amount > balance) {
                printf("Error: Insufficient balance!\n");
            } else {
                balance = withdraw(balance, amount);
                printf("Withdrawal successful! Updated balance: Rs. %.2f\n", balance);
            }
            break;

        case 3:
            printf("Current Balance: Rs. %.2f\n", balance);
            break;

        default:
            printf("Error: Invalid menu choice!\n");
    }

    return 0;
}