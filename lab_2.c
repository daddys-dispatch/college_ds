#include <stdio.h>
#include <string.h>

void main() {
    char str[100], pat[100], rep[100], ans[100];
    int i = 0, j = 0, c = 0, m = 0, flag = 0;
    
    printf("Enter the main string: ");
    fgets(str, 100, stdin);
    printf("Enter the pattern string: ");
    fgets(pat, 100, stdin);
    printf("Enter the replacement string: ");
    fgets(rep, 100, stdin);
    
    while (str[c] != '\0') {
        if (str[m] == pat[i]) {
            if (++i == strlen(pat) - 1) {
                for (int k = 0; rep[k] != '\0'; j++, k++) 
                    ans[j] = rep[k];
                c = m; i = 0; flag = 1;
            } 
            else
                m++;
        } else {
            ans[j++] = str[c++];
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
    if (!flag) 
        printf("Pattern not found\n");
    else 
        printf("The resultant string is: %s\n", ans);
}
