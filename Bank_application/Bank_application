#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
    float gpa;
};

string filename = "students.txt";

void saveToFile(vector<Student> students) {
    ofstream file(filename);
    for (int i = 0; i < students.size(); i++) {
        file << students[i].id     << "\n";
        file << students[i].name   << "\n";
        file << students[i].age    << "\n";
        file << students[i].course << "\n";
        file << students[i].gpa    << "\n";
    }
    file.close();
}


vector<Student> loadFromFile() {
    vector<Student> students;
    ifstream file(filename);
    if (!file.is_open()) {
        return students;
    }
    Student s;
    while (file >> s.id) {
        file.ignore();
        getline(file, s.name);
        file >> s.age;
        file.ignore();
        getline(file, s.course);
        file >> s.gpa;
        file.ignore();
        students.push_back(s);
    }
    file.close();
    return students;
}


void displayAll(vector<Student> students) {
    if (students.size() == 0) {
        cout << "\nNo students found!\n";
        return;
    }
    cout << "\n========================================\n";
    cout << "          ALL STUDENTS LIST             \n";
    cout << "========================================\n";
    cout << "ID   Name          Age   Course    GPA  \n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < students.size(); i++) {
        cout << students[i].id     << "    ";
        cout << students[i].name   << "    ";
        cout << students[i].age    << "    ";
        cout << students[i].course << "    ";
        cout << students[i].gpa    << "\n";
    }
    cout << "----------------------------------------\n";
    cout << "Total Students: " << students.size() << "\n";
    cout << "========================================\n";
}

void addStudent(vector<Student>& students) {
    Student s;
    if (students.size() == 0) {
        s.id = 1;
    } else {
        s.id = students[students.size() - 1].id + 1;
    }
    cout << "\n========================================\n";
    cout << "           ADD NEW STUDENT              \n";
    cout << "========================================\n";
    cin.ignore();
    cout << "Enter Name   : ";
    getline(cin, s.name);
    cout << "Enter Age    : ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter Course : ";
    getline(cin, s.course);
    cout << "Enter GPA    : ";
    cin >> s.gpa;
    students.push_back(s);
    saveToFile(students);
    cout << "\nStudent added! ID is: " << s.id << "\n";
}


void searchStudent(vector<Student> students) {
    int searchId;
    cout << "\nEnter Student ID to search: ";
    cin >> searchId;
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == searchId) {
            cout << "\n========================================\n";
            cout << "            STUDENT FOUND               \n";
            cout << "========================================\n";
            cout << "ID     : " << students[i].id     << "\n";
            cout << "Name   : " << students[i].name   << "\n";
            cout << "Age    : " << students[i].age    << "\n";
            cout << "Course : " << students[i].course << "\n";
            cout << "GPA    : " << students[i].gpa    << "\n";
            cout << "========================================\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nNo student found with ID: " << searchId << "\n";
    }
}

void updateStudent(vector<Student>& students) {
    int searchId;
    cout << "\nEnter Student ID to update: ";
    cin >> searchId;
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == searchId) {
            cout << "\n========================================\n";
            cout << "           UPDATE STUDENT               \n";
            cout << "========================================\n";
            cin.ignore();
            cout << "New Name   : ";
            getline(cin, students[i].name);
            cout << "New Age    : ";
            cin >> students[i].age;
            cin.ignore();
            cout << "New Course : ";
            getline(cin, students[i].course);
            cout << "New GPA    : ";
            cin >> students[i].gpa;
            saveToFile(students);
            cout << "\nStudent updated successfully!\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nNo student found with ID: " << searchId << "\n";
    }
}


void deleteStudent(vector<Student>& students) {
    int searchId;
    cout << "\nEnter Student ID to delete: ";
    cin >> searchId;
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == searchId) {
            cout << "\nDeleting: " << students[i].name << "\n";
            char confirm;
            cout << "Are you sure? (y/n): ";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                students.erase(students.begin() + i);
                saveToFile(students);
                cout << "Student deleted successfully!\n";
            } else {
                cout << "Deletion cancelled.\n";
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nNo student found with ID: " << searchId << "\n";
    }
}


void showMenu() {
    cout << "\n========================================\n";
    cout << "      STUDENT MANAGEMENT SYSTEM         \n";
    cout << "========================================\n";
    cout << "  1. Add Student\n";
    cout << "  2. Display All Students\n";
    cout << "  3. Search Student\n";
    cout << "  4. Update Student\n";
    cout << "  5. Delete Student\n";
    cout << "  6. Exit\n";
    cout << "========================================\n";
    cout << "  Your choice: ";
}

int main() {
    vector<Student> students = loadFromFile();
    cout << "\nWelcome! " << students.size() << " student(s) loaded.\n";

    int choice;
    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAll(students);
        } else if (choice == 3) {
            searchStudent(students);
        } else if (choice == 4) {
            updateStudent(students);
        } else if (choice == 5) {
            deleteStudent(students);
        } else if (choice == 6) {
            cout << "\nThank you! Goodbye!\n";
        } else {
            cout << "\nWrong choice! Please enter 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}
