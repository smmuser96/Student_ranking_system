#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>

using namespace std;
 
// calculate total marks of the student
int TotalMark(int m1, int m2, int m3) {
	return m1 + m2 + m3;
}

// function for  collect student marks
	// Bio Students marks
void BioStudentMark(vector<vector<int>>& Student, vector<vector<int>>& Section, vector<vector<int>>& Stream, vector<int>& vec_3) {
	int student_id;
	int m1;
	int m2;
	int m3;
	int total;

	vector<int> vec_1;
	vector<int> vec_2;
	
	cout << "Enter Student ID : ";
	cin >> student_id;
	vec_1.push_back(student_id);
	vec_2.push_back(student_id);

	cout << "Enter Marks :" << endl;
	cout << "	Bio       = ";
	cin >> m1;
	if (m1 < 0 || m1 > 100) {
		cout << "Invalid mark. Enter correct mark." << endl;
		cout << "	Bio       = ";
		cin >> m1;
	}
	vec_2.push_back(m1);

	cout << "	Physics   = ";
	cin >> m2;
	if (m2 < 0 || m2 > 100) {
		cout << "Invalid mark. Enter correct mark." << endl;
		cout << "	Physics   = ";
		cin >> m2;
	}
	vec_2.push_back(m2);

	cout << "	Chemistry = ";
	cin >> m3;
	if (m3 < 0 || m3 > 100) {
		cout << "Invalid mark. Enter correct mark." << endl;
		cout << "	Chemistry = ";
		cin >> m3;
	}
	vec_2.push_back(m3);

	total = TotalMark(m1, m2, m3);

	vec_1.push_back(total);
	vec_2.push_back(total);

	Student.push_back(vec_1);
	Section.push_back(vec_2);
	Stream.push_back(vec_2);

	vec_3 = vec_1;
	vec_1.clear();
	vec_2.clear();
}
	// Math Students marks
void MathStudentMark(vector<vector<int>>& Student, vector<vector<int>>& Section, vector<vector<int>>& Stream, vector<int>& vec_3) {
	int student_id;
	int m1;
	int m2;
	int m3;
	int total;

	vector<int> vec_1;
	vector<int> vec_2;

	cout << "Enter Student ID : ";
	cin >> student_id;
	vec_1.push_back(student_id);
	vec_2.push_back(student_id);

	cout << "Enter Marks :" << endl;
	cout << "	Math       = ";
	cin >> m1;
	if (m1 < 0 || m1 > 100) {
		cout << "Invalid mark. Enter correct mark." << endl;
		cout << "	Math       = ";
		cin >> m1;
	}
	vec_2.push_back(m1);

	cout << "	Physics   = ";
	cin >> m2;
	if (m2 < 0 || m2 > 100) {
		cout << "Invalid mark. Enter correct mark." << endl;
		cout << "	Physics   = ";
		cin >> m2;
	}
	vec_2.push_back(m2);

	cout << "	Chemistry = ";
	cin >> m3;
	if (m3 < 0 || m3 > 100) {
		cout << "Invalid mark. Enter correct mark." << endl;
		cout << "	Chemistry = ";
		cin >> m3;
	}
	vec_2.push_back(m3);

	total = TotalMark(m1, m2, m3);

	vec_1.push_back(total);
	vec_2.push_back(total);

	Student.push_back(vec_1);
	Section.push_back(vec_2);
	Stream.push_back(vec_2);

	vec_3 = vec_1;
	vec_1.clear();
	vec_2.clear();
}


// sort 2D vector in descending order
	// sort considering 2nd column
bool SortCol(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] > v2[1];
}
	// sort considering 5th column
bool SortCol1(const vector<int>& v1, const vector<int>& v2) {
	return v1[4] > v2[4];
}

// find school rank of student
void SchoolRank(vector<vector<int>>& vect, int student_id) {
	for (int i = 0; i < vect.size(); i++) {
		if (student_id == vect[i][0]) {
			cout << " Your School rank  : " << i + 1 << endl;
		}
	}
}

// find class rank of student
void ClassRank(vector<vector<int>>& vect, int student_id) {
	for (int i = 0; i < vect.size(); i++) {
		if (student_id == vect[i][0]) {
			cout << " \n Your Class rank   : " << i + 1 << endl;
		}
	}
}

