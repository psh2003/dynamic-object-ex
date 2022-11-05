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
	cout << "�̸��� �Է����ּ��� : ";
	cin.getline(s_name, 20);
	cout << "�й��� �Է����ּ��� : ";
	cin >> stu->id;
	cout << "���������� �Է����ּ��� : ";
	cin >> stu->kor;
	cout << "���������� �Է����ּ��� : ";
	cin >> stu->eng;
	cout << "���������� �Է����ּ��� : ";
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
	cout << "�̸� : " << name << endl;
	cout << "�й� : " << id << endl;
	cout << "���� : " << total << endl;
	cout << "��� : " << avg << endl;
}

int main() {
	Student* A = new Student[3];
	Student* B = new Student[3];
	for (int i = 0; i < 3; i++) {
		cout << "A�� " << i+1 << "��° �л� ���� �Է�" << endl;
		Get(&A[i]);
		A[i].StdSum();
		A[i].StdAvg();
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		cout << "B�� " << i + 1 << "��° �л� ���� �Է�" << endl;
		Get(&B[i]);
		B[i].StdSum();
		B[i].StdAvg();
		cout << endl;
	}

	for (int j = 0; j < 3; j++) {
		cout << "A�� " << j+1 << "��° �л�" << endl;
		A[j].CLShow();
		cout << endl;
	}
	for (int k = 0; k < 3; k++) {
		cout << "B�� " << k + 1 << "��° �л�" << endl;
		B[k].CLShow();
		cout << endl;
	}
	return 0;
}