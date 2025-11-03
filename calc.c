#include<stdio.h>

float reuse(char Operator, float Global_answer, float Take2) {
    float result;
    switch (Operator) {
        case '+':
            result = Global_answer + Take2;
            break;
        case '-':
            result = Global_answer - Take2;
            break;
        case '*':
            result = Global_answer * Take2;
            break;
        case '/':
            result = Global_answer / Take2;
            break;
    }
    return result;
}

float calculation(char Operator, float Take1, float Take2) {
    float result;
    switch (Operator) {
        case '+':
            result = Take1 + Take2;
            break;
        case '-':
            result = Take1 - Take2;
            break;
        case '*':
            result = Take1 * Take2;
            break;
        case '/':
            result = Take1 / Take2;
            break;
    }
    return result;
}

void menu() {
    printf("Please, enter a command:\n");
    printf("A. Calculate.\n");
    printf("B. Re-use answer to calculate\n");
    printf("C. Reset, set saved answer back to 0.\n");
    printf("D. Quit.\n");
    printf("Command: ");
}

int main() {
    char Menu_answer;
    float Global_answer;
    char Operator;
    float Take1, Take2;
    
    do {
        printf("-------------------------------------------------------\n");
        Menu_answer = '\0';
        Take1 = 0;
        Take2 = 0;
        menu();
        scanf(" %c", &Menu_answer);
        getchar();
        if (Menu_answer == 'A' || Menu_answer == 'a') {
            printf("Operator (currently available: +,-,*,/): ");
            scanf("%c", &Operator);

            printf("\nFirst input number? ");
            scanf("%f", &Take1);

            printf("\nSecond input number? ");
            scanf("%f", &Take2);

            Global_answer = calculation(Operator, Take1, Take2);
            printf("-------------------------------------------------------\n");
            printf("'%.0f %c %.0f =' Answer = %f / Stored Answer: %f\n", Take1, Operator, Take2, Global_answer, Global_answer);
        } else if (Menu_answer == 'B' || Menu_answer == 'b') {
            printf("Operator (currently available: +,-,*,/): ");
            scanf("%c", &Operator);
            printf("\nSecond input number? ");
            scanf("%f", &Take2);

            Global_answer = reuse(Operator, Global_answer, Take2);
            printf("-------------------------------------------------------\n");
            printf("'%.0f %c %.0f =' Answer = %f / Stored Answer: %f\n", Global_answer, Operator, Take2, Global_answer, Global_answer);

        } else if (Menu_answer == 'C' || Menu_answer == 'c') {
            Global_answer = 0;
            printf("-------------------------------------------------------\n");
            printf("Updated stored answer  = %d\n", Global_answer);
         } else if (Menu_answer == 'd'){
         } else {
            printf("-------------------------------------------------------\n");
            printf("Bad input detected! Reloading menu.\n");
        }
    } while (Menu_answer != 'D' && Menu_answer != 'd');
    printf("Thank you for using me!");
}