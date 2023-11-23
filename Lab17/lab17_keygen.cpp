#include <iostream>
#include <Windows.h>

using namespace std;

int count_digits(char login[]) {
    short int login_digit_len = 0;
    for (int i = 0; i < strlen(login); i++) {
        if (isdigit(login[i])) {
            login_digit_len++;
            break;
        }
    }
    return login_digit_len;
}

int get_char_array_code(char login[]) {
    short int char_array_code = 0;
    for (int i = 0; i < strlen(login); i++) {
        char_array_code += char(login[i]);
    }
    return char_array_code;
}

char* create_password(char login[]) {

    char static generated_password[16] = "";
    char symbols[36] = {'1', '2', '3', '4', '5', '6', '7', '8', '9',
                        '0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
                        'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Получаем псевдорандомные числа с сидом, зависящим от кода логина (сумма всех кодов символов) умножить
    // на формулу из задания
    srand(get_char_array_code(login) * (10 + count_digits(login) - 3 * strlen(login)));

    for (int i = 0; i < 15; i++)
        generated_password[i] = symbols[rand() % 35];

    return generated_password;

}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char login[24];

    cout << "\nKEYGENERATOR FOR VIKTOR`S PROGRAM\n" << endl;

    while (true) {
        cout << "Please, enter your login...";
        gets(login);
        cout << endl;

        if (strlen(login) < 10 || strlen(login) > 24) {
            cout << "Invalid login! It must contain minimum 10 characters." << endl;
        } else {
            break;
        }
    }

    char *generated_password = create_password(login);

    cout << "Successfully generated password! Use program 4 free :)\n" << endl;

    cout << "Login: " << login << endl;
    cout << "Password: " << generated_password << endl;
    cout << endl;

    system("pause");
    return 0;
}