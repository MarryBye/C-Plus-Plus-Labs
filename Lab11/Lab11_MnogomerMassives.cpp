#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    int massive2x2[5][5] = {0};
    int massive3x3[5][5][5] = {0};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            massive2x2[i][j] = rand() % 15;
            for (int k = 0; k < 5; k++)
            {
                massive3x3[i][j][k] = rand() % 15;
            }
        }
    }

    cout << "\n  __________МАССИВ 2х2__________  " << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << massive2x2[i][j] << "\t";
        }
        cout << "\n"
             << endl;
    }

    cout << "Меняю местами 2 и 4 строки...\n"
         << endl;

    int el_buf = massive2x2[0][0];

    for (int i = 0; i < 5; i++)
    {
        el_buf = massive2x2[2][i];
        massive2x2[2][i] = massive2x2[4][i];
        massive2x2[4][i] = el_buf;
    }

    cout << "  __________МАССИВ 2х2__________  " << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << massive2x2[i][j] << "\t";
        }
        cout << "\n"
             << endl;
    }

    int max_element = massive2x2[0][0];
    int min_elenemt = massive2x2[0][0];

    int el_sum = 0;
    long long int el_mult = 1;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int el = massive2x2[i][j];
            el_sum += el;
            el_mult *= el;
            if (el > max_element)
            {
                max_element = el;
            }
            if (el < min_elenemt)
            {
                min_elenemt = el;
            }
        }
        int max_column_element = massive2x2[0][i];
        cout << "Максимальный элемент в столбце " << i << ": ";
        for (int k = 0; k < 5; k++)
        {
            int el = massive2x2[k][i];
            if (el > max_column_element)
            {
                max_column_element = el;
            }
        }
        cout << max_column_element << endl;
    }

    cout << "\nМаксимальный элемент в массиве 2х2:\t" << max_element << "\t|\tМинимальный:\t" << min_elenemt << endl;
    cout << "Сумма элементов в массиве 2х2:\t\t" << el_sum << "\t|\tПроизведение:\t" << el_mult << endl;

    max_element = massive3x3[0][0][0];
    min_elenemt = massive3x3[0][0][0];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                int el = massive3x3[i][j][k];
                if (el > max_element)
                {
                    max_element = el;
                }
                if (el < min_elenemt)
                {
                    min_elenemt = el;
                }
            }
        }
    }

    cout << "\nМаксимальный элемент в массиве 3х3:\t" << max_element << "\t|\tМинимальный:\t" << min_elenemt << endl;

    system("pause");
    return 0;
}