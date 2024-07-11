#include<stdio.h>

void g(char *s) {
    char *t;
    t = (char *)malloc(sizeof(s) + 1);
    strcpy(t, s);
    printf("%s\n", t);
}

int main() {
    char *v;
    int n = 3;
    //v = (char*) malloc((n+1)*sizeof(char));
    v = malloc(sizeof(char));
    *v = 'a';
    printf("%d\n", strlen(v));
    //g(v);
    return 1;
}
