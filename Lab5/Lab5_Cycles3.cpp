#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Даны два целых числа А и В. Найти произведение всех целых чисел\n"
            "от А до В включительно."
         << endl;

    int a, b;

    cout << "Введите а:";
    cin >> a;
    cout << endl;

    cout << "Введите b";
    cin >> b;
    cout << endl;

    while (b <= a)
    {
        cout << "b должно быть больше а! Введите еще раз: ";
        cin >> b;
        cout << endl;
    }

    int p = 1, i; // Изначально произведение равно 1, а не 0, а то потом 0 будет умножаться

    for (i = a; i <= b; i++)
        p *= i;

    cout << "Произведение чисел от " << a << " до " << b << " = " << p << endl;

    system("pause");
    return 0;
}