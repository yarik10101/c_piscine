
#include <stdio.h>
#include <stdlib.h>

int is_separator(char c, char *charset)
{
    for (int i = 0; charset[i]; i++)
        if (charset[i] == c)
            return (1);
    return(0);
}

int word_counter(char *str, char *charset)
{
    int counter = 1;
    if (is_separator(str[0], charset))   
        counter = 0;
    for (int i = 0; str[i]; i++)
        if (is_separator(str[i], charset) && !is_separator(str[i + 1], charset) && str[i + 1] != '\0')
            counter++;
    return (counter);
}

int length_count(char *str, char *charset)
{
    int i = 0;
    for (; !is_separator(str[i], charset); i++) {}
    return (i);
}

char **ft_split(char *str, char *charset)
{
    int i = 0;
    int k = 0;
    int word_number = word_counter(str, charset);
    char **word_arr = malloc(sizeof(char *) * word_number);
    char *word;
    for (; str[i]; i++)
        if (is_separator(str[i], charset) && !is_separator(str[i + 1], charset) && str[i + 1] != '\0')
        {
            word = malloc(sizeof(char) * length_count(str + i, charset));
            for (int j = i + 1, w = 0; !is_separator(str[j], charset) && str[j]; j++, w++)
                word[w] = str[j];
            word_arr[k] = word;
            k++;
        }
    return (word_arr);
}

void print_arr_arr(char **arr, int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; arr[i][j]; j++)
            printf("%c ", arr[i][j]);
        printf("\n");
    }

}

int main(void)
{
    // printf("%d\n", word_counter("ppppppppppppppppp11tp1pp111p111111tp", "pt"));
    char *arr[3] = {"pososi", "moi", "huec"};
    print_arr_arr(ft_split("1p234pt56pp", "pt"), 2);
    // printf("%d ", length_count("ososakap", "p"));
    // print_arr_arr(arr, 3);
}