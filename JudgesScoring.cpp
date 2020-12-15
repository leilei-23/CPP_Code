#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

//创建Person类，包含姓名，以及成绩
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};

//创建5名选手函数
void creatPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		int score = 0;

		Person p(name, score);
		v.push_back(p);
	}
}

//给五名选手打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//将评委的分数放入deque容器中
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		/*cout << "姓名： " << (*it).m_Name << "\t分数：" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;*/
		//排序，去掉最高分和最低分
		sort(d.begin(), d.end());
		d.pop_front();
		d.pop_back();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / 8;
		(*it).m_Score = avg;
	}
}
void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名： " << (*it).m_Name << "分数： " << (*it).m_Score << endl;
	}
}
int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//1、创建5名选手
	vector<Person>v;
	creatPerson(v);
	
	//测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名: " << (*it).m_Name << "\t分数: " << (*it).m_Score << endl;
	//}
	//2、给5名选手打分
	setScore(v);
	//3、显示最后得分
	showScore(v);

	system("pause");
	return 0;
}
