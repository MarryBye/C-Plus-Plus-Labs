#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\nДан массив размера N. Количество элементов N и"
            "\nэлементы массива вводятся с клавиатуры. Найти и вывести на экран"
            "\nмаксимальный из элементов массива, не являющихся ни локальным"
            "\nминимумом (локальный минимум - это элемент, который меньше"
            "\nлюбого из своих соседей), ни локальным максимумом (локальный"
            "\nмаксимум — это элемент, который больше любого из своих соседей).\n"
         << endl;

    int array_size = -1;
    while (array_size > 100 or array_size < 1)
    {
        cout << "Введите число от 1 до 100:";
        cin >> array_size;
        cout << endl;
    }

    int array[array_size] = {0};

    cout << "Заполните массив числами:" << endl;
    for (int i = 0; i < array_size; i++)
    {
        cout << i + 1 << ": ";
        cin >> array[i];
        cout << endl;
    }

    cout << "[ ";
    for (int i = 0; i < array_size; i++)
        cout << array[i] << " ";
    cout << "]" << endl;

    int max_number = array[0];

    for (int i = 1; i < array_size; i++)
    {
        if (array[i] > array[i + 1] && array[i] > array[i - 1]) // Проверяем что не локальный максимум
            continue;
        if (array[i] < array[i + 1] && array[i] < array[i - 1]) // Проверяем что не локальный минимум
            continue;
        if (max_number < array[i]) // Проверяем больше ли оно прошло числа
            max_number = array[i];
    }

    cout << "Не локальный минимум или максимум: " << max_number << endl;

    cout << "Сортирую массив выше..." << endl;

    int sort_temp = -1;
    for (int i = 0; i < array_size - 1; i++)
    {
        for (int j = 0; j < array_size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                sort_temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = sort_temp;
            }
        }
    }

    cout << "[ ";
    for (int i = 0; i < array_size; i++)
        cout << array[i] << " ";
    cout << "]" << endl;

    system("pause");
    return 0;
}