// Marks list 
void MarkList(vector<vector<int>>& vect) {
	for (int i = 0; i < vect.size(); i++) {
		for (int j = 0; j < vect[i].size(); j++) {
			cout << vect[i][j] << " ";
		}
		cout << endl;
	}
}

// Grade students marks
void Grade(int m) {
	if (75 <= m && m <= 100) {
		cout << " A ";
	}
	else if (65 <= m && m < 75) {
		cout << " B ";
	}
	else if (50 <= m && m < 65) {
		cout << " C ";
	}
	else if (35 <= m && m < 50) {
		cout << " S ";
	}
	else if (0 <= m && m < 35) {
		cout << " F ";
	}
}

// print final result as a grade
void FinalResults(vector<vector<int>>& vect, int sid) {

	int m1;
	int m2;
	int m3;
	int index;
	for (int i = 0; i < vect.size(); i++) {
		if (sid == vect[i][0]) {
			index = i;
		}
	}

	m1 = vect[index][1];
	m2 = vect[index][2];
	m3 = vect[index][3];

	cout << " Your Final Marks  : " << m1 << " " << m2 << " " << m3 << endl;
	
	cout << " Your Final Result : ";
	Grade(m1);
	Grade(m2);
	Grade(m3);
	cout << endl;
}

// CALCULATE Z-SCORE
	// calculate mean
double Mean(vector<vector<int>>& vect, int col) {
	double total = 0;
	for (int i = 0; i < vect.size(); i++) {
		total += vect[i][col];
	}
	return total / vect.size();
}
	// calculate standard deviation
double SD(vector<vector<int>>& vect, int col) {
	double mean = Mean(vect, col);
	double a = 0;

	for (int i = 0; i < vect.size(); i++) {
		a += pow((vect[i][col] - mean), 2);
	}

	return pow((a / (vect.size() - 1)), 0.5);
}
	// Z-Score per subject
double Z_Score(vector<vector<int>>& vect, int sid, int col) {

	int mark = 0;
	double ZScore;

	for (int i = 0; i < vect.size(); i++) {
		if (sid == vect[i][0]) {
			mark = vect[i][col];
		}
	}

	ZScore = (mark - Mean(vect,col)) / (SD(vect,col));

	return ZScore;
}


