#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NEGATION(x) (x ^ (0xffffffff))

#define example(instr) printf("the input string is:%s\n", #instr)

#define example1(instr) #instr


int findSameNumbes(int *num, int len)
{
    if (num == NULL)
    {
        return 0;
    }
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
    int num2[10];
    int len = sizeof(num)/sizeof(int);

    int same = findSameNumbes(num, len);

    example(abc);



    printf("%d\n", same);
    printf("%d\n", num[-1]);

    return 0;
}


