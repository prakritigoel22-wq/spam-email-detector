#include <stdio.h>

int main() {
    int choice;

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Generate Multiplication Table\n");
        printf("2. Calculate Factorial\n");
        printf("3. Print Star Pattern (Right-Angled Triangle)\n");
        printf("4. Exit\n");
        printf("===========================\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int num, range;
                printf("Enter a number to generate its multiplication table: ");
                scanf("%d", &num);
                printf("Enter the range (up to what multiple): ");
                scanf("%d", &range);

                printf("\n--- Multiplication Table for %d ---\n", num);
                for (int i = 1; i <= range; i++) {
                    printf("%d x %d = %d\n", num, i, num * i);
                }
                break;
            }

            case 2: {
                int n;
                unsigned long long fact = 1;
                printf("Enter a positive integer: ");
                scanf("%d", &n);

                if (n < 0) {
                    printf("Error: Factorial does not exist for negative numbers.\n");
                } else {
                    for (int i = 1; i <= n; i++) {
                        fact *= i;
                    }
                    printf("Factorial of %d = %llu\n", n, fact);
                }
                break;
            }

            case 3: {
                int rows;
                printf("Enter the number of rows for the star pattern: ");
                scanf("%d", &rows);

                printf("\n--- Star Pattern ---\n");
                for (int i = 1; i <= rows; i++) {
                    for (int j = 1; j <= i; j++) {
                        printf("* ");
                    }
                    printf("\n");
                }
                break;
            }

            case 4:
                printf("Exiting the program...\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}