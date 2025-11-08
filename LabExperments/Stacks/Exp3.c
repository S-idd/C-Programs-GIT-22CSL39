#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define Max_Size 30

int Stack[Max_Size];
int Top = -1;

// Function to push value into stack
void push(int x) {
    if (Top == Max_Size - 1) {
        printf("\nStack Overflow\n");
        return;
    }
    Stack[++Top] = x;
}

// Function to pop value from stack
int pop() {
    if (Top < 0) {
        printf("\nStack Underflow\n");
        return -1;
    }
    return Stack[Top--];
}

int main() {
    char exp[30];
    char *st;
    int op1, op2, result;

    printf("Enter the Postfix Expression: ");
    scanf("%s", exp);

    st = exp;

    while (*st != '\0') {
        if (isdigit(*st)) {             // If operand (digit)
            push(*st - '0');            // Convert char to int and push
        }
        else {                          // Operator encountered
            op2 = pop();                // Pop two operands
            op1 = pop();

            switch (*st) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '^':
                    result = pow(op1, op2);
                    break;
                default:
                    printf("\nInvalid Operator %c\n", *st);
                    return 0;
            }

            push(result);               // Push result back to stack
        }
        st++;
    }

    printf("\nThe Final Result is: %d\n", pop());
    return 0;
}
