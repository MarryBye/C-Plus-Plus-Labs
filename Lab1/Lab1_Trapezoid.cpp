#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Программа нужна для вычисления площади трапеции." << endl;
    cout << "Для рассчетов нужна высота и оба основания фигуры.\n"
         << endl;

    float height = 0;
    float base_first = 0;
    float base_second = 0;

    cout << "Введите высоту: ";
    cin >> height;
    cout << endl;

    cout << "Введите первое основание: ";
    cin >> base_first;
    cout << endl;

    cout << "Введите второе основание: ";
    cin >> base_second;
    cout << endl;

    float area = (height * (base_first + base_second)) / 2;

    cout << "Площадь трапеции: " << area << endl;

    system("pause");
    return 0;
}