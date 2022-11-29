#include "fileWork.h"

void fileWork::readCourseFile(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap, ifstream &readCourse) {
    string my_str, substr, lineCount;
    vector<string> result;
    int count = 0;
    // read each line in file
    while (getline(readCourse, my_str)) {
        // stream to get string of file
        stringstream s_stream(my_str);

        // execute until end of line
        while (s_stream.good()) {
            // split commas and remove spaces at front of delimited strings
            getline(s_stream, substr, ',');
            substr.erase(0, substr.find_first_not_of(' '));
            // add to a list
            result.push_back(substr);
        }
        //error handling
        count++;
        if(!isdigit(result[0][0])){ //missing ID
            my_str += " on line " + to_string(count);
            throw (MyException("Incorrect input in courseFile.txt (missing ID): "+my_str, 100));
        }
        if (result.size() != 6) { // invalid inputs
            my_str += " on line " + to_string(count);
            throw(MyException("Incorrect input in courseFile.txt (invalid input): " + my_str, 101));
            printf("Line %d", count);
        }   //incorrect course code
        if (result[1].length() != 5 || !isalpha(result[1][0]) || !isalpha(result[1][1]) || !isdigit(result[1][2]) || !isdigit(result[1][3]) || !isdigit(result[1][4])){
            my_str += " on line " + to_string(count);
            throw (MyException("Incorrect course code in courseFile.txt: "+result[1], 102));
        }   //incorrect grade
        if (stoi(result[2]) > 100 || stoi(result[3]) > 100 || stoi(result[4]) > 100 || stoi(result[5]) > 100 ){
            my_str += " on line " + to_string(count);
            throw (MyException("Incorrect grade in courseFile.txt (too large): "+my_str.substr(19,14), 103));
        }
        // make tuple of short cast marks
        tuple<short, short, short, short> tempTuple;
        tempTuple = make_tuple((short)stoi(result[2]), (short)stoi(result[3]),
                               (short)stoi(result[4]), (short)stoi(result[5]));
        // create and insert new course or existing data from data obtained
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
    string my_str,substr;
    vector<string> result;
    // read each line in file
    while (getline(readName, my_str)) {
        // stream to get string of file
        stringstream s_stream(my_str);

        // execute until end of line
        while (s_stream.good()) {
            // split commas and remove spaces at front of delimited strings
            getline(s_stream, substr, ',');
            substr.erase(0, substr.find_first_not_of(' '));
            // add to a list
            result.push_back(substr);
        }
        // error handling
        if(!isdigit(result[0][0])){ //missing ID
            throw (MyException("Incorrect input in courseFile.txt (missing ID): "+my_str, 200));
        }
        if(!isalpha(result[1][0])){ //missing name
            throw (MyException("Incorrect input in courseFile.txt (missing name): "+my_str, 201));
        }
        if (result.size() != 2) { // invalid inputs
            throw (MyException("Incorrect input in NameFile.txt (missing input): "+my_str, 202));
        } 
        // if student object not already created, create
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
            myfile << id << ", " << s.getName() << ", " << code << ", " << courseMap[code].getGrades(id) << fixed << setprecision(1) << courseMap[code].calFinal(id) << "\n";
        }
    }
}
