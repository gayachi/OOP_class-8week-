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
Person::Person() :identity(0)//:�� ����
{
}
//Constructor with parameters
Person::Person(long id) : identity(id)//��� �̴ϼȶ�����(member initialize)class person�ȿ� idendtity������ id�� ������ initialize�����ִ°�
{ //���� ���� �ȵǳ�?
//�� �Ǵ°ǵ�
}
//Copy constructor read only
Person::Person(const Person& person) : identity(person.identity)
{//default?explicit?
}
//Destructor
Person::~Person()
{
	cout << "Destructor Person_" << identity << endl;//�Ҹ� ������ �˱����� ������� ��µǴ� �ڵ带 �Է� Debuging code
}
/*
* setlid function
*/
void Person::setid(long id)
{
	identity = id;
	assert(identity >= 100000000 && identity <= 999999999);//assert�� ���� ����� �ڵ� ��ȣ���� ������ ������ ��� assert error�� �ɸ��� �ȴ�.
}
/*
* getid function
*/
long Person::getid() const
{
	return identity;//identity�� ����ϱ� ���� �ڵ� ���� �ʿ��ϴٸ� �߰����� ������ ���� �� �ִ�.
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
	Student::setid(id);//�׳� setid�� ��ϵȰ� ���°ͺ��� �ξ� �����ϰڴ�
	Student::setGPA(0.0);
}
//Constructor with gpa parameter
Student::Student(double x) : gpa(x)
{
	assert(gpa >= 0 && gpa <= 4.5);
}
//Copy constructor
Student::Student(const Student& student) : gpa(student.gpa)/*���ڱ� ��Ʃ��Ʈ�� �ֺθ��°ǵ� �� ���� 
member initialize�ϸ鼭 copy constroctor�̱� ������ copy �ϴ� class������ member�� �ҷ� initialize�ϴ°�*/
{
}
Student::~Student()//���α׷��� ����Ǿ��µ� ������ü�� ����
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
	cout << "Student_first GPA:" << student_first.getGPA() << endl;//endl�� ��������

	Student student_second(987654321L);//�ڸ����� �޶����ٰ� ������ ����? ��?
	cout << "Student_second ID:" << student_second.getid() << endl;
	cout << "Student_second GPA:" << student_second.getGPA() << endl;

	Student& student_third(student_second);
	cout << "Student_third ID:" << student_third.getid() << endl;
	cout << "Student_third GPA:" << student_third.getGPA() << endl;

	return 0;
	//�������� �����Ǵµ� stack���� LIFO
}