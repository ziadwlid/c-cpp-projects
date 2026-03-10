#include <iostream>
#include <vector>
using namespace std;

class subject{
    public:
    string subjectname;
    int credit;
    float gradepoint;

    subject (string name, int cr, float gp){
        subjectname = name;
        credit = cr;
        gradepoint = gp;
    }
};

class student{
    public:
    string name;
    vector <subject> subjects;
    student (string studentname){
        name = studentname;
    }
    void add_subject(string subjectName, int credit, float gradepoint){
        subject newsubject (subjectName, credit, gradepoint);
        subjects.push_back(newsubject);
    }
    float calculator_cgpa(){
        int totalcredit = 0;
        float weighgradepoint = 0;
        for (const subject & subject:subjects){
            totalcredit += subject.credit;
            weighgradepoint += subject.credit*subject.gradepoint;
        }
        return (totalcredit > 0) ? (weighgradepoint / totalcredit) : 0;
    }
    void dispalycgpa (){
        cout << "student name" << name << endl;
        float cgpa = calculator_cgpa();
        cout << "cgpa is : " << cgpa << endl;
    }
    void addSubject (string subjectname, int credit, float creditt){

    }
};

int main (){
    string student_name;
    int numsub;
    cout << "enter student's name: ";
    getline(cin, student_name);
    student student1(student_name);

    cout << "enter the number of subjects: "; 
    cin >> numsub;
    for (int i = 0; i < numsub; ++i){
        string subject_name;
        int credit;
        float grade_point;
        cout << "enter subject name: ";
        cin.ignore();
        getline(cin, subject_name);
        cout << "enter the credit of " << subject_name << ": " ;
        cin >> credit;
        cout << "enter the grade point: ";
        cin >> grade_point;
        student1.add_subject (subject_name, credit, grade_point);
    }
    student1.dispalycgpa();
    return 0;
}