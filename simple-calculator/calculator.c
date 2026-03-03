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
        printf("5) Quit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            break;
        }

        if (choice == 5) {
            printf("See you!\n");
            break;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            if (scanf("%lf %lf", &num1, &num2) != 2) {
                printf("Invalid numbers.\n");
                continue;
            }
        }

        switch (choice)
        {
            case 1:
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2f\n", result);
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