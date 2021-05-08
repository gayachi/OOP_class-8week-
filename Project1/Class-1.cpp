/****
Person and Student(inherit)
****/
//Types of Class methods
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
/*
* Person class defination
*/
class Person
{
private:
	long identity;
public:
	Person();
	Person(long id);
	~Person();//destroctor
	Person(const Person& person);
	void setid(long identity);//accessor
	long getid() const;//mutators
};

//Constructor
Person::Person() :identity(0)//:은 뭔데
{
}
//Constructor with parameters
Person::Person(long id) : identity(id)//멤버 이니셜라이즈(member initialize)class person안에 idendtity변수를 id의 값으로 initialize시켜주는것
{ //직접 들어가면 안되냐?
//왜 되는건데
}
//Copy constructor read only
Person::Person(const Person& person) : identity(person.identity)
{//default?explicit?
}
//Destructor
Person::~Person()
{
	cout << "Destructor Person_" << identity << endl;//소멸 순서를 알기위해 순서대로 출력되는 코드를 입력 Debuging code
}
/*
* setlid function
*/
void Person::setid(long id)
{
	identity = id;
	assert(identity >= 100000000 && identity <= 999999999);//assert는 에러 검출용 코드 괄호안의 명제가 거짓일 경우 assert error가 걸리게 된다.
}
/*
* getid function
*/
long Person::getid() const
{
	return identity;//identity를 사용하기 위한 코드 만일 필요하다면 추가적인 변형을 가할 수 있다.
}
/*
* Student Class Definition
*/
class Student : public Person
{
private:
	double gpa;
public:
	Student();
	Student(long id);
	Student(double x);
	Student(const Student& student);
	~Student();
	//long getid();
	void setGPA(double gpa);
	double getGPA() const;
};
//Constructor with default GPA value
Student::Student() :gpa(3.0)
{

}
//Constructor with ID parameter
Student::Student(long id)
{
	Student::setid(id);//그냥 setid에 기록된걸 쓰는것보다 훨씬 안전하겠다
	Student::setGPA(0.0);
}
//Constructor with gpa parameter
Student::Student(double x) : gpa(x)
{
	assert(gpa >= 0 && gpa <= 4.5);
}
//Copy constructor
Student::Student(const Student& student) : gpa(student.gpa)/*갑자기 스튜던트를 왜부르는건데 왜 와이 
member initialize하면서 copy constroctor이기 떄문에 copy 하는 class에서의 member를 불러 initialize하는것*/
{
}
Student::~Student()//프로그램이 종료되었는데 정적개체가 존재
{
	cout << "Destructor Student_" << getid() << endl;
}
//setGPA fuction
void Student::setGPA(double gp) {
	gpa = gp;
	assert(gpa >= 0 && gpa <= 4.5);
}
//getGPA function
double Student::getGPA() const
{
	return gpa;
}
int main() {
	//instantiation of Person Object
	Person person_first;
	person_first.setid(111111111L);
	cout << "-------Person--------" << endl;
	cout << "Person_first ID:" << person_first.getid();
	cout << endl << endl;
	//Instantiation of Student Object
	cout << "--------Student--------" << endl;
	Student student_first;
	student_first.setid(123456789L);
	student_first.setGPA(3.9);
	cout << "Student_first ID:" << student_first.getid() << endl;
	cout << "Student_first GPA:" << student_first.getGPA() << endl;//endl이 뭐였더라

	Student student_second(987654321L);//자릿수가 달라졌다고 오류가 났다? 왜?
	cout << "Student_second ID:" << student_second.getid() << endl;
	cout << "Student_second GPA:" << student_second.getGPA() << endl;

	Student& student_third(student_second);
	cout << "Student_third ID:" << student_third.getid() << endl;
	cout << "Student_third GPA:" << student_third.getGPA() << endl;

	return 0;
	//역순으로 해제되는데 stack형식 LIFO
}