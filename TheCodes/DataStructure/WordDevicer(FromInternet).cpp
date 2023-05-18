#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>

using namespace std;
/// 预处理
#define MAX(a,b)	a>b?a:b		// 获取两个值中最大的
#define MIN(a,b)	a<b?a:b		// 获取两个值中最小的
#define ERROR_0 cerr << "Open error !!!" << endl; exit(1);	// 文件打开出错提示

int MaxLen;								// 词典中最长词的字节数
unordered_map<string, int> StrInt_Hash;	// 哈希表存储词典（便于查询）

const string ini_file = "1998-01-2003版-带音.txt";	// 词典
const string infile = "in.txt";						// 需要分词的文件
const string outfile = "out.txt";					// 分词后的文件
string project_time = "project_time.txt";			// 存储整个程序所运行的时间的文件

// 对词典进行预处理，截取出所有中文汉字
void InitText(string _infile)
{
	// 打开文件
	ifstream file_in;
	file_in.open(_infile);
	if (!file_in)
	{
		ERROR_0;
	}

	string str_tmp, str;
	int pos;
	MaxLen = 0;
	// 循环读入字符串（遇到空格刚好读出一个字符串），直到文件结束。
	// 在此过程中，记录下词典中最长词的字节数
	while (file_in >>str_tmp)
	{
		pos = str_tmp.find("/");
		str = str_tmp.substr(0,pos);
		if (str.size() > MaxLen) {
			MaxLen = str.size();
		}
		StrInt_Hash[str] = 1;
	}

	// 关闭文件
	file_in.close();
	file_in.clear();
}

/// 正想最大匹配算法
void PositiveMaxMatch(string _infile, string _outfile)
{
	// 初始化
	InitText(ini_file);

	// 打开文件
	ifstream file_in;
	ofstream file_out;
	file_in.open(_infile);
	file_out.open(_outfile);
	if (!file_in)
	{ 
		ERROR_0;
	}
	if (!file_out)
	{
		ERROR_0;
	}

	// 开始计时
	ofstream file_out_time;
	file_out_time.open(project_time);
	if (!file_out_time)
	{
		ERROR_0;
	}
	clock_t myStart, myFinish;
	double time_total;
	myStart = clock();

	/// 匹配算法
	std::ostringstream tmp;
	tmp << file_in.rdbuf();
	string text_tmp = tmp.str();

	int myBegin = 0;
	int myEnd = text_tmp.size();
	while (myBegin< myEnd)
	{
		string str;
		int num;
		// 从最大长度的哈希元素进行查找，找不到长度-1，直到找到匹配的
		for (num=MIN(MaxLen,(text_tmp.size()-myBegin));num>0;num--)
		{
			str = text_tmp.substr(myBegin,num);
			// 如果在哈希表中能找到并且，那么就写进去
			if (StrInt_Hash.find(str)!=StrInt_Hash.end())
			{
				file_out << str;
				myBegin += num;
				break;
			}
		}
		// 如果没找到，那么不构成词，单独划分
		if (0 == num) {
			file_out << text_tmp.substr(myBegin, 1);
			myBegin += 1;
		}
		file_out << "/";
	}

	// 结束计时
	myFinish = clock();
	time_total = (double)(myFinish - myStart) / CLOCKS_PER_SEC;	// 计算运行总时间
	file_out_time << "运行时间为： " << time_total << " 秒。" << endl;
	
	// 关闭文件
	file_out_time.close();
	file_out_time.clear();
	file_out.close();
	file_out.clear();
	file_in.close();
	file_in.clear();
}

int main()
{
	PositiveMaxMatch(infile,outfile);
	return 0;
}

