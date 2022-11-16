#include "course.h"

course::course() : courseCode(NULL) {};
course::course(string code, string id, tuple<short, short, short, short> grades) : courseCode(code) {
    cStudents[id]=grades;
}
float course::calFinal() {
    return 0.0;
}
string course::getCourseCode() {
    return courseCode; // maybe return a copy with get stuff?
}
void course::addStudent(string student, tuple<short, short, short, short> grades) {
    cStudents[student] = grades;
}
void course::deleteStudent(string student) {
}
void course::changeGrade(string student, int assessment, short grade) {
}
// overload
void course::changeGrade(string student, tuple<short, short, short, short> grades) {
}
