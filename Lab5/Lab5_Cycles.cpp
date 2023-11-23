#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Ввести с клавиатуры 2 целых числа a и b, a&lt;b. Суммировать все\n"
            "нечётные целые числа в диапазоне (a,b). Вывести сумму на экран."
         << endl;

    int a, b;

    cout << "Введите а: ";
    cin >> a;
    cout << endl;

    cout << "Введите b: ";
    cin >> b;
    cout << endl;

    while (b <= a)
    {
        cout << "b должно быть больше а! Введите еще раз: ";
        cin >> b;
        cout << endl;
    }

    int sum;
    int i;

    for (i = a; i <= b; i++)
    {
        if (i % 2 == 0)
            continue;
        sum += i;
    }

    cout << "Сумма нечетных чисел: " << sum << endl;

    system("pause");
    return 0;
}