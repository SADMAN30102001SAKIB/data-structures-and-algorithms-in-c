#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

/*
1. Start scanning the infix expression from left to right, one character at a time.

2. If the current character is an operand (a letter or a digit), add it to the postfix expression directly.

3. If the current character is an operator & stack is empty or contains a '(' parenthesis on top, push the incoming operator onto the stack.

4. If the current character is an open parenthesis '(', push it onto the stack.

5. If the current character is a close parenthesis ')', pop operators from the stack and append them to the postfix expression until an open parenthesis '(' is encountered. Pop and discard the open parenthesis.

6. If the current character is an operator (+, -, *, /, etc.), then:
    a. If incoming symbol has higher precedence than the top of the stack, push it onto the stack. (^, *, /)
    b. If incoming symbol has lower precedence than the top of the stack, pop and push the top onto the postfix. Then taste the incoming operator against the new top of the stack. Finally push the incoming operator. (+, -)
    c. If incoming operator has equal precedence with the top of the step, pop and push the top onto the postfix. Then taste the incoming operator against the new top of the stack. Finally push the incoming operator.

7. After scanning the entire infix expression, pop any remaining operators from the stack and append them to the postfix expression.
*/

int precedence(char operator)
{
    if (operator== '*' || operator== '/')
        return 2;
    else if (operator== '+' || operator== '-')
        return 1;
    return 0;
}

int isOperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

void infixToPostfix(char *infix, char *postfix)
{
    char stack[MAX_SIZE];
    int top = -1;
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        char currentChar = infix[i];

        if (currentChar == '(')
        {
            stack[++top] = currentChar; // Open parenthesis, push onto stack
        }
        else if (currentChar == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = stack[top--]; // Pop and append operators until '(' is encountered
            }
            if (top >= 0 && stack[top] == '(')
            {
                top--; // Pop and discard '('
            }
        }
        else if (isOperator(currentChar))
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(currentChar))
            {
                postfix[j++] = stack[top--]; // Pop and append operators based on precedence
            }
            stack[++top] = currentChar; // Push current operator onto stack
        }
        else
        {
            postfix[j++] = currentChar; // Operand, append to postfix
        }
    }

    // Pop any remaining operators from the stack and append to postfix
    while (top >= 0)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
