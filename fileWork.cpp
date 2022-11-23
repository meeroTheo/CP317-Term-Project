#include "fileWork.h"

void fileWork::readCourseFile(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap, ifstream &readCourse) {
    string my_str;
    vector<string> result;
    // read each line in file
    while (getline(readCourse, my_str)) {
        // stream to get string of file
        stringstream s_stream(my_str);

        // execute until end of line
        while (s_stream.good()) {
            string substr;
            // split commas and remove spaces at front of delimited strings
            getline(s_stream, substr, ',');
            substr.erase(0, substr.find_first_not_of(' '));
            // add to a list
            result.push_back(substr);
        }
        if (result.size() != 6) { // skip invalid inputs
            cout << "Invalid input: CourseFile.txt" << endl;
            result.clear();
            continue;
        }
        // make tuple of short cast marks
        tuple<short, short, short, short> tempTuple;
        tempTuple = make_tuple((short)stoi(result[2]), (short)stoi(result[3]),
                               (short)stoi(result[4]), (short)stoi(result[5]));
        // create and insert new course or existing data from data obtained
        bool found = false;
        if (courseMap.find(result[1]) != courseMap.end()) {            // found (course object already exists)
            if (studentMap.find(result[0]) != studentMap.end()) {      // if student object exists
                courseMap[result[1]].addStudent(result[0], tempTuple); // add student and grades to course object
                studentMap[result[0]].addCourse(result[1]);            // add course code to student class
            }
        } else {                                                                // not found
            if (studentMap.find(result[0]) != studentMap.end()) {               // if student object exists
                courseMap[result[1]] = course(result[1], result[0], tempTuple); // add course to courseMap
                studentMap[result[0]].addCourse(result[1]);                     // add course code to student class
            }
        }
        result.clear();
    }
}

void fileWork::readNameFile(unordered_map<string, student> &studentMap, ifstream &readName) {
    string::size_type sz = 0;
    string my_str;
    vector<string> result;
    // read each line in file
    while (getline(readName, my_str)) {
        // stream to get string of file
        stringstream s_stream(my_str);

        // execute until end of line
        while (s_stream.good()) {
            string substr;
            // split commas and remove spaces at front of delimited strings
            getline(s_stream, substr, ',');
            substr.erase(0, substr.find_first_not_of(' '));
            // add to a list
            result.push_back(substr);
        }
        // skip invalid input
        if (result.size() != 2) {
            cout << "Invalid input: NameFile.txt" << endl;
            result.clear();
            continue;
        }
        // if student object not already created, create
        bool found = false;
        if (studentMap.find(result[0]) == studentMap.end())        // student object not found in map
            studentMap[result[0]] = student(result[1], result[0]); // put student in their place in student map, according to ID
        result.clear();
    }
}

void fileWork::writeOutput(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap, ofstream &myfile) {

    // loop through each entry in the studentMap
    for (auto &[id, s] : studentMap) {
        // iterate over every course the student takes
        for (string code : s.getCourses()) {
            // write Student ID, name, course code and decimal-formatted final grade to the parameter file.
            myfile << id << ", " << s.getName() << ", " << code << ", " << fixed << setprecision(1) << courseMap[code].calFinal(id) << "\n";
        }
    }
}
