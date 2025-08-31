
#include <stdio.h>

void ft_putchar(char c)
{
    printf("%c", c);
}
void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ft_putstr(char *str)
{
    for (int i = 0; str[i]; i++)
        ft_putchar(str[i]);
}
int ft_strlen(char *str)
{
    int i = 0;
    for (; str[i]; i++)
        i++;
    return(i - 1);
}
int ft_strcmp(char *s1, char *s2);