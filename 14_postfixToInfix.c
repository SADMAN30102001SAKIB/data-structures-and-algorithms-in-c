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

char *evaluatePostfix(char expression[])
{
    char operand1[MAX_SIZE], operand2[MAX_SIZE];

    while (*expression != '\0')
    {
        if (*expression == ' ' || *expression == '\t')
        {
            // Skip whitespace
        }
        else if (isOperator(*expression))
        {
            strcpy(operand2, pop());
            strcpy(operand1, pop());

            char result[MAX_SIZE];
            sprintf(result, "(%s%c%s)", operand1, *expression, operand2);
            push(result);
        }
        else
        {
            char operand[MAX_SIZE];
            operand[0] = *expression;
            operand[1] = '\0';
            push(operand);
        }

        expression++;
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
    char expression[MAX_SIZE] = "12+31+*2/";
    printf("Result: %s\n", evaluatePostfix(expression));
    return 0;
}
