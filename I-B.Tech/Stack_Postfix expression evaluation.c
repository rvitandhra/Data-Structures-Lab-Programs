//Postfix expression evaluation using Stack
#include <stdio.h>  
#include <stdlib.h>  
#define MAX_SIZE 100  
// Stack implementation  
int stack[MAX_SIZE];  
int top = -1;  
void push(int value) {  
    if (top >= MAX_SIZE - 1) {  
		printf("Stack Overflow\n");  
        return;  
    }  
    top++;  
    stack[top] = value;  
}  
int pop() {  
    if (top < 0) {  
		printf("Stack Underflow\n");  
        return -1;  
    }  
    int value = stack[top];  
    top--;  
    return value;  
}  

int evaluate(char* expression) {  
    int i = 0;  
    char symbol = expression[i];  
    int operand1, operand2, result;  
  
    while (symbol != '\0') 
	{  
        if (symbol >= '0' && symbol <= '9') {  
            int num = symbol - '0';  
            push(num);  
        }  
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {  
            operand2 = pop();  
            operand1 = pop();  
            switch(symbol) {  
                case '+': result = operand1 + operand2; break;  
                case '-': result = operand1 - operand2; break;  
                case '*': result = operand1 * operand2; break;  
                case '/': result = operand1 / operand2; break;  
            }  
            push(result);  
        }  
		i++;  
        symbol = expression[i];  
    }  
    result = pop();  
    return result;  
}  
  
void main() {  
    char expression[] = "5 6 7 + * 8 -";  
    int result = evaluate(expression);  
	printf("Result= %d\n", result);  
}  
