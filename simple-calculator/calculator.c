#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main ()
{
		int choice = -1;
		double num1, num2, result;
		
		printf ("Hello, welcome to the holberton simple calculator\n");

		while (true)
		{
			printf ("1) Add\n");
			printf ("2) Subtract\n");
			printf ("3) Multiply\n");
			printf ("4) Divide\n");
			printf ("5) Quit\n");
			printf ("Choice: ");
			

			if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            break;
        }

        if (choice == 0) {
            printf("Bye!\n");
            break;
        }

            if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
        }
			
		switch (choice)
			{
				case 1:
					printf ("Enter amount:");
					scanf ("%lf", &amount);
					balance += amount;
					break;
				case 2:
					printf ("Enter amount:");
					scanf ("%lf", &amount);
					balance -= amount;
					break;

				case 3:
					printf ("%.2f\n", balance);
					break;
				
				case 4:
					printf ("%.2f\n", balance);	
					exit (0);
				
				case 5:
					exit (0);		
			}
		} 
}