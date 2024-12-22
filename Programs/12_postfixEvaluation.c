#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

int evaluatePostfix(char *expression)
{
    int operand1, operand2;

    while (*expression != '\0')
    {
        if (isdigit(*expression))
        {
            push(*expression - '0');
        }
        else if (*expression == ' ' || *expression == '\t')
        {
            // Skip whitespace
        }
        else if (isOperator(*expression))
        {
            operand2 = pop();
            operand1 = pop();

            switch (*expression)
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
    char expression[] = "12+31+*2/";
    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);
    return 0;
}
