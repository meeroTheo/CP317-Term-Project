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
    float finalGrade = 0.0;
    if (cStudents.find(id) == cStudents.end()) {
        cout << "Student not found" << endl;
    }
    // If the student is in the course
    finalGrade = (get<0>(cStudents[id]) * 0.2) + (get<1>(cStudents[id]) * 0.2) + (get<2>(cStudents[id]) * 0.2) + (get<3>(cStudents[id]) * 0.4);

    return finalGrade;
}
string course::getCourseCode() {
    return courseCode;
}
void course::addStudent(string student, tuple<short, short, short, short> grades) {
    cStudents[student] = grades;
}
void course::deleteStudent(string student) {
    cStudents.erase(student);
}
void course::changeGrade(string student, int assessment, short grade) {
    // change one grade
    switch (assessment) {
    case 1:
        get<0>(cStudents[student]) = grade; // get<0> is the first element of the tuple
        break;
    case 2:
        get<1>(cStudents[student]) = grade; // get<1> is the second element of the tuple
        break;
    case 3:
        get<2>(cStudents[student]) = grade;
        break;
    case 4:
        get<3>(cStudents[student]) = grade;
        break;
    default:
        cout << "Invalid assessment number" << endl;
        break;
    }
}
// overload
void course::changeGrade(string student, tuple<short, short, short, short> grades) {
    // change the whole tuple of grades with the new tuple

    cStudents[student] = grades;
}
