
#include <stdio.h>

int is_symbol(char c)
{
    return (c == '-' || c == ' ' || c == '+');
}

int contains(char c, char* base)
{
    for (int i = 0; base[i]; i++)
        if (base[i] == c)
            return (1);
    return (0);
}

int elem_count(char c, char* base)
{
    for (int i = 0; base[i]; i++)
        if (base[i] == c)
            return (i);
    return (0);
}

int check_base(char *base)
{
    if (base[0] == '\0' || base[1] == '\0')
        return (0);
    for (int i = 0; base[i]; i++)
        for (int j = i + 1; base[j]; j++)
            if (base[i] == base[j] || base[i] == '+'|| base[i] == '-'|| base[i] == ' ')
                return (0);
    return (1);
}

char *from_dec(int dec, char *base, char **str)
{
    int size = 0;
    int i = 0;
    for (; base[size]; size++) {}
    for (; dec > 0; dec /= size, i++)
        *str[31 - i] = base[dec % size];
    return (*(str + 32 - i));
}

int to_dec(char *str, char *base)
{
    int i = 0;
    int size = 0;
    int result = 0;
    for (; contains(str[i], base); i++) {};
    for (; base[size]; size++) {}
    i--;
    int temp_size = 1;
    for (; !is_symbol(str[i]); i--, temp_size = temp_size * size)
        result = result + elem_count(str[i], base) * temp_size; 
    return (result);
}
// "ABCDEGH"

 char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int size = 0;
    int i = 0;
    int counter = 1;
    int result = 0;
    char *str;
    if (!(check_base(base_from) && check_base(base_to)))
        return (0);
    for (; is_symbol(nbr[i]); i++)
        if (nbr[i] == '-')
            counter *= -1;
    if (!contains(nbr[i], base_from))
        return (0);
    result = to_dec(nbr + i, base_from);
    str = from_dec(result, base_to, &str);

    // if (counter < 0)
    // {
    //     *(str - 1) = '-';
    //     str--;
    // }
    return (str);
}

int main(void)
{
    char *base = {(char *)"01"};
    printf("%d ", elem_count('3', base));
    printf("%d ", ft_atoi_base((char *)"1011010111001", base));
    printf("%s ", ft_convert_base("5", "0123456789", "01"));
}