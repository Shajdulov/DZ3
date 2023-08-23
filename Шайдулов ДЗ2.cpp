#include <iostream>;
#include <string>;
using namespace std;

class Teacher
{
public:
	friend class Student;g
	Teacher()
	{
		cout << "Sit down!\n";
	}
	~Teacher()
	{
		cout << "You are free!\n";
	}
private:
	void lesson_start()
	{
		cout << "Stand up! \n";
	}
};

class Student
{
public:
	Student()
	{
		group = 0;
		name = "NoName Student.";
		chislennost++;
		cout << "Student without name and group... Plak...\n";
	}
	Student(int group_, string name_)
	{
		group = group_;
		name = name_;
		chislennost++;
		cout << "Student with name " << name << " and group " << group << "!\n";
	}
	Student(const Student& st)
	{
		group = st.group;
		name = st.name;
		chislennost++;
		cout << "Student bliznec of student " << st.name << " from " << st.group << "!\n";
	}
	~Student()	
	{
		chislennost--;
		cout << "Student killer... Or destructor... \n";
	}
	void set_group(int group_)
	{
		if (group != 0)
		{
			group = group_;
		}
	}
	void set_name(string name_)
	{
		name = name_;
	}
	int get_group()
	{
		return group;
	}
	string get_name()
	{
		return name;
	}
	static int get_chislennost()
	{
		return chislennost;
	}
	void changegroup()
	{
		this->group++;
		this->name;
		cout << "Student " << this->name << " has a new group " << this->group << ". That`s great! \n";
	}
	void student_sitting(Teacher& te)
	{
		cout << "Student sat... \n";
		te.lesson_start();
		cout << "Student stood up! \n";
	}
private:
	static int chislennost;
	int group;
	string name;
};

int Student::chislennost;

int main() 
{
	Student st1;
	Student st2(1, "Tanya");
	Student st3 = st2;
	cout << "Chislennost students is " << Student::get_chislennost << '\n';
	st1.changegroup();
	st3.changegroup();
	st1.set_group(2);
	st1.set_name("Sanya");
	cout << st1.get_name() << " in group " << st1.get_group() << ".\n";
	cout << st2.get_name() << " in group " << st2.get_group() << ".\n";
	cout << st3.get_name() << " in group " << st3.get_group() << ".\n";
	Teacher te;
	st1.student_sitting(te);
}