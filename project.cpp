#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Structure to represent a university
struct uni {
    string name;
    int num_staff;
    int num_student;
};

// Base class representing personnel
class personnel {
private:
    string name;
    int age;
    string id;
    string address;
    string email;

public:
    // Constructor to initialize personnel data
    personnel(string n, int a, string id, string ad, string em) {
        name = n;
        age = a;
        address = ad;
        email = em;
        this->id = id;
    }

    // Accessor function to get personnel ID
    string getId() const {
        return id;
    }

    // Function to store personnel data in a file
    void store_data(ofstream& myfile) const {
        // Store personnel data in the file
        myfile << "Name: " << name << endl;
        myfile << "Age: " << age << endl;
        myfile << "ID: " << id << endl;
        myfile << "Address: " << address << endl;
        myfile << "Email: " << email << endl;
    }

    // Function to print personnel data
    void print() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
    }

    // Destructor
    ~personnel() {
        cout << "Destructor for personnel class called" << endl;
    }
};

// Class representing a student, inheriting from personnel
class Student: public personnel {
private:
    int year;
    double grade;

public:
    // Constructor to initialize student data
    Student(string n, int a, string ad, string em, string id, int y, double g):personnel(n, a, ad, em, id) {
        year = y;
        grade = g;
    }

    // Function to print student data
    void print() const {
        personnel::print();
        cout << "Year you're in: " << 2024 - year << endl;
        cout << "Your grade: " << grade << endl;
    }

    // Function to store student data
    void store_data(ofstream& myfile) const {
        // Call base class method to store personnel data
        personnel::store_data(myfile);

        // Store student-specific data in the file
        myfile << "Student.\n";
        myfile << "Year you're in: " << year << endl;
        myfile << "Grade: " << grade << endl;
        myfile << "///////////////////" << endl;
    }

    // Destructor
    ~Student() {
        cout << "Destructor for Student class called" << endl;
    }
};

// Class representing a staff member, inheriting from personnel
class Staff: public personnel {
private:
    int hours;
    int salary;
    string status;

public:
    // Constructor to initialize staff data
    Staff(string n, int a, string ad, string em, string id, int h, int s, string st):personnel(n, a, ad, em, id) {
        hours = h;
        salary = s;
        status = st;
    }

    // Destructor
    ~Staff() {
        cout << "Destructor for Staff class called" << endl;
    }

    // Function to store staff data in a file
    void store_data(ofstream& myfile) const {
        // Call base class method to store personnel data
        personnel::store_data(myfile);

        // Store staff-specific data in the file
        myfile << "Staff.\n";
        myfile << "Hours worked: " << hours << endl;
        myfile << "Salary: " << salary << endl;
        myfile << "Status: " << status << endl;
        myfile << "///////////////////" << endl;
    }

    // Function to print staff data
    void print() const {
        personnel::print();
        cout << "Hours this month: " << hours << endl;
        cout << "Your salary: " << salary << endl;
        cout << "You are a: " << status << endl;
    }
};

// Function to convert a string to lowercase
string toLowerCase(const string& str) {
    string result;
    for (size_t i = 0; i < str.size(); ++i) {
        char c = str[i];
        result += tolower(c);
    }
    return result;
}

// Function to check if a string represents an integer
bool isInteger(const string& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        if (!isdigit(str[i])) {
            cout << "Invalid input! Please enter a valid number." << endl;
            return false;
        }
    }
    return true;
}

