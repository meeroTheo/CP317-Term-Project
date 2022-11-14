#include "course.h"
#include "student.h"
#include <fstream>
#include <sstream>

void readCourseFile(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap) {
    ifstream readCourse("CourseFile.txt");
    string my_str;
    vector<string> result;
    // read each line in file
    while (getline(readCourse, my_str)) {
        // stream to get string of file
        stringstream s_stream(my_str);
        while (s_stream.good()) {
            string substr;
            // split commas and remove spaces at front of delimited strings
            getline(s_stream, substr, ',');
            substr.erase(0, substr.find_first_not_of(' '));
            result.push_back(substr);
        }
        // make tuple of short cast marks
        tuple<short, short, short, short> tempTuple;
        tempTuple = make_tuple((short)stoll(result[2]), (short)stoll(result[3]),
                               (short)stoll(result[4]), (short)stoll(result[5]));

        // create and insert new course or existing data from data obtained
        bool found = false;
        if (courseMap.find(result[1]) != courseMap.end()) {        // found
            courseMap[result[1]].addStudent(result[0], tempTuple); // add student and grades to course object
            studentMap[result[0]].addCourse(courseMap[result[1]]); // add course to student class
        } else {
            course tempC(result[1], result[0], tempTuple);
            courseMap[result[1]] = tempC;                          // add course to courseMap
            studentMap[result[0]].addCourse(courseMap[result[1]]); // add course to student class
        }
        result.clear();
    }

    readCourse.close();
}

void readNameFile(unordered_map<string, student> &studentMap) {
    string::size_type sz = 0;
    ifstream readName("NameFile.txt");
    string my_str;
    vector<string> result;
    // read each line in file
    while (getline(readName, my_str)) {
        // stream to get string of file
        stringstream s_stream(my_str);
        while (s_stream.good()) {
            string substr;
            // split commas and remove spaces at front of delimited strings
            getline(s_stream, substr, ',');
            substr.erase(0, substr.find_first_not_of(' '));
            result.push_back(substr);
        }

        // if student object not already created, create
        bool found = false;
        if (studentMap.find(result[0]) == studentMap.end()) {
            student tempS(result[1], result[0]);
            studentMap[result[0]] = tempS;
        }
        result.clear();
    }
    readName.close();
}
int main() {

    unordered_map<string, course> courseMap;
    unordered_map<string, student> studentMap;
    readNameFile(studentMap);
    readCourseFile(courseMap, studentMap);
    return 0;
}
