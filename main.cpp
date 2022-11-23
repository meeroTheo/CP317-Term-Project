#include "fileWork.h"


int main() {
    unordered_map<string, course> courseMap;
    unordered_map<string, student> studentMap;
    ifstream readName("NameFile.txt");
    fileWork::readNameFile(studentMap, readName);
    readName.close();
    ifstream readCourse("CourseFile.txt");
    fileWork::readCourseFile(courseMap, studentMap, readCourse);
    readCourse.close();
    ofstream myfile;
    myfile.open("output.txt");
    fileWork::writeOutput(courseMap, studentMap, myfile);
    myfile.close();
    return 0;
}
