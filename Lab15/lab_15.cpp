#include <iostream>
#include <Windows.h>

using namespace std;

void numbers_to(int n, int num=1) {
    if (num > n) return;
    cout << num << endl;
    numbers_to(n, num+1);
}

void hanoi(int disks, int kolishek, int need_kolishek, int time_kolishek) {
    if (disks == 1) {
        cout << disks << ": " << kolishek << "->" << need_kolishek << endl;
        return;
    }
    hanoi(disks - 1, kolishek, time_kolishek, need_kolishek);
    cout << disks << ": " << kolishek << "->" << need_kolishek << endl;
    hanoi(disks - 1, time_kolishek, need_kolishek, kolishek);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    numbers_to(1000);

    hanoi(3, 1, 3, 2);


    system("pause");
    return 0;
}