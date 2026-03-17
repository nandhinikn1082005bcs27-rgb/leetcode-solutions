char* toLowerCase(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        // Check if character is within uppercase range 'A' to 'Z'
        if (s[i] >= 'A' && s[i] <= 'Z') {
            // Add 32 to get the lowercase counterpart
            s[i] = s[i] + 32; 
        }
    }
    return s;
}
