#include <stdio.h>
#include <stdlib.h>

int ft_ultimate_range(int** range, int min, int max)
{
    if (min >= max)
    {
        *range = NULL;
        return(0);
    }
    *range = (int*)malloc(sizeof(int) * (max - min));
    for (int i = 0; min < max; i++)
    {
        (*range)[i] = min;
        min++;
    }
    return(max - min);
}

void print_arr(int size, int* arr)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
    int* arr;
    ft_ultimate_range(&arr, 12, 16);
    print_arr(4, arr);

}