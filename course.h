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
    float calFinal();
    string getCourseCode();
    void addStudent(string student, tuple<short, short, short, short> grades);
    void deleteStudent(string student);
    void changeGrade(string student, int assessment, short grade);
    void changeGrade(string student, vector<int> assessment, tuple<short, short, short, short> grade);
};