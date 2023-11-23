#include <iostream>
#include <Windows.h>

using namespace std;

struct Vector {
    private:
        int points_A[2];
        int points_B[2];
        int coordinates[2];

    public:
        void set_vector_points(int x1, int y1, int x2, int y2) {
            points_A[0] = x1;
            points_A[1] = y1;

            points_B[0] = x2;
            points_B[1] = y2;

            coordinates[0] = x2 - x1;
            coordinates[1] = y2 - y1;

        }

        // На случай если точки не знаем
        void set_vector_coordinates(int x, int y) {
            coordinates[0] = x;
            coordinates[1] = y;

            points_A[0] = 0;
            points_A[1] = 0;

            points_B[0] = 0;
            points_B[1] = 0;

        }

        int* get_coordinates() {
            return coordinates;
        }

        friend Vector operator + (Vector v1, Vector v2);
        friend Vector operator - (Vector v1, Vector v2);
        friend int operator * (Vector v1, Vector v2);
        friend ostream& operator << (ostream &os, Vector v); // friend нужен чтобы иметь доступ даже к приватным частям структуры
        friend istream& operator >> (istream &os, Vector &v);
};

ostream& operator <<(ostream &os, Vector v){
    cout << "Coordinates: " << "(" << v.coordinates[0] << "," << v.coordinates[1] << ")" << endl;

    return os;
}

istream& operator >>(istream &os, Vector &v) {
    int x1, y1, x2, y2;
    cout << "Enter X1: ";
    cin >> x1;
    cout << endl;

    cout << "Enter Y1: ";
    cin >> y1;
    cout << endl;

    cout << "Enter X2:";
    cin >> x2;
    cout << endl;

    cout << "Enter Y2";
    cin >> y2;
    cout << endl;

    v.set_vector_points(x1, y1, x2, y2);

    return os;
}

Vector operator + (Vector v1, Vector v2) {
    Vector v3{};
    v3.set_vector_coordinates(v1.coordinates[0] + v2.coordinates[0], v1.coordinates[1] + v2.coordinates[1]);
    return v3;
}

Vector operator - (Vector v1, Vector v2) {
    Vector v3{};
    v3.set_vector_coordinates(v1.coordinates[0] - v2.coordinates[0], v1.coordinates[1] - v2.coordinates[1]);
    return v3;
}

int operator * (Vector v1, Vector v2) {
    return v1.coordinates[0] * v2.coordinates[0] + v1.coordinates[1] * v2.coordinates[1];
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int action = -1;
    Vector vector1{}, vector2{};
    cin >> vector1;
    cin >> vector2;

    cout << "Choose action: (1 - '+', 2 - '-', 3 - '*')" << endl;
    cin >> action;
    cout << endl;

    switch (action) {
        case 1:
            cout << vector1 + vector2;
            break;
        case 2:
            cout << vector1 - vector2;
            break;
        case 3:
            cout << vector1 * vector2;
            break;
        default:
            cout << "Incorrect!" << endl;
            break;
    }

    system("pause");
    return 0;
}