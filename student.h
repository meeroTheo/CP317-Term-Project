#pragma once
#include <iostream>
#include <vector>

using namespace std;

class student {
private:
    string name;
    string id;
    vector<string> courses;

public:
    student();
    student(string studentName, string studentID);
    student(string studentName, string studentID, string course);
    string getID();
    string getName();
    void addCourse(string course);
    void addCourse(vector<string> courseList);
};