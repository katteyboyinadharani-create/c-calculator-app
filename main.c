#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void basicCalculator();
void scientificCalculator();
void numberAnalysis();
void conversions();
void saveHistory(const char *operation);
void viewHistory();

int main()
{
    int choice; 

    do {
        printf("\n============ MAIN MENU ============\n");
        printf("1. Basic Calculator\n");
        printf("2. Scientific Calculator\n");
        printf("3. Number Analysis\n");
        printf("4. Conversions\n");
        printf("5. History\n");
        printf("6. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                basicCalculator();
                break;
            case 2:
                scientificCalculator();
                break;

            case 3:
                numberAnalysis();
                break;

            case 4:
                conversions();
                break;

            case 5:
                viewHistory();
                break;

            case 6:
                printf("\nExiting Program. Goodbye!\n");
                break;

            default:
                printf("\nInvalid Choice! Try again.\n");
                break;
        }

    } while(choice != 6);

    return 0;
}

void basicCalculator() {
    int subChoice;
    int num1, num2, result; 
    char historyBuffer[100];

    printf("\n====== Basic Calculator =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modular Division\n");
    printf("Enter operation (1-5): ");
    scanf("%d", &subChoice);

    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);

    switch(subChoice) {
        case 1:
            result = num1 + num2;
            printf("Result (Addition): %d\n", result);
            sprintf(historyBuffer, "Basic: %d + %d = %d", num1, num2, result);
            saveHistory(historyBuffer);
            break;
        case 2:
            result = num1 - num2;
            printf("Result (Subtraction): %d\n", result);
            sprintf(historyBuffer, "Basic: %d - %d = %d", num1, num2, result);
            saveHistory(historyBuffer);
            break;
        case 3:
            result = num1 * num2;
            printf("Result (Multiplication): %d\n", result);
            sprintf(historyBuffer, "Basic: %d * %d = %d", num1, num2, result);
            saveHistory(historyBuffer);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result (Division): %d\n", result);
                sprintf(historyBuffer, "Basic: %d / %d = %d", num1, num2, result);
                saveHistory(historyBuffer);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        case 5:
            if (num2 != 0) {
                result = num1 % num2;
                printf("Result (Modulus): %d\n", result);
                sprintf(historyBuffer, "Basic: %d %% %d = %d", num1, num2, result);
                saveHistory(historyBuffer);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        default:
            printf("Invalid Operation Choice!\n");
            break;
    }
}

void scientificCalculator() {
    int choice;
    double num1, num2, result;
    char historyBuffer[100];

    printf("\n====== Scientific Calculator =====\n");
    printf("1. Power (x^y)\n");
    printf("2. Square Root (√x)\n");
    printf("3. Sine (sin x)\n");
    printf("4. Cosine (cos x)\n");
    printf("5. Logarithm (log10 x)\n");
    printf("Enter choice (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter base (x): ");
            scanf("%lf", &num1);
            printf("Enter power (y): ");
            scanf("%lf", &num2);
            result = pow(num1, num2); 
            printf("Result: %.2lf ^ %.2lf = %.2lf\n", num1, num2, result);
            sprintf(historyBuffer, "Scientific: %.2lf ^ %.2lf = %.2lf", num1, num2, result);
            saveHistory(historyBuffer);
            break;

        case 2:
            printf("Enter number: ");
            scanf("%lf", &num1);
            if (num1 >= 0) {
                result = sqrt(num1);
                printf("Result: √%.2lf = %.2lf\n", num1, result);
                sprintf(historyBuffer, "Scientific: √%.2lf = %.2lf", num1, result);
                saveHistory(historyBuffer);
            } else {
                printf("Error: Negative numbers do not have real square root!\n");
            }
            break;

        case 3:
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = sin(num1 * PI / 180.0);
            printf("Result: sin(%.2lf°) = %.4lf\n", num1, result);
            sprintf(historyBuffer, "Scientific: sin(%.2lf°) = %.4lf", num1, result);
            saveHistory(historyBuffer);
            break;

        case 4:
            printf("Enter angle in degrees: ");
            scanf("%lf", &num1);
            result = cos(num1 * PI / 180.0);
            printf("Result: cos(%.2lf°) = %.4lf\n", num1, result);
            sprintf(historyBuffer, "Scientific: cos(%.2lf°) = %.4lf", num1, result);
            saveHistory(historyBuffer);
            break;

        case 5:
            printf("Enter positive number: ");
            scanf("%lf", &num1);
            if (num1 > 0) {
                result = log10(num1);
                printf("Result: log10(%.2lf) = %.4lf\n", num1, result);
                sprintf(historyBuffer, "Scientific: log10(%.2lf) = %.4lf", num1, result);
                saveHistory(historyBuffer);
            } else {
                printf("Error: Logarithm undefined for <= 0!\n");
            }
            break;

        default:
            printf("Invalid Choice!\n");
            break;
    }
}

