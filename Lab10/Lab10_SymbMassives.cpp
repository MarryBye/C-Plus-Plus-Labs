#include <iostream>
#include <Windows.h>
#include <string.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\nВвести строки str1 и str2 с клавиатуры. Найти первую подстроку str2 в"
            "\nстроке str1. Вывести на экран индекс начала подстроки. Если строка не"
            "\nнайдена – вывести -1."
         << endl;

    string str1, str2 = "";
    cout << "Введите первую строку: " << endl;
    getline(cin, str1);

    cout << "Введите подстроку: " << endl;
    getline(cin, str2);

    cout << str1 << endl;
    cout << str2 << endl;

    int pos = -1;
    for (int i = 0; i < str1.length(); i++)
    { // Проверяем каждую букву первой строки
        cout << str1[i] << " = " << str2[0] << " ?" << endl;
        if (str1[i] == str2[0])
        { // Если начало подстроки совпало с буквой, начинаем проверять всю строку
            cout << "Проверяю подстроку..." << endl;
            pos = i; // На будущее если окажется подстрокой сразу сохраняем позицию
            for (int j = 0; j < str2.length(); j++)
            { // Перебираем буквы подстроки и сравниваем с каждой следующей буквой строки
                cout << str1[i + j] << " = " << str2[j] << " ?" << endl;
                if (str1[i + j] != str2[j])
                { // Первой несовпадение - ломаем цикл, обнуляем позицию и дальше проверяем строку
                    cout << "Не подстрока!" << endl;
                    pos = -1;
                    break;
                }
            }
            if (pos != -1) // Чтобы не было лишних проверок, нам нужно только первое вхождение
                break;
        }
    }

    cout << "Первое вхождение подстроки: " << pos << endl;

    cout << "\nПалиндромы в строке\n"
         << endl;

    cout << "Введите строку: " << endl;
    char str3[256];
    gets(str3);

    cout << "Строка: " << str3 << "\n"
         << endl;

    cout << "Палиндромы: " << endl;

    string buf_word = "";
    bool success = true;

    for (int i = 0; i <= strlen(str3); i++)
    { // Перебираем строку
        if (str3[i] != ' ' && i != strlen(str3))
        { // Добавляем буквы в буффер, пока не пробел/конец строки
            buf_word.push_back(str3[i]);
        }
        else
        {
            if (buf_word == "")
                continue;
            for (int j = buf_word.length() - 1; j >= 0; j--)
            { // Перебираем слово из буффера наоборот
                if (buf_word[j] != buf_word[buf_word.length() - 1 - j])
                { // Сравниваем буквы с конца с буквами из начала
                    success = false;
                    break;
                }
            }
            if (success)
            {
                cout << buf_word << endl;
            }
            success = true;
            buf_word = "";
        }
    }

    system("pause");
    return 0;
}