// Function to interactively create a staff member or a student
void staff_or_student() {
    string response;
    string answer;
    while (answer != "staff" && answer != "student") {
        cout << "Staff or Student?: ";
        cin >> response;
        answer = toLowerCase(response);
    }

    if (answer == "staff") {
        // Prompt user for staff details
        string name;
        string age_str;
        int age;
        string id;
        string address;
        string email;
        string hours_str;
        int hours;
        string salary_str;
        int salary;
        string status;

        cout << "Please enter your name: ";
        cin.ignore(); // Ignore the newline character left by previous cin
        getline(cin, name); // Use getline for name
        cout << "Please enter your age: ";
        cin >> age_str;
        while (!isInteger(age_str)) {
            cout << "Please enter a valid age: ";
            cin >> age_str;
        }
        istringstream(age_str) >> age;
        cout << "Please enter your id: ";
        cin >> id;
        cin.ignore(); // Ignore the newline character left by previous cin
        cout << "Please enter your address: ";
        getline(cin, address); // Use getline for address
        cout << "Please enter your email: ";
        cin >> email;
        cout << "Please enter hours worked this month: ";
        cin >> hours_str;
        while (!isInteger(hours_str)) {
            cout << "Please enter a valid number of hours: ";
            cin >> hours_str;
        }
        istringstream(hours_str) >> hours;
        cout << "Please enter your salary: ";
        cin >> salary_str;
        while (!isInteger(salary_str)) {
            cout << "Please enter a valid salary: ";
            cin >> salary_str;
        }
        istringstream(salary_str) >> salary;

        // Determine staff status based on hours worked
        if (hours > 30) {
            status = "Full_time";
        } else {
            status = "Part_time";
        }

        // Create Staff object and store data
        Staff staf(name, age, address, email, id, hours, salary, status);
        staf.print();
        cout << "Save data? (y/n): ";
        string save;
        cin >> save;
        save = toLowerCase(save);
        if (save == "y") {
            // Open the file for writing
            ofstream MyFile("data.txt", ios::app);
            if (MyFile.is_open()) {
                staf.store_data(MyFile);
                cout << "Data saved in data.txt" << endl;
                MyFile.close(); // Close the file
            } else {
                cout << "Unable to open file for writing!" << endl;
            }
        } else {
            cout << "Data not saved" << endl;
        }
    }

    if (answer == "student") {
        // Prompt user for student details
        string name;
        string age_str;
        int age;
        string id;
        string address;
        string email;
        string year_str;
        int year;
        double grade;

        cout << "Please enter your name: ";
        cin.ignore(); // Ignore the newline character left by previous cin
        getline(cin, name); // Use getline for name
        cout << "Please enter your age: ";
        cin >> age_str;
        while (!isInteger(age_str)) {
            cout << "Please enter a valid age: ";
            cin >> age_str;
        }
        istringstream(age_str) >> age;
        cout << "Please enter your id: ";
        cin >> id;
        cin.ignore(); // Ignore the newline character left by previous cin
        cout << "Please enter your address: ";
        getline(cin, address); // Use getline for address
        cout << "Please enter your email: ";
        cin >> email;
        cout << "Please enter year of joining the university: ";
        cin >> year_str;
        while (!isInteger(year_str)) {
            cout << "Please enter a valid year: ";
            cin >> year_str;
        }
        istringstream(year_str) >> year;
        cout << "Please enter your grade: ";
        cin >> grade;

        // Create Student object and print data
        Student st1(name, age, address, email, id, year, grade);
        st1.print();

        cout << "Save data? (y/n): ";
        string save;
        cin >> save;
        save = toLowerCase(save);
        if (save == "y") {
            // Open the file for writing
            ofstream MyFile("data.txt", ios::app);
            if (MyFile.is_open()) {
                st1.store_data(MyFile);
                cout << "Data saved in data.txt" << endl;
                MyFile.close(); // Close the file
            } else {
                cout << "Unable to open file for writing!" << endl;
            }
        } else {
            cout << "Data not saved" << endl;
        }
    }
}


int main() {
    // Call function to interactively create staff or student
    staff_or_student();

    // Create a university object
    uni Ismailia_National_University;
    Ismailia_National_University.name = "New Ismailia National University";
    Ismailia_National_University.num_staff = 1;
    Ismailia_National_University.num_student = 1;

    // Print university name
    cout << "University name: " << Ismailia_National_University.name;
    return 0;
}
