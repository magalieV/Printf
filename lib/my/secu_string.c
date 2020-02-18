/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** SECU_STRING
*/

#include "printf_hd.h"

void test_secu(int *bol, int *bol_2, char str, char temp)
{
    if (str == '%')
        *bol = 1;
    else if (*bol == 0 && str == temp)
        *bol_2 = 1;
}
