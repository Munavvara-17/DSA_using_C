////#include <stdio.h>
////#include <stdlib.h>
////#include <ctype.h>
////#include <string.h>
////
////#define MAX_SIZE 100
////
////char stack[MAX_SIZE];
////int top = -1;
////
////char pop() {
////    if (top == -1) {
////        printf("Stack Underflow\n");
////        exit(1);
////    }
////    return stack[top--];
////}
////
////void push(char op) {
////    if (top == MAX_SIZE - 1) {
////        printf("Stack Overflow\n");
////        exit(1);
////    }
////    stack[++top] = op;
////}
////
////int precedence(char op) {
////    switch (op) {
////        case '+':
////        case '-':
////            return 1;
////        case '*':
////        case '/':
////            return 2;
////        case '^':
////            return 3;
////        default:
////            return 0;
////    }
////}
////
//////int isOperand(char ch) {
//////    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
//////}
////int isOperand(char ch) {
////    return isalnum(ch) && !isdigit(ch);
////}
////
////void infixToPostfix(char *infix, char *postfix) {
////    int i, j;
////    char ch, popped;
////
////    push('(');
////    strcat(infix, ")");
////
////    i = 0;
////    j = 0;
////    ch = infix[i++];
////
////    while (ch != '\0') {
////        if (isalnum(ch)) {
////            postfix[j++] = ch;
////        } else if (ch == '(') {
////            push(ch);
////        } else if (ch == ')') {
////            while ((popped = pop()) != '(') {
////                postfix[j++] = popped;
////            }
////        } else {
////            while (precedence(stack[top]) >= precedence(ch)) {
////                postfix[j++] = pop();
////            }
////            push(ch);
////        }
////        ch = infix[i++];
////    }
////
////    while ((popped = pop()) != '(') {
////        postfix[j++] = popped;
////    }
////
////    postfix[j] = '\0';
////}
////
////int main() {
////    char infix[MAX_SIZE], postfix[MAX_SIZE];
////
////    printf("Enter the infix expression: ");
////    fgets(infix, MAX_SIZE, stdin);
////
////    infixToPostfix(infix, postfix);
////
////    printf("Postfix expression: %s", postfix);
////
////    return 0;
////}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_SIZE 100
//
//// Define a stack structure
//struct Stack {
//    int top;
//    unsigned capacity;
//    char* array;
//};
//
//// Function to create a stack
//struct Stack* createStack(unsigned capacity) {
//    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
//    stack->top = -1;
//    stack->capacity = capacity;
//    stack->array = (char*)malloc(stack->capacity * sizeof(char));
//    return stack;
//}
//
//// Function to check if the stack is empty
//int isEmpty(struct Stack* stack) {
//    return stack->top == -1;
//}
//
//// Function to push an element to the stack
//void push(struct Stack* stack, char item) {
//    stack->array[++stack->top] = item;
//}
//
//// Function to pop an element from the stack
//char pop(struct Stack* stack) {
//    if (!isEmpty(stack))
//        return stack->array[stack->top--];
//    return '\0';
//}
//
//// Function to get the top element of the stack without popping it
//char peek(struct Stack* stack) {
//    return stack->array[stack->top];
//}
//
//// Function to check if a character is an operator
//int isOperator(char ch) {
//    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
//}
//
//// Function to get the precedence of an operator
//int getPrecedence(char op) {
//    if (op == '^')
//        return 3;
//    else if (op == '*' || op == '/')
//        return 2;
//    else if (op == '+' || op == '-')
//        return 1;
//    else
//        return 0;  // Assuming any other character has lower precedence
//}
//
//// Function to convert infix expression to postfix
//void infixToPostfix(char* infixExpression) {
//    struct Stack* stack = createStack(MAX_SIZE);
//    int i, j;
//
//    for (i = 0, j = 0; infixExpression[i] != '\0'; i++) {
//        char currentChar = infixExpression[i];
//
//        if (isalnum(currentChar))
//            printf("%c", currentChar);
//        else if (currentChar == '(')
//            push(stack, currentChar);
//        else if (currentChar == ')') {
//            while (!isEmpty(stack) && peek(stack) != '(')
//                printf("%c", pop(stack));
//            pop(stack);  // Pop '('
//        } else {
//            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(currentChar))
//                printf("%c", pop(stack));
//            push(stack, currentChar);
//        }
//    }
//
//    // Pop remaining operators from the stack
//    while (!isEmpty(stack))
//        printf("%c", pop(stack));
//}
//
//int main() {
//    char infixExpression[MAX_SIZE];
//
//    printf("Enter an infix expression: ");
//    scanf("%s", infixExpression);
//
//    printf("Postfix expression: ");
//    infixToPostfix(infixExpression);
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return precedence of operators
int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// Function to return associativity of operators
char associativity(char c) {
	if (c == '^')
		return 'R';
	return 'L'; // Default to left-associative
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(char s[]) {
	char result[1000];
	int resultIndex = 0;
	int len = strlen(s);
	char stack[1000];
	int stackIndex = -1;

	for (int i = 0; i < len; i++) {
		char c = s[i];

		// If the scanned character is an operand, add it to the output string.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			result[resultIndex++] = c;
		}
		// If the scanned character is an ‘(‘, push it to the stack.
		else if (c == '(') {
			stack[++stackIndex] = c;
		}
		// If the scanned character is an ‘)’, pop and add to the output string from the stack
		// until an ‘(‘ is encountered.
		else if (c == ')') {
			while (stackIndex >= 0 && stack[stackIndex] != '(') {
				result[resultIndex++] = stack[stackIndex--];
			}
			stackIndex--; // Pop '('
		}
		// If an operator is scanned
		else {
			while (stackIndex >= 0 && (prec(s[i]) < prec(stack[stackIndex]) ||
									prec(s[i]) == prec(stack[stackIndex]) &&
										associativity(s[i]) == 'L')) {
				result[resultIndex++] = stack[stackIndex--];
			}
			stack[++stackIndex] = c;
		}
	}

	// Pop all the remaining elements from the stack
	while (stackIndex >= 0) {
		result[resultIndex++] = stack[stackIndex--];
	}

	result[resultIndex] = '\0';
	printf("%s\n", result);
}

// Driver code
int main() {
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";

	// Function call
	infixToPostfix(exp);

	return 0;
}
