#include <stdio.h>
#include <stdlib.h>
int main() {
    int* p = malloc(sizeof(int));  
    *p = 0; 
    printf("Default: %d\n", *p);
    printf("Enter new code: ");
    scanf("%d", p);  
    printf("Final: %d\n", *p);
    free(p);  
    p = NULL;  

    return 0;
}