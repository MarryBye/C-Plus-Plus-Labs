#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

struct Student {

    string first_name;
    string last_name;
    int born_year;
    int marks[5];

};

int getAverage(Student student) {
    int average = 0;
    for (int i = 0; i < 5; i++) {
        average += student.marks[i];
    }
    return average / 5;
}

void getSortedList(Student students[]) {
    // Сортировка
    for(int i = 0; i<30; i++) {
        for(int j = i+1; j<30; j++)
        {
            int now_student_avg = getAverage(students[i]);
            int next_student_avg = getAverage(students[j]);

            if(next_student_avg > now_student_avg) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    for (int i = 0; i < 30; i++) {
        if (students[i].last_name == "" or students[i].first_name == "") continue;
        cout << students[i].first_name << " " << students[i].last_name << ": " << getAverage(students[i]) << endl;
    }
}

void findStudent(Student students[], string first_name, string last_name) {
    for (int i = 0; i < 30; i++) {
        if (students[i].last_name == last_name && students[i].first_name == first_name) {
            cout << "Borned in: " << students[i].born_year << " year" << endl;
            cout << "Last marks: " << students[i].marks[0] << " " << students[i].marks[1] << " " << students[i].marks[2]
                    << " " << students[i].marks[3] << " " << students[i].marks[4] << endl;
            return;
        }
    }
    cout << "No student with this data!" << endl;
}

void deleteStudent(Student students[], string first_name, string last_name) {
    for (int i = 0; i < 30; i++) {
        if (students[i].last_name == last_name && students[i].first_name == first_name) {
            students[i].first_name = "";
            students[i].last_name = "";
            students[i].born_year = -1;
            students[i].marks[0] = -1;
            students[i].marks[1] = -1;
            students[i].marks[2] = -1;
            students[i].marks[3] = -1;
            students[i].marks[4] = -1;
            cout << "Succesfully deleted " << first_name << " " << last_name << endl;
        }
    }
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student students[30];

    ifstream db_file("C:\\Users\\vikto\\Documents\\Projects\\C++\\Lab16\\db.txt");
    char db_file_line[256];

    if (db_file.is_open()) {

        int student_number = 0;
        string new_student_info[8];
        string buff;

        while (db_file.getline(db_file_line, 256)) {

            int student_info_element_number = 0;
            buff.clear();

            for (int i = 0; i < 256; i++) {
                if (db_file_line[i] != ' ') {
                    if (db_file_line[i] == ';') break;
                    buff += db_file_line[i];
                } else {
                    new_student_info[student_info_element_number] = buff;
                    student_info_element_number++;
                    buff.clear();
                }
            }

            Student new_student;
            new_student.first_name = new_student_info[0];
            new_student.last_name = new_student_info[1];
            new_student.born_year = stoi(new_student_info[2]);
            new_student.marks[0] = stoi(new_student_info[3]);
            new_student.marks[1] = stoi(new_student_info[4]);
            new_student.marks[2] = stoi(new_student_info[5]);
            new_student.marks[3] = stoi(new_student_info[6]);
            new_student.marks[4] = stoi(new_student_info[7]);

            students[student_number] = new_student;
            student_number++;

        }
        db_file.close();
    }

    cout << "List of students (sorted by average mark): " << endl;
    getSortedList(students);

    cout << "Find student Tatiana Ivanova" << endl;
    findStudent(students, "Tatiana", "Ivanova");

    cout << "Delete Tatiana Ivanova" << endl;
    deleteStudent(students, "Tatiana", "Ivanova");

    cout << "List of students after deletion (sorted by average mark): " << endl;
    getSortedList(students);

    system("pause");
    return 0;
}