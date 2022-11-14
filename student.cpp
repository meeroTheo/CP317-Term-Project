#include "student.h"
student::student() {
    this->name = "";
    this->id = "";
}
student::student(string studentName, string studentID) : name(studentName), id(studentID) {}
student::student(string studentName, string studentID, course &course) : name(studentName), id(studentID) {
    courses.push_back(course);
}
// overload
string student::getID() {
    return id;
}
string student::getName() {
    return name;
}
void student::addCourse(course &course) {
    courses.push_back(course);
}
// overload
void student::addCourse(vector<course> courseV) {
}
