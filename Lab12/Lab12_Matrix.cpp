#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int number = 10;
    int rows = number * 0.5 + 5;
    int columns = number / 3 + 2;

    int A[rows][columns] = {0};
    int B[rows][columns] = {0};
    int C[rows][columns] = {0};

    int num_cin = 0;

    cout << "Номер " << number << " в журнале, ==> ко всем числам +" << number << endl;
    cout << "Размеры матриц: " << rows << "x" << columns << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Введите В[" << i << "][" << j << "]:";
            cin >> num_cin;
            cout << endl;

            B[i][j] = num_cin + number;

            cout << "Введите C[" << i << "][" << j << "]:";
            cin >> num_cin;
            cout << endl;

            C[i][j] = num_cin + number;
        }
    }

    cout << "\n Матрица В: " << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << "||\t";
        for (int j = 0; j < columns; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << "|| " << endl;
    }

    cout << "\n Матрица С: " << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << "||\t";
        for (int j = 0; j < columns; j++)
        {
            cout << C[i][j] << "\t";
        }
        cout << "|| " << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            A[i][j] = B[i][j] + C[i][j];
        }
    }

    cout << "\n Матрица А (В + С): " << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << "||\t";
        for (int j = 0; j < columns; j++)
        {
            cout << A[i][j] << "\t";
        }
        cout << "|| " << endl;
    }

    cout << "\nВывожу матрицу В следующим способом: 1 строка слева направо, 2 справа налево и.т.д" << endl;

    int direction = 1;

    for (int i = 0; i < rows; i++)
    {
        cout << "||\t";
        if (direction % 2 != 0)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << B[i][j] << "\t";
            }
        }
        else
        {
            for (int j = columns - 1; j >= 0; j--)
            {
                cout << B[i][j] << "\t";
            }
        }
        direction++;
        cout << "|| " << endl;
    }

    system("pause");
    return 0;
}