#include <stdio.h>

long long power(int base, int exponent) {
    long long result = 1;
    while (exponent-- > 0) {
        result *= base;
    }
    return result;
}

int main(void) {
    long long num;
    printf("Enter an integer: ");
    scanf("%lld", &num);

    long long original = num < 0 ? -num : num;
    long long temp = original;
    int num_digits = original == 0 ? 1 : 0;
    long long count = original;

    while (count > 0) {
        num_digits++;
        count /= 10;
    }

    long long reversed_num = 0;
    long long sum_of_digits = 0;
    long long armstrong_sum = 0;

    do {
        int digit = (int)(temp % 10);
        reversed_num = reversed_num * 10 + digit;
        sum_of_digits += digit;
        armstrong_sum += power(digit, num_digits);
        temp /= 10;
    } while (temp > 0);

    if (num < 0) {
        reversed_num = -reversed_num;
        sum_of_digits = -sum_of_digits;
    }

    int is_palindrome = num == reversed_num;
    int is_armstrong = original == armstrong_sum && num >= 0;

    printf("Sum of the digits comes out to be (%lld)\n", sum_of_digits);
    printf("Reverse of number comes out to be (%lld)\n", reversed_num);
    printf("also\n");
    printf("%lld %s a palindrome.\n", num,
           is_palindrome ? "is" : "is not");
    printf("And in addition to that, it %s an Armstrong number.\n",
           is_armstrong ? "is" : "is not");

    return 0;
}