// main fuction
int main() {

	vector<vector<int>> Student;
	vector<vector<int>> Bio_section;
	vector<vector<int>> Math_section;
	vector<vector<int>> Bio_1;
	vector<vector<int>> Bio_2;
	vector<vector<int>> Bio_3;
	vector<vector<int>> Math_1;
	vector<vector<int>> Math_2;
	vector<vector<int>> Math_3;
	vector<vector<int>> Math_4;
	vector<vector<int>> Math_5;

	vector<int> vec_3;

	int stream;
	int class_num;
	int no_of_students;
	int student_id;

	char ch;
	
	cout << "\n\t\t This an application to get the school and class rank of A/L students of a school in science section based on term test results.\n" << endl;
	system("pause");
	system("CLS");

	cout << "\nEnter the No of Students : ";
	cin >> no_of_students;

	for (int i = 0; i < no_of_students; i++) {
		cout << " \n 1.Bio \n 2.Math \n Select Students' Stream : ";
		cin >> stream;
		while (stream != 1 && stream != 2) {
			system("CLS");
			cout << " Invalid input. Please choose correct stream. " << endl;
			cout << " 1.Bio \n 2.Math \n Select Students' Stream : ";
			cin >> stream;
		}

		if (stream == 1) {
			cout << "\n 1.Bio_1 \n 2.Bio_2 \n 3.Bio_3\n Select Students' Class : ";
			cin >> class_num;
			if (class_num == 1) {
				BioStudentMark(Student, Bio_section, Bio_1, vec_3);
			}

			else if (class_num == 2) {
				BioStudentMark(Student, Bio_section, Bio_2, vec_3);
			}

			else if (class_num == 3) {
				BioStudentMark(Student, Bio_section, Bio_3, vec_3);
			}
		}

		if (stream == 2) {
			cout << "\n 1.Math_1 \n 2.Math_2 \n 3.Math_3\n 4.Math_4\n 5.Math_5\n Select Students' Class : ";
			cin >> class_num;
			if (class_num == 1) {
				MathStudentMark(Student, Math_section, Math_1, vec_3);
			}

			else if (class_num == 2) {
				MathStudentMark(Student, Math_section, Math_2, vec_3);
			}

			else if (class_num == 3) {
				MathStudentMark(Student, Math_section, Math_3, vec_3);
			}

			else if (class_num == 4) {
				MathStudentMark(Student, Math_section, Math_4, vec_3);
			}

			else if (class_num == 5) {
				MathStudentMark(Student, Math_section, Math_5, vec_3);
			}
		}
		system("pause");
		system("CLS");

		if (i + 1 == 1) {
			cout << "\nYou successfully entered records of " << 1 << " student." << endl;
			cout << "Last entered Student ID = " << vec_3[0] << endl;
		}
		else {
			cout << "\nYou successfully entered records of " << (i + 1) << " students." << endl;
			cout << "Last entered Student ID = " << vec_3[0] << endl;
		}
		vec_3.clear();
	}
	
	system("pause");
	system("CLS");
	
//Sort vectors in descending order 
	sort(Student.begin(), Student.end(), SortCol);
	sort(Bio_1.begin(), Bio_1.end(), SortCol1);
	sort(Bio_2.begin(), Bio_2.end(), SortCol1);
	sort(Bio_3.begin(), Bio_3.end(), SortCol1);
	sort(Math_1.begin(), Math_1.end(), SortCol1);
	sort(Math_2.begin(), Math_2.end(), SortCol1);
	sort(Math_3.begin(), Math_3.end(), SortCol1);
	sort(Math_4.begin(), Math_4.end(), SortCol1);
	sort(Math_5.begin(), Math_5.end(), SortCol1);


	MarkList(Student);

// Final Results output
	ch = 'c';

	while (ch != 'e') {

		cout << " ***** Find your result ***** " << endl;
		cout << " \nEnter your Student ID : ";
		cin >> student_id;

		cout << "\n 1.Bio \n 2.Math \n Select Your Stream : ";
		cin >> stream;

		if (stream == 1) {
			cout << "\n 1.Bio_1 \n 2.Bio_2 \n 3.Bio_3 \n Select Your Class : ";
			cin >> class_num;
		}
		else if (stream == 2) {
			cout << "\n 4.Math_1 \n 5.Math_2 \n 6.Math_3\n 7.Math_4\n 8.Math_5\n Select Your Class : ";
			cin >> class_num;
		}
		cout << endl;

		switch (class_num)
		{
		case 1:FinalResults(Bio_1, student_id); ClassRank(Bio_1, student_id); break;
		case 2:FinalResults(Bio_2, student_id); ClassRank(Bio_2, student_id); break;
		case 3:FinalResults(Bio_3, student_id); ClassRank(Bio_3, student_id); break;
		case 4:FinalResults(Math_1, student_id); ClassRank(Math_1, student_id); break;
		case 5:FinalResults(Math_2, student_id); ClassRank(Math_2, student_id); break;
		case 6:FinalResults(Math_3, student_id); ClassRank(Math_3, student_id); break;
		case 7:FinalResults(Math_4, student_id); ClassRank(Math_4, student_id); break;
		case 8:FinalResults(Math_5, student_id); ClassRank(Math_5, student_id); break;
		default: break;
		}

		SchoolRank(Student, student_id);

		if (stream == 1) {
			double Zscore = (Z_Score(Bio_section, student_id, 1) + Z_Score(Bio_section, student_id, 2) + Z_Score(Bio_section, student_id, 3)) / 3;
			cout << " Your Z-Score      : " << fixed << setprecision(3) << Zscore << endl;
		}
		else if (stream == 2) {
			double Zscore = (Z_Score(Math_section, student_id, 1) + Z_Score(Math_section, student_id, 2) + Z_Score(Math_section, student_id, 3)) / 3;
			cout << " Your Z-Score      : " << Zscore << endl;
		}
		

		system("pause");
		system("CLS");

		cout << " \n(c). countinue \n(e). exit \n Do you want to countinue or exit : ";
		cin >> ch;

		system("pause");
		system("CLS");
	}
	
	return 0;
}


