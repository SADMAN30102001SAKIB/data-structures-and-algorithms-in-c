#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200
char stack[MAX_SIZE][MAX_SIZE];
int top = -1;

void push(char x[])
{
    if (top < MAX_SIZE - 1)
    {
        strcpy(stack[++top], x);
    }
    else
    {
        printf("Error: Stack overflow\n");
        exit(1);
    }
}

char *pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        printf("Error: Stack underflow\n");
        exit(1);
    }
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

char *evaluatePrefix(char expression[])
{
    char operand1[MAX_SIZE], operand2[MAX_SIZE];
    int len = strlen(expression) - 1; // Ignore the null terminator

    for (int i = len; i >= 0; i--)
    {
        if (expression[i] == ' ' || expression[i] == '\t')
        {
            // Skip whitespace
        }
        else if (isOperator(expression[i]))
        {
            strcpy(operand1, pop());
            strcpy(operand2, pop());

            char result[MAX_SIZE];
            sprintf(result, "(%s%c%s)", operand1, expression[i], operand2);
            push(result);
        }
        else
        {
            char operand[MAX_SIZE];
            operand[0] = expression[i];
            operand[1] = '\0';
            push(operand);
        }
    }

    if (top == 0)
    {
        return pop();
    }
    else
    {
        printf("Error: Invalid expression\n");
        exit(1);
    }
}

int main()
{
    char expression[MAX_SIZE] = "-+2*34/84";
    printf("Result: %s\n", evaluatePrefix(expression));
    return 0;
}
