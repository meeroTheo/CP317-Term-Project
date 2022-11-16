#include "student.h"
student::student() : name(NULL), id(NULL){}
student::student(string studentName, string studentID) : name(studentName), id(studentID) {}
student::student(string studentName, string studentID, string course) : name(studentName), id(studentID) {
    courses.push_back(course);
}
// overload
string student::getID() {
    return id;
}
string student::getName() {
    return name;
}
void student::addCourse(string course) {
    courses.push_back(course);
}
// overload
void student::addCourse(vector<string> courseV) {
}
