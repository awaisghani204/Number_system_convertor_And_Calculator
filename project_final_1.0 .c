#include <stdio.h>
#include <math.h>
#include <string.h>

// Function prototypes
void decTobinary();
void binaryTodec();
void decToOctal();
void OctToDecimal();
void hexaDeciToBinary();
void binTohex();
void performArithmetic();
void clearInputBuffer();

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear remaining input
}

int main() {
    int mainChoice, subChoice;

    printf("===============================================================================================================================================\n");
    printf("\t\t\t\t\t\tNUMBER SYSTEM CONVERTER AND CALCULATOR\n");
    printf("===============================================================================================================================================\n");
    printf("\t\t\t\t\t\t       WELCOME !\n");
    printf("\t\t\t   THIS PROJECT IS ONLY VALID FOR INTEGER TYPE DATA   \n    ");
    while (1) {
        printf("Main Menu:\n");
        printf("1. Number System Converter\n");
        printf("2. Calculator\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &mainChoice) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            clearInputBuffer(); // Clear invalid input
            continue;
        }

        if (mainChoice == 3) {
            printf("Goodbye!\n");
            break;
        }

        switch (mainChoice) {
            case 1:
                while (1) {
                    printf("Number System Converter:\n");
                    printf("1. Decimal to Binary\n");
                    printf("2. Binary to Decimal\n");
                    printf("3. Decimal to Octal\n");
                    printf("4. Octal to Decimal\n");
                    printf("5. Hexadecimal to Binary\n");
                    printf("6. Binary to Hexadecimal\n");
                    printf("7. Back to Main Menu\n");
                    printf("Enter your choice: ");
                    
                    if (scanf("%d", &subChoice) != 1) {
                        printf("Invalid input! Please enter a valid number.\n");
                        clearInputBuffer();
                        continue;
                    }

                    if (subChoice == 7) break;

                    switch (subChoice) {
                        case 1: decTobinary(); break;
                        case 2: binaryTodec(); break;
                        case 3: decToOctal(); break;
                        case 4: OctToDecimal(); break;
                        case 5: hexaDeciToBinary(); break;
                        case 6: binTohex(); break;
                        default: printf("Invalid choice! Please enter a valid option.\n");
                    }
                }
                break;

            case 2:
                performArithmetic();
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void performArithmetic() {
    int choice;
    while (1) {
        printf("Arithmetic Operations Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square Root\n");
        printf("7. Modulo\n");
        printf("8. Back to Main Menu\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            clearInputBuffer();
            continue;
        }

        if (choice == 8) break;

        int num1, num2;
        double result;

        switch (choice) {
            case 1: // Addition
                printf("Enter two numbers:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
                printf("Result (Addition): %d\n\n", num1 + num2);
                break;

            case 2: // Subtraction
                printf("Enter two numbers:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
                printf("Result (Subtraction): %d\n\n", num1 - num2);
                break;

            case 3: // Multiplication
                printf("Enter two numbers:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
                printf("Result (Multiplication): %d\n\n", num1 * num2);
                break;

            case 4: // Division
                printf("Enter two numbers:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
                if (num2 != 0) {
                    printf("Result (Division): %.2f\n\n", (double)num1 / num2);
                } else {
                    printf("Error: Division by zero is not allowed.\n\n");
                }
                break;

            case 5: // Power
                printf("Enter the base number: ");
                scanf("%d", &num1);
                printf("Enter the exponent: ");
                scanf("%d", &num2);
                result = pow(num1, num2);
                printf("Result (Power): %.2f\n\n", result);
                break;

            case 6: // Square Root
                printf("Enter a number: ");
                scanf("%d", &num1);
                if (num1 >= 0) {
                    result = sqrt(num1);
                    printf("Result (Square Root): %.2f\n\n", result);
                } else {
                    printf("Error: Square root of negative numbers is not defined.\n\n");
                }
                break;

            case 7: // Modulo
                printf("Enter two numbers:\n");
                printf("Number 1: ");
                scanf("%d", &num1);
                printf("Number 2: ");
                scanf("%d", &num2);
                if (num2 != 0) {
                    printf("Result (Modulo): %d\n\n", num1 % num2);
                } else {
                    printf("Error: Modulo by zero is not allowed.\n\n");
                }
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n\n");
        }
    }
}

// Conversion functions
void decTobinary() {
    int num;
    printf("Please enter a decimal number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input! Please enter a valid number.\n");
        clearInputBuffer();
        return;
    }
    int binarynum[64]; 
    int i = 0;
    while (num > 0) {
        binarynum[i] = num % 2;
        num /= 2;
        i++;
    }
    printf("Binary: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binarynum[j]);
    }
    printf("\n\n");
}

void binaryTodec() {
    char bnum[64];
    printf("Please enter a binary number: ");
    scanf("%s", bnum);
    int decimal = 0;
    int length = strlen(bnum);
    for (int i = 0; i < length; i++) {
        if (bnum[i] != '0' && bnum[i] != '1') {
            printf("Invalid binary number!\n\n");
            return;
        }
        decimal = decimal * 2 + (bnum[i] - '0');
    }
    printf("Decimal: %d\n\n", decimal);
}

void decToOctal() {
    int dnum;
    printf("Please enter a decimal number: ");
    if (scanf("%d", &dnum) != 1) {
        printf("Invalid input! Please enter a valid number.\n");
        clearInputBuffer();
        return;
    }
    char octnum[100];
    int i = 0;
    while (dnum != 0) {
        octnum[i] = dnum % 8;
        dnum /= 8;
        i++;
    }
    printf("Octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octnum[j]);
    }
    printf("\n\n");
}

void OctToDecimal() {
    char octnum[64];
    printf("Please enter an octal number: ");
    scanf("%s", octnum);
    int decimal = 0, digit, length = strlen(octnum);
    for (int i = 0; i < length; i++) {
        digit = octnum[i] - '0';
        if (digit < 0 || digit > 7) {
            printf("Invalid octal digit: %c\n\n", octnum[i]);
            return;
        }
        decimal = decimal * 8 + digit;
    }
    printf("Decimal: %d\n\n", decimal);
}

void hexaDeciToBinary() {
    char hexdec_num[17];
    printf("Please enter a hexadecimal number: ");
    scanf("%s", hexdec_num);
    int i = 0;
    printf("Binary: ");
    while (hexdec_num[i]) {
        switch (hexdec_num[i]) {
            case '0': printf("0000"); break;
            case '1': printf("0001"); break;
            case '2': printf("0010"); break;
            case '3': printf("0011"); break;
            case '4': printf("0100"); break;
            case '5': printf("0101"); break;
            case '6': printf("0110"); break;
            case '7': printf("0111"); break;
            case '8': printf("1000"); break;
            case '9': printf("1001"); break;
            case 'A': case 'a': printf("1010"); break;
            case 'B': case 'b': printf("1011"); break;
            case 'C': case 'c': printf("1100"); break;
            case 'D': case 'd': printf("1101"); break;
            case 'E': case 'e': printf("1110"); break;
            case 'F': case 'f': printf("1111"); break;
            default: printf("\nInvalid hex digit %c\n", hexdec_num[i]); return;
        }
        i++;
    }
    printf("\n\n");
}

void binTohex() {
    char bin_num[65];
    printf("Please enter a binary number: ");
    scanf("%s", bin_num);
    int length = strlen(bin_num), decimal = 0, power, i, remainder;
    char hexa_num[17];

    for (i = 0; i < length; i++) {
        if (bin_num[i] != '0' && bin_num[i] != '1') {
            printf("Invalid binary number!\n\n");
            return;
        }
        if (bin_num[i] == '1') {
            power = length - i - 1;
            decimal += pow(2, power);
        }
    }

    i = 0;
    while (decimal > 0) {
        remainder = decimal % 16;
        hexa_num[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        decimal /= 16;
    }

    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexa_num[j]);
    }
    printf("\n\n");
}
