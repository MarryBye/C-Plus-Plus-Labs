#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Спортсмен приступает к тренировкам по следующему графику: в первый день он должен пробежать\n"
            "10 км; каждый следующий день следует увеличивать дистанцию на 10% от нормы\n"
            "предыдущего дня. Как только норма достигнет или превысит 25 км, необходимо\n"
            "прекратить её увеличение и далее пробегать ежедневно ровно 25 км. Начиная с\n"
            "какого дня спортсмен будет пробегать 25 км?"
         << endl;

    float today_distance = 10;
    int day;

    for (day = 1; today_distance < 25; day++)
    {
        cout << "День: " << day << " Дистанция: " << today_distance << endl;
        today_distance += today_distance * 0.1;
    }

    cout << endl;

    cout << "Атлет прошел 25 километров, но не ровно на " << day << " день." << endl;
    cout << "Ровно 25 километров он начнет пробегать с " << day + 1 << " дня." << endl;

    system("pause");
    return 0;
}