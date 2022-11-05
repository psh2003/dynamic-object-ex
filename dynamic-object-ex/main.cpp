#include <iostream>
#include <cstring>
using namespace std;
class Student {
private:
	char* name;
	int id;
	int kor;
	int eng;
	int math;
	int total;
	double avg;
public:
	friend void Get(Student* stu);
	void StdSum();
	void StdAvg();
	void CLShow();
};
void Get(Student* stu) {
	char s_name[20];
	cin.clear(); cin.ignore(INT_MAX, '\n');
	cout << "이름를 입력해주세요 : ";
	cin.getline(s_name, 20);
	cout << "학번을 입력해주세요 : ";
	cin >> stu->id;
	cout << "국어점수를 입력해주세요 : ";
	cin >> stu->kor;
	cout << "영어점수를 입력해주세요 : ";
	cin >> stu->eng;
	cout << "수학점수를 입력해주세요 : ";
	cin >> stu->math;
	stu->name = new char[strlen(s_name) + 1];
	strcpy_s(stu->name, strlen(s_name) + 1, s_name);
}
void Student::StdSum() {
	total = kor + eng + math;
}
void Student::StdAvg() {
	avg = total / 3;
}
void Student::CLShow() {
	cout << "이름 : " << name << endl;
	cout << "학번 : " << id << endl;
	cout << "총점 : " << total << endl;
	cout << "평균 : " << avg << endl;
}

int main() {
	Student* A = new Student[3];
	Student* B = new Student[3];
	for (int i = 0; i < 3; i++) {
		cout << "A반 " << i+1 << "번째 학생 정보 입력" << endl;
		Get(&A[i]);
		A[i].StdSum();
		A[i].StdAvg();
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << "B반 " << i + 1 << "번째 학생 정보 입력" << endl;
		Get(&B[i]);
		B[i].StdSum();
		B[i].StdAvg();
		cout << endl;
	}

	for (int j = 0; j < 3; j++) {
		cout << "A반 " << j+1 << "번째 학생" << endl;
		A[j].CLShow();
		cout << endl;
	}
	for (int k = 0; k < 3; k++) {
		cout << "B반 " << k + 1 << "번째 학생" << endl;
		B[k].CLShow();
		cout << endl;
	}
	return 0;
}