#include <stdio.h>

int main() {
    int choice;
    int a, b, c;
    char op;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Check Positive / Negative / Zero\n");
        printf("2. Check Even or Odd\n");
        printf("3. Find Largest Among 3 Numbers\n");
        printf("4. Simple Calculator\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &a);
                if (a > 0)
                    printf("%d is Positive\n", a);
                else if (a < 0)
                    printf("%d is Negative\n", a);
                else
                    printf("The number is Zero\n");
                break;

            case 2:
                printf("Enter an integer: ");
                scanf("%d", &a);
                if (a % 2 == 0)
                    printf("%d is Even\n", a);
                else
                    printf("%d is Odd\n", a);
                break;

            case 3:
                printf("Enter three numbers: ");
                scanf("%d %d %d", &a, &b, &c);
                if (a >= b && a >= c)
                    printf("Largest is %d\n", a);
                else if (b >= a && b >= c)
                    printf("Largest is %d\n", b);
                else
                    printf("Largest is %d\n", c);
                break;

            case 4:
                printf("Enter operator (+, -, *, /): ");
                scanf(" %c", &op); // Notice the space before %c to avoid enter-key bug
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);

                switch (op) {
                    case '+': printf("Result: %d\n", a + b); break;
                    case '-': printf("Result: %d\n", a - b); break;
                    case '*': printf("Result: %d\n", a * b); break;
                    case '/': 
                        if (b != 0)
                            printf("Result: %d\n", a / b);
                        else
                            printf("Cannot divide by zero!\n");
                        break;
                    default: printf("Invalid Operator!\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                return 0; // Terminates the program cleanly

            default:
                printf("Invalid choice! Enter between 1 and 5.\n");
        }
    }
    return 0;
}