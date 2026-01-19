#include <stdio.h>
#include <string.h>

int main() {
    // initialise str1 and str2. Assign pointers.
    char str1[100], str2[100];
    char *ptr1, *ptr2;
    int length1 = 0, length2 = 0;

    // enter string 1
    printf("Enter str1: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';
    // enter string 2
    printf("Enter str2: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // Finding length of str1
    ptr1 = str1;
    while (*ptr1 != '\0')
    {
        length1++;
        ptr1++;
    }
    printf("\nThe length of str1 is: %d\n", length1);
    // Finding length of str2
    ptr2 = str2;
    while (*ptr2 != '\0')
    {
        length2++;
        ptr2++;
    }
    printf("The length of str2 is: %d\n", length2);

    // concatenation using pointers
    ptr1 = str1;
    ptr2 = str2;
    while (*ptr1 != '\0')
    {
        ptr1++;
    }
    while (*ptr2 != '\0')
    {
        *ptr1 = *ptr2;
        ptr1++;
        ptr2++;
    }
    *ptr1 = '\0';
    printf("\nConcatenated string: %s\n", str1);
    
    return 0;
}