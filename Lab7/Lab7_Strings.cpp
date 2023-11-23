#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Ввести с клавиатуры текст, определить какой символ встречается в тексте чаще всего.\n"
         << endl;

    string user_answer = "Пустая строка";

    cout << "Введите любой текст: ";
    getline(cin, user_answer);
    cout << endl;

    string user_answer_f = user_answer; // Костыль, чтобы когда удаляем из строки символ мы не пропускали другие

    int user_answer_len = user_answer.size();

    char best_letter;
    int best_letter_counts = 0;

    cout << "ИЩУ САМЫЙ ИСПОЛЬЗУЕМЫЙ СИМВОЛ (РЕГИСТР ВАЖЕН)..." << endl;

    for (int i = 0; i < user_answer_len; ++i)
    { // Перебираю символы строки
        char letter = user_answer[i];
        if (letter == NULL or letter == ' ')
            continue; // Когда удаляем символы остаются пустоты, проверяем

        int has_letter = user_answer_f.find(letter); // Ищем символ, который щас пробегает цикл, но в копии строки
        if (has_letter == -1)
            continue; // Из-за костыля надо проверять, трогали ли мы такой символ или нет

        int letter_counter = 0;

        cout << "\nПроверяю символ " << letter << endl;

        while (has_letter != -1)
        { // Искать символы пока не закончатся
            letter_counter++;
            user_answer_f.erase(has_letter, 1);
            has_letter = user_answer_f.find(letter); // Опять проверяем есть ли еще такие символы
            if (has_letter != -1)
            {
                cout << "Символ " << letter << " существует на позиции " << has_letter << endl;
            }
            else
            {
                cout << "Символа " << letter << " больше нет!" << endl;
            }
        }

        cout << letter << " - " << letter_counter << "\n"
             << endl;

        if (letter_counter > best_letter_counts)
        {
            best_letter = letter;
            best_letter_counts = letter_counter;
        }
    }

    cout << "РАБОТА ОКОНЧЕНА" << endl;

    cout << "\nБольше всего использовали символ " << best_letter << " (" << best_letter_counts << ")\n"
         << endl;

    system("pause");
    return 0;
}