void numberAnalysis() {
    int num, i, flag = 0;
    long long fact = 1;

    printf("\n====== Number Analysis =====\n");
    printf("Enter an integer to analyze: ");
    scanf("%d", &num);
    printf("\n-----------------------------------\n");
    printf("     ANALYSIS RESULTS FOR: %d       \n", num);
    printf("-----------------------------------\n");

    if (num % 2 == 0) {
        printf("1. Even/Odd   : EVEN Number\n");
    } else {
        printf("1. Even/Odd   : ODD Number\n");
    }

    if (num <= 1) {
        printf("2. Prime Check : NOT a Prime Number\n");
    } else {
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("2. Prime Check : PRIME Number\n");
        else
            printf("2. Prime Check : NOT a Prime Number\n");
    }

    if (num < 0) {
        printf("3. Factorial   : Undefined for negative numbers\n");
    } else if (num > 20) {
        printf("3. Factorial   : Very large (Overflow)\n");
    } else {
        for (i = 1; i <= num; i++) {
            fact *= i;
        }
        printf("3. Factorial   : %lld\n", fact);
    }

    int temp = num, remainder, sum = 0;
    while (temp != 0) {
        remainder = temp % 10;
        sum += remainder * remainder * remainder;
        temp /= 10;
    }
    if (sum == num && num >= 0) {
        printf("4. Armstrong   : ARMSTRONG Number\n");
    } else {
        printf("4. Armstrong   : NOT an Armstrong Number\n");
    }

    printf("-----------------------------------\n");
}

void conversions() {
    int choice;
    double val, result;

    printf("\n====== Unit Conversions =====\n");
    printf("1. Length: Kilometers (km) to Meters (m)\n");
    printf("2. Length: Kilometers (km) to Miles\n");
    printf("3. Temperature: Celsius (°C) to Fahrenheit (°F)\n");
    printf("4. Currency: USD ($) to INR (₹)\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter distance in Kilometers: ");
            scanf("%lf", &val);
            result = val * 1000;
            printf("Result: %.2lf km = %.2lf meters\n", val, result);
            break;

        case 2:
            printf("Enter distance in Kilometers: ");
            scanf("%lf", &val);
            result = val * 0.621371;
            printf("Result: %.2lf km = %.2lf miles\n", val, result);
            break;

        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &val);
            result = (val * 9 / 5) + 32;
            printf("Result: %.2lf °C = %.2lf °F\n", val, result);
            break;

        case 4:
            printf("Enter amount in USD ($): ");
            scanf("%lf", &val);
            result = val * 95.15;
            printf("Result: $%.2lf = ₹%.2lf INR\n", val, result);
            break;

        default:
            printf("Invalid Choice!\n");
            break;
    }
}

void saveHistory(const char *operation) {
    FILE *fp = fopen("history.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s\n", operation);
        fclose(fp);
    }
}

void viewHistory() {
    FILE *fp = fopen("history.txt", "r");
    char line[100];

    printf("\n====== Calculation History =====\n");
    if (fp == NULL) {
        printf("No history found!\n");
        return;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}