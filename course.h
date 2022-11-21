#pragma once
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class course {
private:
    string courseCode;
    unordered_map<string, tuple<short, short, short, short>> cStudents;

public:
    course();
    course(string code, string id, tuple<short, short, short, short> grades);
     
    /*
     * Parameters:
     *         id: the student's numerical id (string)
     * returns:
     *         finalGrade: the student's overall final grade as a decimal value (float)
     * Description:
     *    Initialize finalGrade as a float of 0.0.
     *    Check if student is in course, then make finalGrade sum of weighted assessments
     *    (first 3 are worth 0.2, final is worth 0.4) and return.
     */
    float calFinal(string id);
    string getCourseCode();
    void addStudent(string student, tuple<short, short, short, short> grades);
    void deleteStudent(string student);
    void changeGrade(string student, int assessment, short grade);
    void changeGrade(string student, tuple<short, short, short, short> grades);
};
