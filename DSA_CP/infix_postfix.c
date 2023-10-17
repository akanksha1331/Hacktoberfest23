#include <stdio.h>
#define MAX 20

char arr[MAX]; // operator stack
int top = -1;

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}

char peek()
{
    return arr[top];
}

char pop()
{
    if (isEmpty())
    {
        printf("Empty stack! Cannot pop");
        return -1;
    }
    char popped = arr[top];
    top--;
    return popped;
}

void push(char opr)
{
    if (isFull())
    {
        printf("Stack is full! Cannot push!");
    }
    else
    {
        top++;
        arr[top] = opr;
    }
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
    case '^':
        return 2;

    case '%':
        return 3;
    }
    return -1;
}

int convert(char *input)
{
    char output[MAX];
    int i, j;
    for (i = 0, j = -1; input[i] != '\0'; i++)
    {
        if (checkIfOperand(input[i]))
            output[++j] = input[i]; // numbers are directly added to the output array

        else if (input[i] == '(')
            push(input[i]); // push ( to the operator stack

        else if (input[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                output[++j] = pop(); // pop all operators until '(' is encountered or the stack is left empty
            }                        // stops when '(' is encountered and add the popped operators to the output array

            if (isEmpty() || peek() != '(') // empty stack
                return -1;

            else // pops the bracket
                pop();
        }

        else
        { // check for precedence
            while (!isEmpty() && precedence(input[i]) <= precedence(peek()))
                output[++j] = pop();
            push(input[i]); // Push the operator onto the stack
        }
    }
    while (!isEmpty())
        output[++j] = pop();

    output[++j] = '\0';
    printf("%s", output);
    return 0;
}

int main()
{
    char expression[50];
    printf("Enter expression: ");
    gets(expression);
    convert(expression);
    return 0;
}
// Enter expression: a+b-c
// ab+c-