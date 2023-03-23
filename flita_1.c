#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int convert(char bit_str[]) {
    short int n = strlen(bit_str);          
    int sum = 0;

    for (int i = (n-1); i > -1; i--) {
        if (bit_str[i] == '1')
            sum += pow(2, n-(i+1));
    }    
    return sum;
}

bool isBinary(char str[]) {
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '\0')
            return false; 
    }
    return true;
}

int main() {
    int dim, bit_depth;
    bool isExist = false;
    
    puts("Put the dimention:");
    scanf("%d", &dim);

    puts("Put the bit depth:");
    scanf("%d", &bit_depth);
    
    char transit[(bit_depth + 2)];
    char str[dim][++bit_depth];
    int arr_o[dim];
    
    for (int i = 0; i < dim; i++) {
        puts("Put the value:");
        scanf("%s", &transit);

        if (strlen(transit) >= bit_depth || (strlen(transit) + 1) < bit_depth || !isBinary(transit)) {
            i--; 
            puts("So short or long or no binary, try again:"); 
            continue;
        }

        for (int j = 0; j <= i; j++) {
            if (strcmp(str[j], transit) == 0){
                i--;
                puts("Already exist, try again:");
                isExist = true;
                break;
            } else {
                isExist = false;
            }
        }

        if (isExist) continue;

        for (int j = 0; j <= strlen(transit); j++) {
            str[i][j] = transit[j];    
        }
    }
    
    for (int i = 0; i < dim; i++)
        arr_o[i] = convert(str[i]);
        
    puts("Input array: \t Output array:");

    for (int i = 0; i < dim; i++) {
        printf("%s\t\t\t", str[i]);
        printf("%d\n", arr_o[i]);
    }
    return 0;
}