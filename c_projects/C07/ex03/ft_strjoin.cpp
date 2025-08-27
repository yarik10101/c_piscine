
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

char *ft_strjoin(int size, char **strs, char *sep)
{
    int length = -1;

    for (int i = 0; i < size; i++)
    {
        length++;
        for (int j = 0; strs[i][j]; j++)
            length++;
    }
    int pos = 0;
    char *word = (char *)malloc(sizeof(char) * length);
    for (int i = 0; i < size; i++)
    {
        if (i != 0)
        {
            for (int j = 0; sep[j]; j++)
            {
                word[pos] = sep[j];
                pos++;
            }
        }
        for (int j = 0; strs[i][j]; j++)
        {
            word[pos] = strs[i][j];
            pos++;
        }
    }
    return (word);
}
// void fillMatrix(char** A, int a, int b) {
//     string line;
//     for (int i = 0; i < a; i++) {
//         cout << "Введите " << i + 1 << "-ю строку\n";
//         getline(cin, line);
//         istringstream iss(line);
//         for (int x = 0; x < b; x++) {
//             iss >> A[i][x];
//         }
//     }
// }

// void manualCharFill(char* A, int n) {
//     cout << "Введите строку длиной " << n << "\n";
//     cin.getline(A, n + 1);
// }

void print_arr(int size, char* arr)
{
    for (int i = 0; i < size; i++)
        printf("%c ", arr[i]);
}

int main()
{
    char *arr[] = {(char *)"pososi", (char *)"moi", (char *)"huec", (char *)"nahui"};
    char str[] = {"huec"};
    // char stroka1[5];
    // char stroka2[6];
    // char stroka3[3];
    // char stroka4[8];

    // manualCharFill(stroka1, 5);
    // manualCharFill(stroka2, 6);
    // manualCharFill(stroka3, 3);
    // manualCharFill(stroka4, 8);

    // arr[0] = stroka1;
    // arr[1] = stroka2;
    // arr[2] = stroka3;
    // arr[3] = stroka4;


    print_arr(30, ft_strjoin(4, arr, (char *)"sosi"));
    // print_arr(4, str);

    

}