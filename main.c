#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    void    *ptr = 0;

    printf("NP : %p %p\n", ptr, ptr);
    printf("NP : %p %p\n", ptr, ptr);
    ft_printf("HP : %p %p\n", ptr, ptr);
}