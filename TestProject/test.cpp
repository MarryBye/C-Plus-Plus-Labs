#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int massive_razmer = 10;
    int *array = new int[massive_razmer]{0};

    array[4] = 15;

    for (int i = 0; i < massive_razmer; i++)
    {
        cout << array[i] << endl;
    }

    delete[] array;

    ofstream fout("file.txt");
    fout << "Hello suka" << endl;
    fout.close();

    int buffer_razmer = 50;
    char *buff = new char[buffer_razmer];
    ifstream fin("file.txt");
    // fin >> buff;
    fin.getline(buff, buffer_razmer);
    cout << buff << endl;
    fin.close();

    system("pause");
    return 0;
}