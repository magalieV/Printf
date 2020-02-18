/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** UNIT_Test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <ctype.h>

int my_printf(char const *, ...);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(redirect, test_borne_1, .init = redirect_all_std)
{
    my_printf("%d\n", 2147483647);
    cr_assert_stdout_eq_str("2147483647\n");
}

Test(redirect, test_borne_2, .init = redirect_all_std)
{
    my_printf("%d\n", -2147483648);
    cr_assert_stdout_eq_str("-2147483648\n");
}

Test(redirect, test_borne_3, .init = redirect_all_std)
{
    my_printf("%u\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test(redirect, test_borne_4, .init = redirect_all_std)
{
    my_printf("%u\n", 4294967295);
    cr_assert_stdout_eq_str("4294967295\n");
}

Test(redirect, test_borne_5, .init = redirect_all_std)
{
    my_printf("%o\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test(redirect, test_borne_6, .init = redirect_all_std)
{
    my_printf("%o\n", 4294967295);
    cr_assert_stdout_eq_str("37777777777\n");
}

Test(redirect, test_borne_7, .init = redirect_all_std)
{
    my_printf("%x\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test(redirect, test_borne_8, .init = redirect_all_std)
{
    my_printf("%x\n", 4294967295);
    cr_assert_stdout_eq_str("ffffffff\n");
}

Test(redirect, test_borne_9, .init = redirect_all_std)
{
    my_printf("%X\n", 0);
    cr_assert_stdout_eq_str("0\n");
}

Test(redirect, test_borne_10, .init = redirect_all_std)
{
    my_printf("%X\n", 4294967295);
    cr_assert_stdout_eq_str("FFFFFFFF\n");
}

Test(redirect, test_number_1, .init = redirect_all_std)
{
    my_printf("%d\n", 12);
    cr_assert_stdout_eq_str("12\n");
}

Test(redirect, test_number_2, .init = redirect_all_std)
{
    my_printf("%d\n", 1234567);
    cr_assert_stdout_eq_str("1234567\n");
}

Test(redirect, test_number_4, .init = redirect_all_std)
{
    my_printf("%i\n", 18);
    cr_assert_stdout_eq_str("18\n");
}

Test(redirect, test_number_5, .init = redirect_all_std)
{
    my_printf("%i\n", 1234569);
    cr_assert_stdout_eq_str("1234569\n");
}

Test(redirect, test_number_6, .init = redirect_all_std)
{
    my_printf("%i", 183);
    cr_assert_stdout_eq_str("183");
}

Test(redirect, test_number_7, .init = redirect_all_std)
{
    int d = -12;

    my_printf("%d\n", d);
    cr_assert_stdout_eq_str("-12\n");
}

Test(redirect, test_number_8, .init = redirect_all_std)
{
    int d = -12385;

    my_printf("%d\n", d);
    cr_assert_stdout_eq_str("-12385\n");
}

Test(redirect, test_number_9, .init = redirect_all_std)
{
    my_printf("%i", -12345);
    cr_assert_stdout_eq_str("-12345");
}

Test(redirect, test_number_10, .init = redirect_all_std)
{
    my_printf("%d", -12385);
    cr_assert_stdout_eq_str("-12385");
}

Test(redirect, test_number_11, .init = redirect_all_std)
{
    my_printf("%i\n", 1832);
    cr_assert_stdout_eq_str("1832\n");
}

Test(redirect, test_number_12, .init = redirect_all_std)
{
    my_printf("% d", 45);
    cr_assert_stdout_eq_str(" 45");
}

Test(redirect, test_number_13, .init = redirect_all_std)
{
    my_printf("% i\n", 87);
    cr_assert_stdout_eq_str(" 87\n");
}

Test(redirect, test_number_14, .init = redirect_all_std)
{
    my_printf("%5d", 45);
    cr_assert_stdout_eq_str("   45");
}

Test(redirect, test_number_15, .init = redirect_all_std)
{
    my_printf("%1i\n", 87);
    cr_assert_stdout_eq_str("87\n");
}

Test(redirect, test_number_16, .init = redirect_all_std)
{
    my_printf("%-5d", 45);
    cr_assert_stdout_eq_str("45   ");
}

Test(redirect, test_number_17, .init = redirect_all_std)
{
    my_printf("%-2i\n", 87);
    cr_assert_stdout_eq_str("87\n");
}

Test(redirect, test_number_18, .init = redirect_all_std)
{
    my_printf("%0d", 45);
    cr_assert_stdout_eq_str("45");
}

Test(redirect, test_number_19, .init = redirect_all_std)
{
    my_printf("%0i\n", 87);
    cr_assert_stdout_eq_str("87\n");
}

Test(redirect, test_number_20, .init = redirect_all_std)
{
    my_printf("%-6d\n", 87);
    cr_assert_stdout_eq_str("87    \n");
}

Test(redirect, test_number_21, .init = redirect_all_std)
{
    my_printf("%+d\n", 87);
    cr_assert_stdout_eq_str("+87\n");
}

Test(redirect, test_number_22, .init = redirect_all_std)
{
    my_printf("%+d\n", -89);
    cr_assert_stdout_eq_str("-89\n");
}

Test(redirect, test_number_23, .init = redirect_all_std)
{
    my_printf("%--d\n", 30);
    cr_assert_stdout_eq_str("30\n");
}

Test(redirect, test_number_24, .init = redirect_all_std)
{
    my_printf("%.d\n", 40);
    cr_assert_stdout_eq_str("40\n");
}

Test(redirect, test_number_25, .init = redirect_all_std)
{
    my_printf("%.d\n", -40);
    cr_assert_stdout_eq_str("-40\n");
}

Test(redirect, test_number_26, .init = redirect_all_std)
{
    my_printf("%.6d\n", 352);
    cr_assert_stdout_eq_str("000352\n");
}

Test(redirect, test_number_27, .init = redirect_all_std)
{
    my_printf("%#d\n", -40);
    cr_assert_stdout_eq_str("-40\n");
}

Test(redirect, test_number_28, .init = redirect_all_std)
{
    my_printf("%#i\n", 352);
    cr_assert_stdout_eq_str("352\n");
}

Test(redirect, test_number_29, .init = redirect_all_std)
{
    my_printf("%d\n", -2147483648);
    cr_assert_stdout_eq_str("-2147483648\n");
}

Test(redirect, test_char_1, .init = redirect_all_std)
{
    my_printf("%c\n", 'a');
    cr_assert_stdout_eq_str("a\n");
}

Test(redirect, test_char_2, .init = redirect_all_std)
{
    my_printf("%c et %c\n", 'a', 'z');
    cr_assert_stdout_eq_str("a et z\n");
}

Test(redirect, test_char_3, .init = redirect_all_std)
{
    my_printf("%    c et %     c\n", 'a', 'z');
    cr_assert_stdout_eq_str("a et z\n");
}

Test(redirect, test_char_4, .init = redirect_all_std)
{
    my_printf("%       c\n", 'c');
    cr_assert_stdout_eq_str("c\n");
}

Test(redirect, test_char_5, .init = redirect_all_std)
{
    my_printf("%5c et %3c\n", 'a', 'z');
    cr_assert_stdout_eq_str("    a et   z\n");
}

Test(redirect, test_char_6, .init = redirect_all_std)
{
    my_printf("%1c\n", 'c');
    cr_assert_stdout_eq_str("c\n");
}

Test(redirect, test_char_7, .init = redirect_all_std)
{
    my_printf("%0c\n", 'c');
    cr_assert_stdout_eq_str("c\n");
}

Test(redirect, test_char_8, .init = redirect_all_std)
{
    my_printf("%0c et %0c\n", 'a', 'z');
    cr_assert_stdout_eq_str("a et z\n");
}

Test(redirect, test_char_9, .init = redirect_all_std)
{
    my_printf("%05c et %03c\n", 'a', 'z');
    cr_assert_stdout_eq_str("    a et   z\n");
}

Test(redirect, test_char_10, .init = redirect_all_std)
{
    my_printf("%01c\n", 'c');
    cr_assert_stdout_eq_str("c\n");
}

Test(redirect, test_char_11, .init = redirect_all_std)
{
    my_printf("%.c\n", 'c');
    cr_assert_stdout_eq_str("c\n");
}

Test(redirect, test_char_12, .init = redirect_all_std)
{
    my_printf("%.c et %.c\n", 'a', 'z');
    cr_assert_stdout_eq_str("a et z\n");
}

Test(redirect, test_char_13, .init = redirect_all_std)
{
    my_printf("%.8c\n", 'c');
    cr_assert_stdout_eq_str("c\n");
}

Test(redirect, test_char_14, .init = redirect_all_std)
{
    my_printf("%.11c et %.3c\n", 'a', 'z');
    cr_assert_stdout_eq_str("a et z\n");
}

Test(redirect, test_octal_1, .init = redirect_all_std)
{
    my_printf("%o\n", 42);
    cr_assert_stdout_eq_str("52\n");
}

Test(redirect, test_octal_2, .init = redirect_all_std)
{
    my_printf("%o\n", -42);
    cr_assert_stdout_eq_str("37777777726\n");
}

Test(redirect, test_octal_3, .init = redirect_all_std)
{
    my_printf("%        o\n", 42);
    cr_assert_stdout_eq_str("52\n");
}

Test(redirect, test_octal_4, .init = redirect_all_std)
{
    my_printf("%       o\n", -42);
    cr_assert_stdout_eq_str("37777777726\n");
}

Test(redirect, test_octal_5, .init = redirect_all_std)
{
    my_printf("%3o\n", 42);
    cr_assert_stdout_eq_str(" 52\n");
}

Test(redirect, test_octal_6, .init = redirect_all_std)
{
    my_printf("%0o\n", 42);
    cr_assert_stdout_eq_str("52\n");
}

Test(redirect, test_octal_7, .init = redirect_all_std)
{
    my_printf("%0o\n", -42);
    cr_assert_stdout_eq_str("37777777726\n");
}

Test(redirect, test_octal_8, .init = redirect_all_std)
{
    my_printf("%+o\n", 42);
    cr_assert_stdout_eq_str("52\n");
}

Test(redirect, test_octal_9, .init = redirect_all_std)
{
    my_printf("%+o octal 2 %+ostop\n", 42, 6, -42, 6);
    cr_assert_stdout_eq_str("52 octal 2 6stop\n");
}

Test(redirect, test_octal_10, .init = redirect_all_std)
{
    my_printf("%.o\n", 42);
    cr_assert_stdout_eq_str("52\n");
}

Test(redirect, test_octal_11, .init = redirect_all_std)
{
    my_printf("%#o\n", 42);
    cr_assert_stdout_eq_str("052\n");
}

Test(redirect, test_hexa_1, .init = redirect_all_std)
{
    my_printf("%x\n", 16);
    cr_assert_stdout_eq_str("10\n");
}

Test(redirect, test_hexa_2, .init = redirect_all_std)
{
    my_printf("%x\n", -42);
    cr_assert_stdout_eq_str("ffffffd6\n");
}

Test(redirect, test_hexa_3, .init = redirect_all_std)
{
    my_printf("%   x\n", 16);
    cr_assert_stdout_eq_str("10\n");
}

Test(redirect, test_hexa_4, .init = redirect_all_std)
{
    my_printf("%   x\n", -42);
    cr_assert_stdout_eq_str("ffffffd6\n");
}

Test(redirect, test_hexa_5, .init = redirect_all_std)
{
    my_printf("%0x\n", 16);
    cr_assert_stdout_eq_str("10\n");
}

Test(redirect, test_hexa_6, .init = redirect_all_std)
{
    my_printf("%0x\n", -42);
    cr_assert_stdout_eq_str("ffffffd6\n");
}

Test(redirect, test_hexa_7, .init = redirect_all_std)
{
    my_printf("%+x hexa 2 %+x\n", 42, 6, -42, 6);
    cr_assert_stdout_eq_str("2a hexa 2 6\n");
}

Test(redirect, test_hexa_8, .init = redirect_all_std)
{
    my_printf("%.x\n", 16);
    cr_assert_stdout_eq_str("10\n");
}

Test(redirect, test_hexa_9, .init = redirect_all_std)
{
    my_printf("%X\n", 42);
    cr_assert_stdout_eq_str("2A\n");
}

Test(redirect, test_hexa_10, .init = redirect_all_std)
{
    my_printf("%X\n", -42);
    cr_assert_stdout_eq_str("FFFFFFD6\n");
}

Test(redirect, test_hexa_11, .init = redirect_all_std)
{
    my_printf("%        X\n", 42);
    cr_assert_stdout_eq_str("2A\n");
}

Test(redirect, test_hexa_12, .init = redirect_all_std)
{
    my_printf("%        X\n", -42);
    cr_assert_stdout_eq_str("FFFFFFD6\n");
}

Test(redirect, test_hexa_13, .init = redirect_all_std)
{
    my_printf("%0X\n", 42);
    cr_assert_stdout_eq_str("2A\n");
}

Test(redirect, test_hexa_14, .init = redirect_all_std)
{
    my_printf("%0X\n", -42);
    cr_assert_stdout_eq_str("FFFFFFD6\n");
}

Test(redirect, test_hexa_15, .init = redirect_all_std)
{
    my_printf("%+X\n", 42);
    cr_assert_stdout_eq_str("2A\n");
}

Test(redirect, test_hexa_16, .init = redirect_all_std)
{
    my_printf("%+X\n", -42);
    cr_assert_stdout_eq_str("FFFFFFD6\n");
}

Test(redirect, test_hexa_17, .init = redirect_all_std)
{
    my_printf("%.X\n", 42);
    cr_assert_stdout_eq_str("2A\n");
}

Test(redirect, test_hexa_18, .init = redirect_all_std)
{
    my_printf("%.X\n", -42);
    cr_assert_stdout_eq_str("FFFFFFD6\n");
}

Test(redirect, test_hexa_19, .init = redirect_all_std)
{
    my_printf("%#X\n", 42);
    cr_assert_stdout_eq_str("0X2A\n");
}

Test(redirect, test_hexa_20, .init = redirect_all_std)
{
    my_printf("%#x\n", -42);
    cr_assert_stdout_eq_str("0xffffffd6\n");
}

Test(redirect, test_adress_1, .init = redirect_all_std)
{
    my_printf("%p\n", 123456789);
    cr_assert_stdout_eq_str("0x75bcd15\n");
}

Test(redirect, test_adress_2, .init = redirect_all_std)
{
    my_printf("%      p\n", 123456789);
    cr_assert_stdout_eq_str(" 0x75bcd15\n");
}

Test(redirect, test_adress_3, .init = redirect_all_std)
{
    my_printf("%12p\n", 123456789);
    cr_assert_stdout_eq_str("0x75bcd15\n");
}

Test(redirect, test_adress_4, .init = redirect_all_std)
{
    my_printf("%-p\n", 123456789);
    cr_assert_stdout_eq_str("0x75bcd15\n");
}

Test(redirect, test_adress_5, .init = redirect_all_std)
{
    my_printf("%0p\n", 123456789);
    cr_assert_stdout_eq_str("0x75bcd15\n");
}

Test(redirect, test_adress_6, .init = redirect_all_std)
{
    my_printf("%07p\n", 123456789);
    cr_assert_stdout_eq_str("0x75bcd15\n");
}

Test(redirect, test_adress_7, .init = redirect_all_std)
{
    my_printf("%-012p\n", 123456789);
    cr_assert_stdout_eq_str("0x75bcd15\n");
}

Test(redirect, test_adress_8, .init = redirect_all_std)
{
    my_printf("%.p\n", 123456789);
    cr_assert_stdout_eq_str("0x75bcd15\n");
}

Test(redirect, test_adress_9, .init = redirect_all_std)
{
    my_printf("%.12p\n", 123456789);
    cr_assert_stdout_eq_str("0x75bcd15\n");
}

Test(redirect, test_u_1, .init = redirect_all_std)
{
    my_printf("%u\n", 10);
    cr_assert_stdout_eq_str("10\n");
}

Test(redirect, test_u_2, .init = redirect_all_std)
{
    my_printf("%u\n", -42);
    cr_assert_stdout_eq_str("4294967254\n");
}

Test(redirect, test_u_3, .init = redirect_all_std)
{
    my_printf("%        u\n", 10);
    cr_assert_stdout_eq_str("10\n");
}

Test(redirect, test_u_4, .init = redirect_all_std)
{
    my_printf("%      u\n", -42);
    cr_assert_stdout_eq_str("4294967254\n");
}

Test(redirect, test_u_5, .init = redirect_all_std)
{
    my_printf("%0u\n", 10);
    cr_assert_stdout_eq_str("10\n");
}

Test(redirect, test_u_6, .init = redirect_all_std)
{
    my_printf("%0u\n", -42);
    cr_assert_stdout_eq_str("4294967254\n");
}

Test(redirect, test_u_7, .init = redirect_all_std)
{
    my_printf("%+u\n", 10);
    cr_assert_stdout_eq_str("10\n");
}

Test(redirect, test_u_8, .init = redirect_all_std)
{
    my_printf("%+u\n", -42);
    cr_assert_stdout_eq_str("4294967254\n");
}

Test(redirect, test_u_9, .init = redirect_all_std)
{
    my_printf("%.u\n", 10);
    cr_assert_stdout_eq_str("10\n");
}

Test(redirect, test_u_10, .init = redirect_all_std)
{
    my_printf("%.u\n", -42);
    cr_assert_stdout_eq_str("4294967254\n");
}

Test(redirect, test_s_nulle, .init = redirect_all_std)
{
    my_printf("%s", 0);
    cr_assert_stdout_eq_str("(null)");
}

Test(redirect, test_pourcen, .init = redirect_all_std)
{
    my_printf("%%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(redirect, test_without_flag, .init = redirect_all_std)
{
    my_printf("Salut");
    cr_assert_stdout_eq_str("Salut");
}

Test(redirect, test_without_flag_2, .init = redirect_all_std)
{
    my_printf("Salut\n");
    cr_assert_stdout_eq_str("Salut\n");
}

Test(redirect, test_without_flag_3, .init = redirect_all_std)
{
    my_printf("Salut ca va ?\n", 34, 67);
    cr_assert_stdout_eq_str("Salut ca va ?\n");
}

Test(redirect, test_sentence_1, .init = redirect_all_std)
{
    my_printf("%s\n", "Salut");
    cr_assert_stdout_eq_str("Salut\n");
}

Test(redirect, test_sentence_2, .init = redirect_all_std)
{
    my_printf("%          s\n", "Salut");
    cr_assert_stdout_eq_str("Salut\n");
}

Test(redirect, test_sentence_3, .init = redirect_all_std)
{
    my_printf("%12s\n", "Salut");
    cr_assert_stdout_eq_str("       Salut\n");
}

Test(redirect, test_sentence_4, .init = redirect_all_std)
{
    my_printf("%0s\n", "Salut");
    cr_assert_stdout_eq_str("Salut\n");
}

Test(redirect, test_sentence_5, .init = redirect_all_std)
{
    my_printf("%012s\n", "Salut");
    cr_assert_stdout_eq_str("       Salut\n");
}

Test(redirect, test_sentence_6, .init = redirect_all_std)
{
    my_printf("astek%%%d%s\n", 42, "moulinette");
    cr_assert_stdout_eq_str("astek%42moulinette\n");
}

Test(redirect, test_sentence_octal, .init = redirect_all_std)
{
    my_printf("%S\n", "Salut\n");
    cr_assert_stdout_eq_str("Salut\\012\n");
}

Test(redirect, test_exit_1, .init = redirect_all_std)
{
    my_printf("%..#d\n", 12);
    cr_assert_stdout_eq_str("%.0.#d\n");
}

Test(redirect, test_exit_2, .init = redirect_all_std)
{
    my_printf("%:c\n", 'a');
    cr_assert_stdout_eq_str("\n");
}
