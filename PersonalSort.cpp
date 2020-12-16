#include <iostream>
using namespace std;
#include <string>
#include <list>

//创建类
class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};

//打印函数
void ListPrint(list<Person>& l)
{
	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "\t年龄： " << it->m_Age << "\t身高： " << it->m_Height << endl;
	}

}

//排序函数
bool compare(Person &p1, Person &p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}

	return p1.m_Age < p2.m_Age;
}

//开始测试
void test01()
{
	list<Person>L;

	Person p1("张三", 23, 172);
	Person p2("李四", 24, 173);
	Person p3("王五", 24, 175);
	Person p4("赵六", 25, 178);
	Person p5("张三", 24, 169);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);

	cout << "排序前： " << endl;
	ListPrint(L);

	cout << "************************" << endl;
	cout << "排序后： " << endl;

	L.sort(compare);
	ListPrint(L);
}
int main()
{
	test01();

	system("pause");
	return 0;
}
