#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Выписав первые шесть простых чисел, получим 2, 3, 5, 7, 11 и 13. Очевидно,\n"
            "что 6-ое простое число - 13.\n"
            "Какое число является 101-ым простым числом?"
         << endl;

    int counter = 1, number = 2;

    while (counter <= 101)
    {
        bool easy = true;
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                easy = false;
                break;
            }
        }
        if (easy)
        {
            cout << counter << ") " << number << endl;
            counter++;
        }
        number++;
    }

    cout << "101-е простое число: " << number - 1 << endl;

    system("pause");
    return 0;
}