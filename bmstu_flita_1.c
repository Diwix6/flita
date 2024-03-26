#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void push(struct Stack *stack, int item) {
    // Function to push an element into the stack
    if(stack->top == MAX_SIZE-1)
        printf("stack overflow\n");
    else {
        stack->top++;
        stack->items[stack->top] = item; // Add element to the top of the stack
    }
}


int bin_to_dec(int x){
    // Function to convert a binary number to decimal
    int result = 0, i = 1;
    while(x){
        result += (x % 10) * i; // Calculate the decimal value of each binary digit
        if (x % 10 != 1 && x % 10 != 0){
            printf("\n__ERROR__\n WRONG INPUT\n"); // If a digit is not 0 or 1, display error message and exit
            exit(0);
        }
        i *= 2;
        x /= 10;
    }
    return result;
}

short check(int x, struct Stack *stack){
    for (int i = 0; i <= stack->top; i++) 
        if (stack->items[i] == x)
            return 0;
    return 1;
}

void input(int n, struct Stack *stack){
    // Function to input a sequence of numbers into the stack
    printf("binary stack input : ");
    int tmp;
    for (int i = 0; i < n; i++){
        scanf("%d", &tmp);
        if (check(tmp, stack))
            push(stack, tmp); // Add each number to the stack
    }
}

void steck_conversion(struct Stack *bin_stack, struct Stack *dec_stack){
    // Function to convert a stack from binary to decimal format
    for (int i = bin_stack->top; i >= 0; i--)
        push(dec_stack, bin_to_dec(bin_stack->items[i]));
}

void output(struct Stack *stack) {
    // Function to output the content of the stack
    for (int i = 0; i <= stack->top; i++) printf("%d ", stack->items[i]);
}


int main(){
    int n;
    struct Stack bin_stack, dec_stack;
    bin_stack.top = -1;
    dec_stack.top = -1;
    printf("__INPUT__\nsize input: ");
    scanf("%d", &n); // Input the size of the sequence
    input(n, &bin_stack); // Input the sequence into bin_stack
    steck_conversion(&bin_stack, &dec_stack); // Convert bin_stack to decimal format and store in dec_stack
    printf("\n__OUTPUT__\nbinary stack: ");
    output(&bin_stack);
    printf("\ndecimal stack: ");
    output(&dec_stack);
    return 0;
}