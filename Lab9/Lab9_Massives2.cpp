#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\nДано число R (вводится с клавиатуры) и массив размера N. Найти два"
            "\nразличных элемента массива, сумма которых наиболее близка к числу R, и"
            "\nвывести эти элементы в порядке возрастания их индексов."
         << endl;

    int R = -1;
    int array[10] = {0};
    int array_size = sizeof(array) / 4;

    cout << "Введите эталонное число:";
    cin >> R;
    cout << endl;

    for (int i = 0; i < array_size; i++)
    {
        cout << i + 1 << ": ";
        cin >> array[i];
        cout << endl;
    }

    cout << "[ ";
    for (int i = 0; i < array_size; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]" << endl;

    int buf_sum = R;
    int buf_elements[2] = {0};

    cout << "Щас подумаю..." << endl;
    for (int i = 0; i < array_size; i++)
    { // Перебор всех чисел
        for (int j = i + 1; j < array_size; j++)
        { // Сравниваем число i со всеми следующими числами после него
            cout << R << " - "
                 << "(" << array[i] << " + " << array[j] << ") = " << R - (array[i] + array[j]) << endl;
            cout << "Прошлая разница: " << buf_sum << endl;
            if (R - (array[i] + array[j]) < buf_sum && R - (array[i] + array[j]) >= 0)
            { // Если разница чисел больше нуля и меньше прошлой - проходит
                cout << "Число #" << i << " + число #" << j << " оказались ближе к числу!" << endl;
                buf_sum = R - (array[i] + array[i + 1]);
                buf_elements[0] = i;
                buf_elements[1] = j;
            }
        }
    }

    cout << buf_sum << " " << array[buf_elements[0]] << " " << array[buf_elements[1]] << endl;

    system("pause");
    return 0;
}