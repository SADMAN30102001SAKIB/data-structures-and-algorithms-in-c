#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 20

int stack[MAX_SIZE];
int top = -1;

void push(int x)
{
    if (top < MAX_SIZE - 1)
    {
        stack[++top] = x;
    }
    else
    {
        printf("Error: Stack overflow\n");
        exit(1);
    }
}

int pop()
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

int evaluatePrefix(char *expression)
{
    int operand1, operand2;
    int len = strlen(expression) - 1; // Ignore the null terminator

    for (int i = len; i >= 0; i--)
    {
        if (isdigit(expression[i]))
        {
            push(expression[i] - '0');
        }
        else if (expression[i] == ' ' || expression[i] == '\t')
        {
            // Skip whitespace
        }
        else if (isOperator(expression[i]))
        {
            operand1 = pop();
            operand2 = pop();

            switch (expression[i])
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                if (operand2 != 0)
                {
                    push(operand1 / operand2);
                }
                else
                {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                break;
            default:
                printf("Error: Invalid operator\n");
                exit(1);
            }
        }
        else
        {
            printf("Error: Invalid character in expression\n");
            exit(1);
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
    char expression[] = "-+2*34/84";
    int result = evaluatePrefix(expression);
    printf("Result: %d\n", result);
    return 0;
}
