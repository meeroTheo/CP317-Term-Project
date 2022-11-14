#include "student.h"
student::student() : name(NULL), id(NULL), courses(sizeof(course),course()) {}
student::student(string studentName, string studentID) : name(studentName), id(studentID),courses(sizeof(course),course()) {}
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
