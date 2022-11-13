#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <sstream>


using namespace std;

class student {
private:
    string name;
    int id;
    vector<string> courses;
public:
    student(string studentName, int studentID, string course) : name(studentName), id(studentID)
    {
        courses.push_back(course);
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    void addCourse(string course){
        courses.push_back(course);
    }
    //overload
    void addCourse(vector<string> courseV){

    }
};

class course {
private:
    string courseCode;
    unordered_map<int, tuple<short, short, short, short>> cStudents;
public:
    course(string code, int id, tuple<short, short, short, short> grades) : courseCode(code)
    {
        cStudents[id]=grades;
    }
    float calFinal(){

    }
    string getCourseCode() {
		return courseCode; //maybe return a copy with get stuff?
	}
	void addStudent(int student, tuple<short, short, short, short> grades) {

	}
    void deleteStudent(int student){

    }
    void changeGrade(int student, int assessment, short grade){

    }
    //overload
    void changeGrade(int student, vector<int> assessment, tuple<short> grade){

    }

};

int main() {

	//course list reading
	vector<course> courselist;
	ifstream MyReadFile("CourseFile.txt");
	string my_str;
	//read each line in file
	while (getline(MyReadFile, my_str)) {
		vector<string> result;
		//stream to get string of file
		stringstream s_stream(my_str);
		while (s_stream.good()) {
			string substr;
			//split commas and remove spaces at front of delimited strings
			getline(s_stream, substr, ',');
			substr.erase(0, substr.find_first_not_of(' '));
			result.push_back(substr);
		}
		//make tuple of short cast marks
		tuple<short, short, short, short> temptuple;
		temptuple = make_tuple((short) stoi(result[2]), (short) stoi(result[3]),
				(short) stoi(result[4]), (short) stoi(result[5]));
		//create new course from data obtained
		course latest(result[1], stoi(result[0]), temptuple);
		courselist.push_back(latest);
	}

	MyReadFile.close();
	return 0;
}
