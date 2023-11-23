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

bool check_password(char login[], char user_password[]) {
    char *gen_pass = create_password(login);

    return (strcmp(user_password, gen_pass) == 0);
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char password[16];
    char login[24];
    bool authorized = false;

    cout << "Program created by Viktor Lukianov" << endl;
    cout << "Please, register!" << endl;
    cout << "<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>" << endl;

    int page = 0;

    while (true) {

        cout << "\nMenu\n" << endl;
        cout << "1. Information" << endl;
        cout << "2. About registration" << endl;
        cout << "3. Sign Up!" << endl;
        cout << "4. Exit" << endl;

        cout << "Select menu:";
        cin >> page;
        cout << endl;

        if (page == 1) {

            if (!authorized) {
                cout << "Please, register to see information!" << endl;
            } else {
                cout << "Thanks for registration! There is no any information..." << endl;
            }

        } else if (page == 2) {

            cout << "To register you copy of program you need to buy this program only for 99.9$ USD!" << endl;
            cout << "When you buy our program, you will get a 16 digit password." << endl;

        } else if (page == 3) {

            cin.ignore(); // cin() оставляет какой-то мусор судя по информации из интернета, из-за чего ломаются gets ниже

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

            cout << "Please, enter your password...";
            gets(password);
            cout << endl;

            bool result = check_password(login, password);

            if (result) {
                cout << "Successfully authorized!" << endl;
                authorized = true;
            } else {
                cout << "Invalid password! Please, buy this program on our site." << endl;
            }

        } else if (page == 4) {

            break;

        } else {

            cout << "Invalid page!" << endl;

        }

    }

    system("pause");
    return 0;
}