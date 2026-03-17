char findTheDifference(char* s, char* t) {
    char result = 0;
    
    // XOR all characters in string s
    for (int i = 0; s[i] != '\0'; i++) {
        result ^= s[i];
    }
    
    // XOR all characters in string t
    for (int i = 0; t[i] != '\0'; i++) {
        result ^= t[i];
    }
    
    // The remaining value is the extra character
    return result;
}
