#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    int choice = -1;
    double num1, num2, result;
    printf("Hello, welcome to the Holberton simple calculator\n");
    while (true)
    {
        printf("\n1) Add\n");
        printf("2) Subtract\n");
        printf("3) Multiply\n");
        printf("4) Divide\n");
        printf("0) Quit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            break;
        }
        if (choice == 0) {
            printf("See you!\n");
            break;
        }
        if (choice >= 1 && choice <= 4) {
            printf("A: ");
            if (scanf("%lf", &num1) != 1) {
                printf("Invalid number.\n");
                continue;
            }
            printf("B: ");
            if (scanf("%lf", &num2) != 1) {
                printf("Invalid number.\n");
                continue;
            }
        }
        switch (choice)
        {
            case 1:
                result = num1 + num2;
                printf("Result: %.0f\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.0f\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.0f\n", result);
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.0f\n", result);
                } else {
                    printf("Error: Division by zero!\n");
                }
                break;
            default:
                printf("Unknown option.\n");
                break;
        }
    }
    return 0;
}