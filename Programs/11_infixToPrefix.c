#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

/*
1. Reverse the entire expresion.

2. Start scanning the infix expression from left to right, one character at a time.

3. If the current character is an operand (a letter or a digit), add it to the prefix expression directly.

4. If stack is empty or contains a ')' parenthesis on top, push the incoming operator onto the step.

5. If the current character is an open parenthesis ')', push it onto the stack.

6. If the current character is an open parenthesis '(', pop operators from the stack and append them to the prefix expression until a close parenthesis ')' is encountered. Pop and discard the close parenthesis.

7. If the current character is an operator (+, -, *, /, etc.), then:
    a. If incoming symbol has higher precedence than the top of the stack, push it onto the stack. (*, /)
    b. If incoming symbol has lower precedence than the top of the stack, pop and print the top. Then taste the incoming operator against the new top of the stack. (+, -)
    c. If incoming operator has equal precedence with the top of the step, then push the incoming operator.

8. After scanning the entire infix expression, pop any remaining operators from the stack and append them to the prefix expression.

9. Finally again reverse it.
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

void reverseString(char *str)
{
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

void infixToPrefix(char *infix, char *prefix)
{
    char stack[MAX_SIZE];
    int top = -1;
    int i, j = 0;

    reverseString(infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        char currentChar = infix[i];

        if (currentChar == ')')
        {
            stack[++top] = currentChar; // Close parenthesis, push onto stack
        }
        else if (currentChar == '(')
        {
            while (top >= 0 && stack[top] != ')')
            {
                prefix[j++] = stack[top--]; // Pop and append operators until ')' is encountered
            }
            if (top >= 0 && stack[top] == ')')
            {
                top--; // Pop and discard ')'
            }
        }
        else if (isOperator(currentChar))
        {
            while (top >= 0 && precedence(stack[top]) > precedence(currentChar))
            {
                prefix[j++] = stack[top--]; // Pop and append operators based on precedence
            }
            stack[++top] = currentChar; // Push current operator onto stack
        }
        else
        {
            prefix[j++] = currentChar; // Operand, append to prefix
        }
    }

    // Pop any remaining operators from the stack and append to prefix
    while (top >= 0)
    {
        prefix[j++] = stack[top--];
    }

    prefix[j] = '\0';      // Null-terminate the prefix expression
    reverseString(prefix); // Reverse the prefix expression again
}

int main()
{
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
