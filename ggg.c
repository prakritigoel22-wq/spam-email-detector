#include <stdio.h>

int main() {
    // 1. Data Types Declaration
    // int: for choice
    int choice;

    // float / double: for real numbers with decimals
    float length, width, area, perimeter;
    double celsius, fahrenheit;

    printf("==================================================\n");
    printf("   FORMATTED I/O & ARITHMETIC OPERATIONS DEMO   \n");
    printf("==================================================\n");
    printf("1. Calculate Area and Perimeter of a Rectangle\n");
    printf("2. Convert Temperature (Celsius to Fahrenheit)\n");
    printf("--------------------------------------------------\n");
    printf("Enter your choice (1 or 2): ");
    
    // Formatted input using %d for integer
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\n--- AREA & PERIMETER OF A RECTANGLE ---\n");
        
        // Formatted input using %f for float values
        printf("Enter length and width of the rectangle (e.g., 10.5 4.2): ");
        scanf("%f %f", &length, &width);

        // Arithmetic operations: Multiplication (*) and Addition (+)
        area = length * width;
        perimeter = 2 * (length + width);

        // Formatted output: %.2f restricts display to 2 decimal places
        printf("\n%-15s : %8.2f units\n", "Length", length);
        printf("%-15s : %8.2f units\n", "Width", width);
        printf("----------------------------------------\n");
        printf("%-15s : %8.2f sq. units\n", "Area", area);
        printf("%-15s : %8.2f units\n", "Perimeter", perimeter);

    } else if (choice == 2) {
        printf("\n--- TEMPERATURE CONVERSION (C to F) ---\n");
        
        // Formatted input using %lf for double values
        printf("Enter temperature in Celsius (e.g., 37.5): ");
        scanf("%lf", &celsius);

        // Arithmetic operations: Multiplication (*), Division (/), and Addition (+)
        fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

        // Formatted output: %.2lf restricts display to 2 decimal places
        printf("\n%-20s : %8.2lf deg C\n", "Input Celsius", celsius);
        printf("%-20s : %8.2lf deg F\n", "Converted Fahrenheit", fahrenheit);

    } else {
        printf("\nInvalid Choice! Please run the program and enter 1 or 2.\n");
    }

    return 0;
}
