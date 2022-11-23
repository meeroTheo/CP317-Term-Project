#pragma once
#include "course.h"
#include "student.h"
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

class fileWork{
private:
    fileWork(){}
public:
    /*
     * Description:
     *    Reads course file and uploads student relevant data into studentMap and course relevant data into courseMap.
     *
     * Parameters:
     *         courseMap: a map of course objects
     *         studentMap: a map of student objects
     *         readCourse: the file that is being read (ifstream)
     * returns:
     *         void
     * side effects:
     *         modifies courseMap and studentMap
     */
    static void readCourseFile(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap, ifstream &readCourse);
    
    /*
     * Description:
     *    Reads student file and uploads student relevant data into studentMap.
     *
     * Parameters:
     *         studentMap: a map of student objects
     *         readName: the file that is being read (ifstream)
     * returns:
     *         void
     * side effects:
     *         modifies studentMap
     */
    static void readNameFile(unordered_map<string, student> &studentMap, ifstream &readName);

    /*
     * Description:
     *    Writes data into myFile in the format [StudentID, Student Name, Course Code, Final Grade]
     *
     * Parameters:
     *         courseMap: a map of course objects
     *         studentMap: a map of student objects
     *         myFile: the file that is being written (ofstream)
     * returns:
     *         void
     * side effects:
     *         writes myFile
     */
    static void writeOutput(unordered_map<string, course> &courseMap, unordered_map<string, student> &studentMap, ofstream &myfile);
};