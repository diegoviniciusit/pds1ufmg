#include <stdio.h>
#include <stdlib.h>

char calcGrade(int grade)
{
    switch (grade) {
        case 0:
            return 'F';
        case 1:
            return 'F';
        case 2:
            return 'F';
        case 3:
            return 'F';
        case 4:
            return 'F';
        case 5:
            return 'E';
        case 6:
            return 'D';
        case 7:
            return 'C';
        case 8:
            return 'B';
        default:
            return 'A';
    }
}

void main()
{
    int grade;
    scanf("%d", &grade);
    printf("%c\n", calcGrade(grade));
}