#include<string>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

//Final project by Diana Efimova: grade counter for this course.
//The program asks how many students there are in class and conserning the answer gives same amount of forms with studentd' information.
//In the end it inprints filled forms with calculating of teh final grade and gives a user a choice how to sort the lists.
using namespace std;
using std::cout; using std::endl;
using std::string; using std::vector;

struct Student {
	std::string name;
	std::string surname;
	double amount_exercises;
	std::string student_number;
	int final_assignment;
	double final_grade;
	int final_grade_rounded;
};


void printVector(vector<Student>vec) {  // prints out filled lists

	for (Student& i : vec) {
		i.final_grade = i.amount_exercises * 0.6 + i.final_assignment * 0.4; // formula for the final grade
		i.final_grade_rounded = i.amount_exercises * 0.6 + i.final_assignment * 0.4; // formula for inprinted rounded final grade
		cout << endl << "Student's name: " << i.name << " " << i.surname;
		cout << endl << i.name << "'s number:" << i.student_number;
		cout << endl << i.name << "'s amount of accepted weekly exercises:: " << i.amount_exercises;
		cout << endl << i.name << "'s grade for the final assignment: " << i.final_assignment;
		cout << endl << i.name << "'s final grade: " << i.final_grade << " = " << i.final_grade_rounded;

	}
}

void bubbleSort(vector<Student>& vec, int option) {  // introducing sorting algorithm
	if (option == 1) {                             // option #1 sorts by final_grade
		for (size_t i = 0; i < vec.size() - 1; ++i) {
			for (size_t j = 0; j < vec.size() - i - 1; ++j) {
				if (vec.at(j).final_grade > vec.at(j + 1).final_grade)
					std::swap(vec.at(j), vec.at(j + 1));
			}
		}
	}
	else if (option == 2) {                   // option #2 sorts by name
		for (size_t i = 0; i < vec.size() - 1; ++i) {
			for (size_t j = 0; j < vec.size() - i - 1; ++j) {
				if (vec.at(j).name > vec.at(j + 1).name)
					std::swap(vec.at(j), vec.at(j + 1));
			}
		}
	}
}


int main()
{
	int cases;
	cout << "How many students are at class: ";
	cin >> cases;  // identifies how many lists will be shown
	int option;  // variable fot sorting algorithm

	vector<Student> class1;
	for (int i = 0; i < cases; i++) {
		class1.push_back(Student());
		cout << "Form #" << i + 1 << ": \n";
		cout << "Student's name: \n";
		cout << "EXAMPLE: Diana Efimova \n";
		cin >> class1[i].name;
		cin >> class1[i].surname;
		cout << "Student's number: ";
		cin >> class1[i].student_number;
		cout << "Amount of accepted weekly exercises: ";
		cin >> class1[i].amount_exercises;
		cout << "Grade for the final assignment: ";
		cin >> class1[i].final_assignment;
	}
	printVector(class1);
	cout << "\n";
	cout << "How would you like to sort students lists? \n";
	cout << "Press 1 if you want to sort by grade (from smallest to biggest); if you want to sort by names press 2:";
	cin >> option;
	cout << "\n";
	bubbleSort(class1, option);
	cout << "Here is sorted information about your students:" << endl;
	printVector(class1);

	return 0;
}



