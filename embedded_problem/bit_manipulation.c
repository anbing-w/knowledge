#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BIT3 (0x1 << 3)

static int a;

void set_bit(void)
{
    a |= BIT3;
}

void clear_bit(void)
{
    a &= ~BIT3;  
}


