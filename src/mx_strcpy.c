char* mx_strcpy(char* dst, const char* src) {
    if (dst == 0)
        return 0;

    char* temp = dst;

    while (*src != '\0') {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';
    return temp;
}

