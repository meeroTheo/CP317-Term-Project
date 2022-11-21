#include "fileWork.h"
#include <fstream>
#include <sstream>
#include <iomanip>

void fileWork::readCourseFile(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap) {
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
        tempTuple = make_tuple((short)stoi(result[2]), (short)stoi(result[3]),
                               (short)stoi(result[4]), (short)stoi(result[5]));

        // create and insert new course or existing data from data obtained
        bool found = false;
        if (courseMap.find(result[1]) != courseMap.end()) {                 // found (course object already exists)
            courseMap[result[1]].addStudent(result[0], tempTuple);          // add student and grades to course object
            studentMap[result[0]].addCourse(result[1]);                     // add course code to student class
        } else {                                                            // not found
            courseMap[result[1]] = course(result[1], result[0], tempTuple); // add course to courseMap
            studentMap[result[0]].addCourse(result[1]);                     // add course code to student class
        }
        result.clear();
    }

    readCourse.close();
}

void fileWork::readNameFile(unordered_map<string, student> &studentMap) {
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
        if (studentMap.find(result[0]) == studentMap.end()) // student object not found in map
            studentMap[result[0]] = student(result[1], result[0]);
        result.clear();
    }
    readName.close();
}

void fileWork::writeOutput(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap){
    ofstream myfile;
    myfile.open ("output.txt");
    for (auto& [id,s]: studentMap){
        for (string code: s.getCourses()){
            myfile << id << ", " << s.getName() << ", " << code << ", " << fixed << setprecision(1) << courseMap[code].calFinal(id) << "\n";
        }
    }
    myfile.close();

}