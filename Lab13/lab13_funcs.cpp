#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

template<typename T>

// Использовал темплейт чтобы адаптировать функцию под любые типы данных
int get_element_last_index(T *array, int array_size, T element_to_seek) {
    int index = -1;
    for (int i = 0; i < array_size; i++) {
        if (array[i] == element_to_seek)
            index = i;
    }
    return index;
}

template<typename T>

T* get_double_elements_array(T *array, int array_size) {

    T *new_massive = new T[array_size]{0};
    int repeats = 0;
    int element_now = 0;
    int slot = 0;
    bool already_exists = false;

    for (int i = 0; i < array_size; i++) {
        element_now = array[i];
        repeats = 0;
        already_exists = false;
        for (int j = 0; j < array_size; j++) {
            if (element_now == array[j])
                repeats++;
        }
        if (repeats != 2) continue;
        for (int j = 0; j < array_size; j++) {
            if (new_massive[j] == element_now) {
                already_exists = true;
                break;
            }
        }
        if (!already_exists) {
            new_massive[slot] = element_now;
            slot++;
        }
    }

    return new_massive;
}

int main()
{

    srand(time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array_size = 5;

    cout << "Enter array size:";
    cin >> array_size;
    cout << endl;

    int *numbers_array = new int[array_size];

    cout << "[ ";
    for (int i = 0; i < array_size; i++) {
        numbers_array[i] = rand() % 100;
        cout << numbers_array[i] << " ";
    }
    cout << "]" << endl;

    cout << "FIND THE LAST INDEX OF A USER ENTERED NUMBER" << endl;

    int element;
    cout << "Enter which element we seek:";
    cin >> element;
    cout << endl;

    int ind = get_element_last_index(numbers_array, array_size, element);
    cout << "Last index: " << ind << ", for element " << element << endl;

    cout << "_________________________________________________________________" << endl;

    cout << "FIND ALL NUMBERS IN AN ARRAY THAT REPEAT 2 TIMES AND MAKE A NEW ARRAY OUT OF THEM" << endl;

    int* double_elements_array = get_double_elements_array(numbers_array, array_size);
    cout << "[ ";
    for (int i = 0; i < array_size; i++) {
        cout << double_elements_array[i] << " ";
    }
    cout << "]" << endl;

    delete[] numbers_array;

    cout << "_________________________________________________________________" << endl;

    system("pause");
    return 0;
}