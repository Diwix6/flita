#include <stdio.h>

int main(){
    int bin_set[100], dec_set[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &bin_set[i]);
        int tmp = bin_set[i], j = 1; dec_set[i] = 0;
        while (tmp){dec_set[i] += (tmp % 10) * j;tmp /= 10; j*=2;}
        printf("%d  %d\n", dec_set[i], bin_set[i]);
    }}
