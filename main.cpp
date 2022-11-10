#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

class student {
private:
    string name;
    int id;
    vector<string> courses;
public:
    student(string studentName, int studentID, string course) : name(studentName), id(studentID)
    {
        courses.push_back(course);
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    void addCourse(string course){

    }
    //overload
    void addCouse(vector<string> courseV){

    }
};

class course {
private:
    string courseCode;
    unordered_map<int, tuple<short>> cStudents;
public:
    course(string code, int id, tuple<short> grades) : courseCode(code)
    {
        cStudents[id]=grades;
    }
    float calFinal(){

    }
    string getCouseCode(){
        return courseCode;
    }
    void addStudent(int student, tuple<short> grades){

    }
    void deleteStudent(int student){

    }
    void changeGrade(int student, int assessment, short grade){

    }
    //overload
    void changeGrade(int student, vector<int> assessment, tuple<short> grade){

    }

};

int main() {
    int test = 0;
    cout << sizeof(test) << endl;
    return 0;
}