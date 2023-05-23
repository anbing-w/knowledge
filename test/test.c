#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NEGATION(x) (x ^ (0xffffffff))


int findSameNumbes(int *num, int len)
{
    for (size_t i = 0; i < len - 1; i++)
    { 
        for (int j = i + 1; j < len; j++)
        {
            if (num[i] == num[j])
            {
                return num[j];
            }
        }
    }
    return 0;
}


int main()
{
    int num[] = {0,1,2,2,4,5,6};
    int len = sizeof(num)/sizeof(int);

    int same = findSameNumbes(num, len);

    printf("%d\n", same);

    return 0;
}
