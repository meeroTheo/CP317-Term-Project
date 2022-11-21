#include "fileWork.h"
#include <fstream>
#include <sstream>
#include <iomanip>

int main() {
    cout << "TEST:" << endl;
    unordered_map<string, course> courseMap;
    ifstream readCourse("CourseFile.txt");
    unordered_map<string, student> studentMap;
    ifstream readName("NameFile.txt");
    fileWork::readNameFile(studentMap, readName);
    cout << "TEST: DONE student" << endl;
    fileWork::readCourseFile(courseMap, studentMap, readCourse);
    readCourse.close();
    readName.close();
    ofstream myfile;
    myfile.open ("output.txt");
    cout << "TEST: DONE course" << endl;
    fileWork::writeOutput(courseMap, studentMap, myfile);
    myfile.close();
    cout << "DONE" << endl;
    return 0;
}
