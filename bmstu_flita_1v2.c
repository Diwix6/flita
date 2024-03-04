#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Function for inputting elements into an array
void input(int *vec, int n){
    printf("binary stack input : ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &vec[i]);
}

// Function for outputting array elements
void output(int *vec, int n){
    for(int i = 0; i < n; i++)
        printf("%d ", vec[i]);
}

// Function to convert a number from binary to decimal
int bin_to_dec(int x){
    int result = 0, i = 1;
    while(x){
        result += (x % 10) * i; 
        if (x % 10 != 1 && x % 10 != 0){
            printf("__ERROR__\nInput is not binary\n"); 
            exit(0);
        }
        i *= 2;
        x /= 10;
    }
    return result;
}

// Function to convert an array from binary to decimal system
void array_conversion(int *bin, int *dec, int n){
    for(int i = 0; i < n; i++)
        dec[i] = bin_to_dec(bin[i]);
}

int main(){
    int n;
    printf("__INPUT__\nsize input: ");
    scanf("%d", &n); 
    // Memory allocation for arrays
    int * bin_array = (int*)malloc(n * sizeof(int));
    int * dec_array = (int*)malloc(n * sizeof(int));
    // Input values into the array
    input(bin_array, n);
    // Conversion of the array from binary to decimal system
    array_conversion(bin_array, dec_array, n); 
    printf("\n__OUTPUT__\nbinary array: ");
    // Output values of the binary array
    output(bin_array, n);
    printf("\ndecimal array: ");
    // Output values of the decimal array
    output(dec_array, n);
    // Freeing the memory allocated for the arrays
    free(bin_array);
    free(dec_array);
    return 0;
}
