
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

int ft_atoi_base(char *str, char *base)
{
    if (!check_base(base))
        return (0);
    int size = 0;
    int i = 0;
    int counter = 1;
    int result = 0;
    for (; is_symbol(str[i]); i++)
        if (str[i] == '-')
            counter *= -1;
    if (!contains(str[i], base))
        return (0);
    for (int j = 0; contains(str[i], base); i++, j++) {};
    for (; base[size]; size++) {}
    i--;
    result = elem_count(str[i], base);
    i--;
    int temp_size = size;
    for (; !is_symbol(str[i]); i--, size = temp_size * size)
        result = result + elem_count(str[i], base) * size; 
    return (result * counter);
}
int main(void)
{
    char *base = {(char *)"01"};
    printf("%d ", elem_count('3', base));
    printf("%d ", ft_atoi_base((char *)"-----1101011011101", base));
}