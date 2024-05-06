#include <iostream>
#include <cctype> 
using namespace std;
//structure for the university
struct uni{
string name;
int num_staff;
int num_student;

};
// Class representing the personnel of the university
class personnel{
    private:
string name;
int age;
string id;
string address;
string email;
    public:
//Constructor
personnel(string n, int a,string id,string ad,string em){
    name = n;
    age = a;
    address = ad;
    email = em;
    id = id;
    }
     //Saving data in arrays
    void store_data(){
    string data[4] = {name,id,address,email};
}
// Print out the details of the personnel 
    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"id: "<<id<<endl;
        cout<<"address: "<<address<<endl;
        cout<<"email: "<<email<<endl;
}
// Destructor for releasing resources when the personnel object is destroyed
~personnel() {
        cout << "Destructor for personnel class called" << endl;}
};
// Class representing the students of the university, it is a child class
class Student: public personnel {
    private:
    int year;
    int grade;
    int cureent_year = 2024;
    public:
    //Constructor
    Student(string n, int a,string ad,string em,string id, int y,double g):personnel(n,a,ad,em,id){
        year = y;
        grade = g;
    }
    // Print out the details of the student
    void print(){
        personnel::print();
        cout<<"year your in: "<<cureent_year - year<<endl;
        cout<<"your grade: "<<grade<<endl;
    }
    //Saving data in arrays
    void store_data(){
        int num_data[2] = {year,grade};

    }
    // Destructor for releasing resources when the student object is destroyed
    ~Student() {
        cout << "Destructor for personnel class called" << endl;}
};
// Class representing the staff of the university, it is a child class
class Staff: public personnel{
private:
int hours;
int Salary;
string status; //full time or part time

public:
//Constructor
Staff (string n, int a,string ad,string em,string id,int h, int s,string st):personnel(n,a,ad,em,id){
    hours = h;
    Salary = s;
    status = st;
}
// Destructor for releasing resources when the staff object is destroyed
    ~Staff() {
        cout << "Destructor for Staff class called" << endl;
    }
//Saving data in arrays
void store_data(){
    string data[1] = {status};
    int num_data[3] = {hours,Salary};
}
// Print out the details of the staff
void print(){
        personnel::print();
        cout<<"hours this month: "<<hours<<endl;
        cout<<"Your salary: "<<Salary<<endl;
        cout<<"You are a: "<<status<<endl;
    }
};
    string toLowerCase(const string& str) {
    string result;
    for (char c : str) {
        result += tolower(c);
    }
    return result;

}

int staff_or_student(){
    string response;
    bool student = false;
    bool staff = false;
string answer;
// Loop until the user enters a valid response (either "staff" or "student")
while (answer != "staff" && answer != "student"){
//Asking the user for input
    cout<<"Staff or Student?: "; 
    cin>>response;
    answer = toLowerCase(response);}
    // Validate that the input is either "staff" or "student"
    if (answer== "staff"){
       staff = true;
    }
    else if (answer == "student")
    {
        student = true;
    }
    if (staff){
        string name;
int age;
string id;
string address;
string email;
int hours;
int Salary;
string status;
// Prompting the user to enter their data
cout<<"Please enter your name: "<<endl;
cin>>name;
cout<<"Please enter your age: "<<endl;
cin>>age;
cout<<"Please enter your id: "<<endl;
cin>>id;
cout<<"Please enter your address: "<<endl;
cin>>address;
cout<<"Please enter your email: "<<endl;
cin>>email;
cout<<"Please enter hours worked this month: "<<endl;
cin>>hours;
cout<<"Please enter your salary: "<<endl;
cin>>Salary;

    if (hours>30){
        status = "Full_time";
    }
    else{
        status = "Part_time";
    }
        Staff staf(name,age,id,address,email,hours,Salary,status);
        // Print the details of the staff member
        staf.print();
    }
    if (student){
string name;
int age;
string id;
string address;
string email;
int year;
double grade;
// Prompting the user to enter their data
cout<<"Please enter your name: "<<endl;
cin>>name;
cout<<"Please enter your age: "<<endl;
cin>>age;
cout<<"Please enter your id: "<<endl;
cin>>id;
cout<<"Please enter your address: "<<endl;
cin>>address;
cout<<"Please enter your email: "<<endl;
cin>>email;
cout<<"Please enter year of joining the university: "<<endl;
cin>>year;
cout<<"Please enter your grade: "<<endl;
cin>>grade;
        Student st1(name,age,id,address,email,year,grade);
        st1.print();

    }
    return 0;
};
int main() {

staff_or_student();
uni Ismailia_National_University;
Ismailia_National_University.name = "New Ismailia National University";
Ismailia_National_University.num_staff = 1;
Ismailia_National_University.num_student = 1;
cout<<"University name: "<<Ismailia_National_University.name;
    return 0;
}
