#include "course.h"

course::course() : courseCode(" "), cStudents({{" ", make_tuple((short)0, (short)0, (short)0, (short)0)}}){};
course::course(string code, string id, tuple<short, short, short, short> grades) : courseCode(code) {
    cStudents[id] = grades;
}
float course::calFinal(string id) {
    /*
    calFinal:
    Calculates the final grade a student given their id and
    returns a float which is the final grade.
    */
    return 0.0;
}
string course::getCourseCode() {
    return courseCode;
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
