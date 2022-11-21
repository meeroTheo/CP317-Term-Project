#pragma once
#include <iostream>
#include <vector>

using namespace std;

class student {
private:
    string name;
    string id;
    vector<string> courses;

public:
    student();

    /*
     * Description:
     *    Initializes student object containing name and ID
     *
     * Parameters:
     *         studentName: the student's full name (string)
     *         studentID: the student's numerical id (string)
     * returns:
     *         returns student object
     */
    student(string studentName, string studentID);

    /*
     * Description:
     *    Initializes student object containing name, ID, and course
     *
     * Parameters:
     *         studentName: the student's full name (string)
     *         studentID: the student's numerical id (string)
     *         course: a course code (string)
     * returns:
     *         returns student object
     */
    student(string studentName, string studentID, string course);
    
    /*
     * Description:
     *    Gets student's numeric ID
     *
     * returns:
     *         returns student's ID (string)
     */
    string getID();

    /*
     * Description:
     *    Gets student's full name
     *
     * returns:
     *         returns student's full name (string)
     */
    string getName();

    /*
     * Description:
     *    Gets student's course list
     *
     * returns:
     *         returns vector list of student's courses (vector<string>)
     */
    vector<string> getCourses();

    /*
     * Description:
     *    Adds a course to student's course list.
     *
     * Parameters:
     *         course: the course code (string)
     * returns:
     *         void
     * side effects:
     *         modifies courses
     */
    void addCourse(string course);
    
    /*
     * Description:
     *    Adds a set of courses to student's course list.
     *
     * Parameters:
     *         courseList: a set of multiple course codes (vector<string>)
     * returns:
     *         void
     * side effects:
     *         modifies courses
     */
    void addCourse(vector<string> courseList);
};
