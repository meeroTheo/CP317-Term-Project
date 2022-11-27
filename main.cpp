#include "fileWork.h"

int main() {
    unordered_map<string, course> courseMap;
    unordered_map<string, student> studentMap;
    try {
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
    } catch (MyException& e) {
        cout << " an exception was caught with code: " << e.getX() << " " << e.getMsg() << '\n';
    } catch (const std::exception &e) {
        std::cout << " a standard exception was caught, with message '"
                  << e.what() << "'\n";
    }
    return 0;
}
