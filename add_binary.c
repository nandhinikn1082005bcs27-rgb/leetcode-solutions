#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = (len_a > len_b ? len_a : len_b);
    
    // Allocate max_len + 2 for potential carry and null terminator
    char* result = (char*)malloc((max_len + 2) * sizeof(char));
    result[max_len + 1] = '\0';
    
    int i = len_a - 1;
    int j = len_b - 1;
    int k = max_len; // Pointer for result string
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        result[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }
    
    // If the carry didn't extend the length, shift the string forward
    if (k == 0) {
        return result + 1;
    }
    
    return result + k + 1;
}
