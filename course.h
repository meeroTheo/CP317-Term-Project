#pragma once
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class course {
private:
    string courseCode;
    unordered_map<string, tuple<short, short, short, short>> cStudents;

public:
    course();
    course(string code, string id, tuple<short, short, short, short> grades);
     
    /*
     * Description:
     *    Initialize finalGrade as a float of 0.0.
     *    Check if student is in course, then make finalGrade sum of weighted assessments
     *    (first 3 are worth 0.2, final is worth 0.4) and return.
     *
     * Parameters:
     *         id: the student's numerical id (string)
     * returns:
     *         Returns the student's overall final grade as a decimal value (float)
     */
    float calFinal(string id);
    
    /*
     * Description:
     *    Obtains the course's designated course code
     *
     * returns:
     *         returns the course code for this particular course (String)
     */
    string getCourseCode();

    /*
     * Description:
     *    Obtains the grades for a student given their ID.
     *
     * Parameters:
     *         id: the student's numerical id (string)
     * returns:
     *         return the grades for the student in string form with their respective weights
     */
    string getGrades(string id);
     
    /*
     * Description:
     *    Adds student and their assessment grades into the course.
     *
     * Parameters:
     *         student: the student's numerical id (string)
     *         grades: a list of four grades, each out of 100, specific to this course (tuple)
     * returns:
     *         void
     * side effects:
     *         Adds specified student into cStudents
     */
    void addStudent(string student, tuple<short, short, short, short> grades);
    
    /*
     * Description:
     *    Erases student from course.
     *
     * Parameters:
     *         student: the student's numerical id (string)
     * returns:
     *         void
     * side effects:
     *         removes specified student from cStudents
     */
    void deleteStudent(string student);

    /*
     * Description:
     *    Changes the grade of a specific assessment for a student.
     *
     * Parameters:
     *         student: the student's numerical id (string)
     *         assessment: the position of the assessment to be changed in the tuple (1-4) (int)
     *         grade: the new grade to replace with the old grade (short)
     * returns:
     *         void
     * side effects:
     *         modifies a tuple value from a student's grades in cStudents
     */
    void changeGrade(string student, int assessment, short grade);

    /*
     * Description:
     *    Changes a student's assessment grade list
     *
     * Parameters:
     *         student: the student's numerical id (string)
     *         grades: a new list of grades to replace the student's old grades (tuple)
     * returns:
     *         void
     * side effects:
     *         modifies grades from a student in cStudents
     */
    void changeGrade(string student, tuple<short, short, short, short> grades);
};
