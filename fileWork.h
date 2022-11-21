#pragma once
#include "course.h"
#include "student.h"
using namespace std;

class fileWork{
private:
    fileWork(){}
public:
    static void readCourseFile(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap);
    static void readNameFile(unordered_map<string, student> &studentMap);
    static void writeOutput(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap);
};