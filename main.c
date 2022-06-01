#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    void    *ptr;

    long lng = __LONG_MAX__;

    ptr = &lng;
    printf("NP : %p\n", ptr);
    ft_printf(" HP : %p\n", ptr);
}