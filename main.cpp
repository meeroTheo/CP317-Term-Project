#include "fileWork.h"

int main() {
    cout << "TEST:" << endl;
    unordered_map<string, course> courseMap;
    unordered_map<string, student> studentMap;
    fileWork::readNameFile(studentMap);
    cout << "TEST: DONE student" << endl;
    fileWork::readCourseFile(courseMap, studentMap);
    cout << "TEST: DONE" << endl;
    return 0;
}
