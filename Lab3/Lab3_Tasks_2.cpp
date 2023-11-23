#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Написать программу, которая будет\n"
            "возводить число x в степень y, вводимые с\n"
            "клавиатуры,\n"
            "без использования стандартной функции pow()."
         << endl;

    int x, y, i;
    int ans = 1;

    cout << "Введите x: ";
    cin >> x;
    cout << endl;

    cout << "Введите y: ";
    cin >> y;
    cout << endl;

    if (x == 0 && y == 0)
    {
        cout << "Операция бессмысленна!" << endl;
    }
    else
    {
        for (i = 0; i < y; i++)
        {
            ans *= x;
        }

        cout << x << "^" << y << " = " << ans << endl;
    }

    system("pause");
    return 0;
}