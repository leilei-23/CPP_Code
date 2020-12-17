#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <ctime>

//创建部门的宏
#define CEHUA 0;
#define SHEJI 1;
#define YANFA 2;

//创建员工类
class Worker
{
public:
	string name;
	int m_Salary;
};

//创建员工函数
void creatWorker(vector<Worker>&v)
{
	string nameSeed = "ABCDEFGHIG";
	for (int i = 0; i < 10; i++)
	{
		Worker w;

		int salary = rand() % 10001 + 10000;
		string worker_name = "员工";
		worker_name += nameSeed[i];
		w.name = worker_name;
		w.m_Salary = salary;
		v.push_back(w);
	}
}

//将员工进行分组函数
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int group = rand() % 3;  //0,1,2
		m.insert(make_pair(group, *it));
	}
}

//分组显示员工函数
void PrintWorker(multimap<int, Worker>& m)
{
	cout << "策划部门： " << endl;

	multimap<int, Worker>::iterator pos = m.find(0);
	int num = m.count(0);
	int index = 0;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "姓名： " << (*pos).second.name << "\t工资： " << pos->second.m_Salary << endl;
	}

	cout << "-----------------------------" << endl;
	cout << "设计部门： " << endl;

	pos = m.find(1);
	num = m.count(1);
	index = 0;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "姓名： " << (*pos).second.name << "\t工资： " << pos->second.m_Salary << endl;
	}

	cout << "-----------------------------" << endl;
	cout << "研发部门： " << endl;

	pos = m.find(2);
	num = m.count(2);
	index = 0;
	for (; pos != m.end() && index < num; pos++, index++)
	{
		cout << "姓名： " << (*pos).second.name << "\t工资： " << pos->second.m_Salary << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));

	vector<Worker>vWorker;
	multimap<int, Worker>mWorker;
	
	//创建员工
	creatWorker(vWorker);

	//将员工进行分组
	setGroup(vWorker, mWorker);

	//分组显示员工
	PrintWorker(mWorker);

	//验证
	/*for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		cout << "姓名： " << it->name << "\t工资： " << it->m_Salary << endl;
	}*/

	system("pause");
	return 0;
}
