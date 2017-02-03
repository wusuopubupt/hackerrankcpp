#include <iostream>
using namespace std;

enum type {
	PROFESSOR = 1,
	STUDENT = 2
};

class Person {
public:
	Person(){};
	~Person(){};

	char name[101];
	unsigned int age;
	virtual void getdata(){};
	virtual void putdata(){};
};

class Professor : public Person {
private:
	int publications;	
	int cur_id;
	static int counter;

public:
	Professor() {
		cur_id = counter++;
	}

	void getdata() {
		scanf("%s %d %d", name, &age, &publications);	
	}

	void putdata() {
		printf("%s %d %d %d\n", name, age, publications, cur_id);	
	}

};

class Student : public Person {
private:
	int marks[6];
	int cur_id;
	static int counter;

public:
	Student() {
		cur_id = counter++;	
	}

	void getdata() {
		scanf("%s %d %d %d %d %d %d %d", name, &age, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4], &marks[5]);	
	}

	void putdata() {
		int sum_marks = 0;
		for(int i = 0; i < 6; i++) {
			sum_marks += marks[i];	
		}
		printf("%s %d %d %d\n", name, age, sum_marks, cur_id);	
	}

};

int Professor::counter = 1;
int Student::counter = 1;

int main(int argv, char** argc) {
	int n, type;
	cin >> n; // The number of object that is going to be created.
	Person *person[n];

	for(int i = 0; i < n; i++) {
		cin >> type;	
		if(PROFESSOR == type) {
			person[i] = new Professor;			
		} else {
			person[i] = new Student;	
		}
		person[i]->getdata();
	}

	for(int i = 0; i < n; i++) {
		person[i]->putdata();	
	}
	return 0;
}
