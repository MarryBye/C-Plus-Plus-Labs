#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Программа нужна для рассчета результата уравнения." << endl;
    cout << "Для рассчета вам необходимо ввести числа x и y." << endl;

    cout << "10: z = (2cos(x - pi / 6) / 0.5 + sin^2y)* (1 + x^2 / 3 - y^2 / 5))\n"
         << endl;

    float x = 0;
    float y = 0;

    cout << "Введите X:";
    cin >> x;
    cout << endl;

    cout << "Введите Y:";
    cin >> y;
    cout << endl;

    float result_1 = 2 * cos(x - M_PI / 6);
    float result_2 = 0.5 + pow(sin(y), 2);
    float result_3 = pow(x, 2);
    float result_4 = 3 - pow(y, 2) / 5;

    float result = result_1 / result_2 * (1 + result_3 / result_4);

    cout << "Ответ: " << result << endl;

    system("pause");
    return 0;
}