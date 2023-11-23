#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array[10];

    cout << "Примеры из лекции, проработанные.\n"
         << endl;
    cout << "Сначала введите элементы массива\n"
         << endl;

    int array_len = sizeof(array) / 4;

    for (int i = 0; i < array_len; i++)
    {
        cout << "Элемент №" << i + 1 << ": ";
        cin >> array[i];
        cout << endl;
    }

    int el_sum = 0;
    int el_mul = 1;

    int max_el = array[0];
    int del_el;

    int sort_temp;

    cout << "Ваш массив: [ ";
    for (int i = 0; i < array_len; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;

    cout << "\nПрограммы:" << endl;
    cout << "1 - Сумма элементов массива" << endl;
    cout << "2 - Произведение элементов массива" << endl;
    cout << "3 - Поиск максимального элемента массива" << endl;
    cout << "4 - Удаление элемента массива" << endl;
    cout << "5 - Сортировка массива" << endl;
    cout << "6 - Заново заполнить массив" << endl;

    int command = -1;

    while (command != 0)
    {
        cout << "Выберите действие (0 - выключить программу):";
        cin >> command;
        cout << endl;
        switch (command)
        {
        case 0:
            break;
        case 1:
            el_sum = 0;
            for (int i = 0; i < array_len; i++)
                el_sum += array[i];
            cout << "Сумма элементов массива: " << el_sum << endl;
            break;
        case 2:
            el_mul = 1;
            for (int i = 0; i < array_len; i++)
                el_mul *= array[i];
            cout << "Произведение элементов массива: " << el_mul << endl;
            break;
        case 3:
            max_el = array[0];
            for (int i = 0; i < array_len; i++)
            {
                if (array[i] > max_el)
                    max_el = array[i];
            }
            cout << "Наибольший элемент массива: " << max_el << endl;
            break;
        case 4:
            del_el = -1;
            while (del_el < 0 or del_el >= array_len)
            {
                cout << "Введите какой элемент удалить: ";
                cin >> del_el;
                cout << endl;
            }
            for (int i = del_el; i < array_len; i++)
                array[i] = array[i + 1];
            array_len--;
            cout << "Итоговый массив: [ ";
            for (int i = 0; i < array_len; i++)
            {
                cout << array[i] << " ";
            }
            cout << "]" << endl;
            break;
        case 5:
            for (int i = 0; i < array_len - 1; i++)
            {
                for (int j = 0; j < array_len - i - 1; j++)
                {
                    if (array[j] > array[j + 1])
                    {
                        sort_temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = sort_temp;
                    }
                }
            }
            cout << "Итоговый массив: [ ";
            for (int i = 0; i < array_len; i++)
            {
                cout << array[i] << " ";
            }
            cout << "]" << endl;
            break;
        case 6:
            array_len = sizeof(array) / 4;
            for (int i = 0; i < array_len; i++)
            {
                cout << "Элемент №" << i + 1 << ": ";
                cin >> array[i];
                cout << endl;
            }
            cout << "Ваш массив: [ ";
            for (int i = 0; i < array_len; i++)
            {
                cout << array[i] << " ";
            }
            cout << "]" << endl;
            break;
        default:
            cout << "Команды " << command << " не существует!" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}