#pragma once
#include "course.h"

class student {
private:
    string name;
    string id;
    vector<course> courses;

public:
    student();
    student(string studentName, string studentID);
    student(string studentName, string studentID, course &course);
    string getID();
    string getName();
    void addCourse(course &course);
    void addCourse(vector<course> courseV);
};