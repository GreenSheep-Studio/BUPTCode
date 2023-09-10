#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include <sstream>    //使用istringstream所需要的头文件 
#include <cassert>
#include<queue>
#include<vector>
#include<time.h>
//#include<graphics.h>
#include<conio.h>
//#include<easyx.h>
#include<windows.h>
#include<mmsystem.h>
#include <unordered_map>
using	namespace std;
/*采用邻接表作为存储结构
	构建站点Station和道路Road两种结构体*/
	//站点结构体如下:
int	Stationnum = 356;
int insistnum = 352;
struct Stations
{
	string name;	//站点名称
	string belongs[20];//所属线路（换乘站的话属于多条线路）
	Stations* nextStaion;//指向下一站的指针（换乘站可能有多个下一站）
}station[500];
Stations emptystation;

//计算最少换乘用图
vector<vector<int>>Map(Stationnum, vector<int>(Stationnum));

//道路结构体如下:
int	Roadnum = 800;
int staynum = 796;
struct Roads
{
	bool ifuse = true;
	string	from;	//从哪里来
	string	to;		//到哪里去
	string  belong;	//所属线路
	double	distance;	//道路长度
	double	equaltime;	//所用时间
}road[5000];

int	Sublinenum = 30;
//记录各条线路速度
struct Sublines
{
	string	name;
	int		speed;
}subline[35];

//记录搜索时的方式
struct pos
{
	string	Loc;	//所在位置
	int	Distance;//行程距离
	int	Changetime;//换乘次数
	int	Costtime;//花费时间
	vector<string>Rember;//记录途径地点
};

//存储结果的结构体
struct Outans
{
	vector<string>disans;	//最短路程结果数组
	vector<string>timans;	//最短时间结果数组
	int	Odistance;			//最短路程距离
	int distime;			//最短路程时间
	double Otime;			//最短时间时间
	int timdist;			//最短时间距离
	int	Dcostmoney;			//最短路程花费
	int Tcostmoney;			//最短时间花费
}outans, outans2;

//初始化邻接表和道路
void	readfile1();
//初始化各个线路的速度和时间
void	readfile2();
//寻找到车站的编号
int findStation(string str);
//寻找到道路的编号
int	findRoad(string start, string end);
//构建邻接表，插入结点
void insertStation(int start, int end);
//打印邻接表
void print1();
//打印道路
void print2();
//深搜给出解决方案
void bfs(string start, string end);
//最短路径搜索
void dijkstra(string start, string end);
//最短时间搜索
void dijkstra2(string start, string end);
//最少换乘搜索
void dijkstra3(string start, string end);
//最短路函数种搜索距离最小点函数
int	Ddismin(vector<int>arr, vector<int>brr);
int	Ddismin2(vector<double>arr, vector<int>brr);
//返回线路对应的速度
double	findspeed(string str);
//返回道路所属的线路
string findbelong(string start, string end);
//最少换乘路线
void dfs(string start, string end);
//easyx按键
void button(int x, int y, int w, int h, TCHAR* text);
//展示优先路程路径
void display();
//展示优先时间路径
void display2();
//展示最少换乘路径
void display3();
//计算里程花费的钱
int calculatemoney(double n);
//弹出错误
bool showerror(string name);
//停用站点
void forbiddenstation(string name);
//停用线路
void forbiddenroad(string name);
//初始化Map
void initMap();
//添加线路
void insertroad(string start, string end, string length);


void readfile1()
{
	//1、包含头文件
	//2、创建流对象
	//ifstream ifs;
	//3、打开文件并且判断是否打开成功
	//ifs.open("./resource/subway.txt", ios::in);
	ifstream inputFile("subway.txt");
	if (!inputFile.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//存储数据用到的中介值
	string	linename;//线路名称
	int		cnt1 = 1;//车站编号
	int		cnt2 = 1;//道路编号
	int		formStation;//前车站编号
	int		lateStation;//后车编号
	//4、读数据
	string buf;    // 用于存储每一行的文本数据的字符串
	while (getline(inputFile, buf))	//对每一行的处理
	{
		//cout << buf << endl;
		if (buf[0] == '#')	//当这一行是线路时，只存储线路
		{
			linename = buf;  // 将当前行内容存储到linename变量中
			continue;         // 继续读取下一行
		}
		istringstream is(buf);    // 创建字符串输入流is并将其绑定到buf
		string s;
		int	tempcnt = 1;
		while (is >> s)        // 从输入流中逐个读取字符串
		{
			if (tempcnt == 1)	//第一个字符串
			{
				if (findStation(s) == -1)	//没有存储这个站点
				{
					station[cnt1].name = s;   // 将站点名称存储到station数组中
					int i = 0;
					while (station[cnt1].belongs[i] != "")
						i++;
					station[cnt1].belongs[i] = linename;    // 将线路名称存储到站点的所属线路中
					formStation = cnt1;         // 记录前车站编号
					cnt1++;                     // 增加车站编号
				}
				else
				{
					int	j = findStation(s);
					int	i = 0;
					while (station[j].belongs[i] != "")
						i++;
					station[j].belongs[i] = linename;
					formStation = j;
				}
				tempcnt = 2;
			}
			else if (tempcnt == 2)
			{
				int j = cnt1;
				bool	ok = false;
				if (findStation(s) == -1)	//没有存储这个站点
				{
					station[cnt1].name = s;
					ok = true;
				}
				else
				{
					j = findStation(s);
				}
				int i = 0;
				while (station[j].belongs[i] != "")
					i++;
				station[j].belongs[i] = linename;	//添加所属线路
				insertStation(formStation, j);//插入前一个结点的邻接表
				insertStation(j, formStation);
				lateStation = j;	//记录后车编号
				if (ok)
					cnt1++;
				tempcnt = 3;
			}
			else if (tempcnt == 3)
			{
				if (findRoad(station[formStation].name, station[lateStation].name) == -1)
				{
					road[cnt2].from = station[formStation].name;
					road[cnt2].to = station[lateStation].name;
					road[cnt2].distance = atoi(s.c_str());
					//road[cnt2].equaltime = road[cnt2].distance / findspeed(findbelong(station[formStation].name, station[lateStation].name));
					cnt2++;
					road[cnt2].to = station[formStation].name;
					road[cnt2].from = station[lateStation].name;
					road[cnt2].distance = atoi(s.c_str());
					//road[cnt2].equaltime = road[cnt2].distance / findspeed(findbelong(station[formStation].name, station[lateStation].name));
					cnt2++;
				}
				tempcnt = 1;
			}
			//cout << s << endl;
		}

	}
	//5、关闭文件
	inputFile.close();
}

void readfile2()

{
	//1、包含头文件
	//2、创建流对象
	//ifstream ifs;    // 创建文件输入流对象ifs
	ifstream inputFile("subwayv.txt");
	//3、打开文件并且判断是否打开成功
	//inputFile.open("./resource/subwayv.txt", ios::in);
	if (!inputFile.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//统计地铁编号
	int	cnt = 1;
	//4、读数据
	string buf;
	while (getline(inputFile, buf))	//对每一行的处理
	{
		istringstream is(buf);    // 创建字符串输入流is并将其绑定到buf
		string s;
		while (is >> s)          //从输入流中逐个读取字符串
		{
			if (s[0] == '#')      // 如果字符串以'#'开头
				subline[cnt].name = s;           // 存储地铁线路名称
			else
			{
				subline[cnt].speed = atoi(s.c_str());   // 将字符串转换为整数并存储地铁线路的平均速度
			}
		}
		cnt++;
	}
	//5、关闭文件
	inputFile.close();
	for (int i = 1; i < Roadnum; i++)   // 计算道路的等效时间
	{
		// 计算道路的等效时间，等效时间 = 道路距离 / 平均速度
		road[i].equaltime = road[i].distance / findspeed(findbelong(road[i].from, road[i].to));
	}
}

void initMap()
{
	for (int i = 1; i < Stationnum; i++)// 遍历站点数组，从1到Stationnum
	{
		for (int j = 1; j < Stationnum; j++)// 再次遍历站点数组，从1到Stationnum
		{
			if (findbelong(station[i].name, station[j].name) != "")// 检查站点i和站点j是否属于同一地铁线路
			{
				Map[i][j] = 1;// 如果是同一地铁线路，将Map[i][j]的值设为1，表示它们之间存在连接
			}
			else
			{
				Map[i][j] = 9999; // 如果不属于同一地铁线路，将Map[i][j]的值设为9999，表示它们之间无连接或距离非常大
			}
		}
	}
}

void print1()
{
	// 遍历每个站点
	for (int i = 1; i <= Stationnum; i++)
	{
		cout << station[i].name;  // 打印当前站点的名称
		Stations* sta = station[i].nextStaion;   // 获取当前站点的邻接表的第一个站点
		// 遍历当前站点的邻接表
		while (sta)
		{
			cout << "->" << sta->name;  // 打印站点之间的连接箭头和相邻站点的名称
			sta = sta->nextStaion;    // 移动到下一个相邻站点
		}
		cout << endl;       // 打印换行，表示当前站点及其相邻站点的输出结束
	}
}

void print2()
{
	// 遍历每个道路
	for (int i = 1; i <= Roadnum; i++)
	{
		// 打印道路的起点、连接箭头、终点、距离和等效时间
		cout << road[i].from << "->" << road[i].to << " need " << road[i].distance << "and" << road[i].equaltime << endl;
	}
}

void bfs(string start, string end)
{
	vector<int>vis(300);  // 用于标记站点是否被访问过的数组，初始化为0表示未访问
	queue<pos>que;        // 创建一个队列用于广度优先搜索
	pos	cur;             // 当前位置信息
	pos ans[2000];       // 存储找到的路径
	pos res;             // 最短路径结果
	int	cnt = 1;	     // 记录找到的路径数量，初始化为1
	cur.Loc = start;     // 设置起始位置
	cur.Distance = 0;       // 距离初始化为0
	cur.Rember.push_back(start);        // 将起始位置添加到路径中
	vis[findStation(start)] = 1;        // 标记起始位置为已访问
	que.push(cur);                      //将起始位置加入队列
	while (!que.empty())
	{
		cur = que.front();         // 获取队列中的第一个位置
		que.pop();                 // 弹出队列中的第一个位置
		if (cur.Loc == end)	//找到了目的地
		{
			ans[cnt] = cur;       // 将当前路径添加到答案数组中
			cnt++;                 // 增加路径数量
			break;                // 找到目的地后结束搜索
		}
		Stations* sta = station[findStation(cur.Loc)].nextStaion;    // 获取当前位置的邻接站点列表
		while (sta)
		{
			pos nex;        // 下一个位置信息
			nex.Loc = sta->name;      // 设置下一个位置
			sta = sta->nextStaion;     // 移动到下一个邻接站点
			if (!vis[findStation(nex.Loc)])    // 如果下一个位置未被访问过
			{
				nex.Distance = road[findRoad(cur.Loc, nex.Loc)].distance + cur.Distance;  // 计算下一个位置的总距离
				nex.Rember = cur.Rember;           // 复制当前路径
				nex.Rember.push_back(nex.Loc);    // 将下一个位置添加到路径中
				que.push(nex);                    // 将下一个位置加入队列
			}
		}
	}
	res.Distance = INT_MAX;         // 初始化最短路径的距离为最大值
	for (int i = 1; i <= cnt - 1; i++)
	{
		if (ans[i].Distance < res.Distance)    // 如果找到的路径更短
			res = ans[i];                      // 如果找到的路径更短
	}
	for (int i = 0; i < res.Rember.size(); i++)    //输出最短路径的站点序列
		cout << res.Rember[i] << "->";
	cout << endl;
}

void dijkstra(string start, string end)
{
	//最短路径算法辅助数组
	vector<int>Dvis(Stationnum);//标记访问数组
	vector<int>Ddis(Stationnum);//标记起始点到每一个端点最短路径数组
	vector<double>Dtim(Stationnum);//记录最短时间
	vector<int>Dlin(Stationnum);//记录当前结点上一个结点是什么
	vector<string>Dans;      //输出路线结果
	for (int i = 1; i < Stationnum; i++)	//对数组进行初始化
	{
		Ddis[i] = INT_MAX;    // 初始化距离为无穷大
	}
	Ddis[findStation(start)] = 0;	//初始化出发结点的距离为0
	Dtim[findStation(start)] = 0;   // 初始化出发结点的时间为0
	while (Dvis[findStation(end)] != 1)	//当终点没有被标记时，持续循环
	{
		int	cur = Ddismin(Ddis, Dvis);	//找到当前到起点最短的路径
		Stations* sta = station[cur].nextStaion;  // 获取当前站点的邻接站点列表
		while (sta)	//更新该结点到其它结点的距离
		{
			int nex = findStation(sta->name);    // 获取下一个邻接站点的编号
			// 如果通过当前站点到达下一个站点的距离更短，则更新距离、时间和路径信息
			if (Ddis[nex] > Ddis[cur] + road[findRoad(station[cur].name, station[nex].name)].distance)
			{
				Ddis[nex] = Ddis[cur] + road[findRoad(station[cur].name, station[nex].name)].distance;
				Dtim[nex] = Dtim[cur] + road[findRoad(station[cur].name, station[nex].name)].equaltime;
				Dlin[nex] = cur;
			}
			sta = sta->nextStaion;  	// 移动到下一个邻接站点 
		}
		Dvis[cur] = 1;   // 标记当前站点为已访问
	}
	int	temp = findStation(end);
	while (temp != findStation(start))
	{
		Dans.push_back(station[temp].name);  // 从终点向起点回溯，将站点名称添加到路径中
		temp = Dlin[temp];            // 获取上一个站点的编号
	}
	//Dans.insert(Dans.begin(), start);
	Dans.push_back(start);     // 将起点添加到路径中
	string	linenote = station[findStation(Dans[0])].belongs[0];  // 获取起点所属的线路
	outans.disans = Dans;   // 存储路径结果	
	outans.Odistance = Ddis[findStation(end)];    // 最短距离
	outans.distime = Dtim[findStation(end)];      // 花费时间
	double tempdis = (double)outans.Odistance / 1000;    // 将最短距离转换为千米
	outans.Dcostmoney = calculatemoney(tempdis);   // 计算所需花费
	// 输出路径信息
	for (int i = 0; i < Dans.size(); i++)
	{

		cout << Dans[Dans.size() - i - 1] << "->";
	}
	cout << endl;
	cout << "距离优先：" << endl;
	cout << "最短距离为：" << Ddis[findStation(end)] << endl;
	cout << "花费时间为:" << Dtim[findStation(end)] << endl;
	cout << "所需花费为：" << outans.Dcostmoney << endl;
}

void dijkstra2(string start, string end)
{

	//最短路径算法辅助数组
	vector<int>Dvis(Stationnum);// 标记访问数组，标记各站点是否已访问，初始化为0表示未访问
	vector<double>Ddis(Stationnum);// 标记起始点到每一个端点的最短路径数组，初始化为INT_MAX表示无穷大
	vector<int>Dtim(Stationnum); // 标记起始点到每一个端点的最短时间数组
	vector<int>Dlin(Stationnum);//记录当前结点上一个结点是什么
	vector<string>Dans;//输出路线结果，储存站点名称
	for (int i = 1; i < Stationnum; i++)	//对数组进行初始化
	{
		Ddis[i] = INT_MAX; // 初始化距离为无穷大
	}
	Ddis[findStation(start)] = 0;	//初始化出发结点的距离为0
	Dtim[findStation(start)] = 0;   //初始化出发结点的时间为0
	while (Dvis[findStation(end)] != 1)	//当终点没有被标记时，持续循环
	{
		int	cur = Ddismin2(Ddis, Dvis);	//找到当前到起点最短的路径
		Stations* sta = station[cur].nextStaion;   // 获取当前站点的邻接站点列表
		while (sta)	//更新该结点到其它结点的距离
		{
			int nex = findStation(sta->name);    // 获取下一个邻接站点的编号
			// 如果通过当前站点到达下一个站点的时间更短，则更新距离、时间和路径信息
			if (Ddis[nex] > Ddis[cur] + road[findRoad(station[cur].name, station[nex].name)].equaltime)
			{
				Ddis[nex] = Ddis[cur] + road[findRoad(station[cur].name, station[nex].name)].equaltime;
				Dtim[nex] = Dtim[cur] + road[findRoad(station[cur].name, station[nex].name)].distance;
				Dlin[nex] = cur;
			}
			sta = sta->nextStaion;  // 移动到下一个邻接站点
		}
		Dvis[cur] = 1;   // 标记当前站点为已访问
	}
	int	temp = findStation(end);
	while (temp != findStation(start))
	{
		Dans.push_back(station[temp].name);   // 从终点向起点回溯，将站点名称添加到路径中
		temp = Dlin[temp];   // 获取上一个站点的编号
	}
	//Dans.insert(Dans.begin(), start);
	Dans.push_back(start);   // 将起点添加到路径中
	string	linenote = station[findStation(Dans[0])].belongs[0];    // 获取起点所属的线路
	outans.timans = Dans;            // 存储路径结果
	outans.Otime = Ddis[findStation(end)];  // 最短时间
	outans.timdist = Dtim[findStation(end)];   // 所用距离
	outans.Tcostmoney = calculatemoney(double(outans.timdist) / 1000);  // 计算所需花费，将距离从米转换为千米
	// 输出路径信息
	for (int i = 0; i < Dans.size(); i++)
	{

		cout << Dans[Dans.size() - i - 1] << "->";
	}
	cout << endl;
	cout << "时间优先：" << endl;
	cout << "所用距离为：" << Dtim[findStation(end)] << endl;
	cout << "最短时间为：" << Ddis[findStation(end)] << endl;
	cout << "所需花费为：" << outans.Tcostmoney << endl;
}

void dijkstra3(string start, string end)
{
	// 最短路径算法辅助数组
	vector<int>vis(Stationnum);  // 标记访问数组，标记各站点是否已访问，初始化为0表示未访问
	vector<int>dis(Stationnum);   // 标记起始点到每一个端点的最短路径数组，初始化为INT_MAX表示无穷大
	vector<int>lin(Stationnum);    // 记录当前结点上一个结点是什么
	vector<string>ans;             // 输出路线结果，存储站点名称
	for (int i = 1; i < Stationnum; i++)   // 对数组进行初始化
	{
		dis[i] = INT_MAX;    // 初始化距离为无穷大	
	}
	dis[findStation(start)] = 0;// 初始化出发结点的距离为0
	while (vis[findStation(end)] != 1)// 当终点没有被标记时，持续循环
	{
		int cur = Ddismin(dis, vis); // 找到当前到起点最短的路径
		for (int i = 1; i < Stationnum; i++) // 获取下一个结点的编号
		{
			int nex = i;
			// 如果通过当前结点到达下一个结点的距离更短，则更新距离和路径信息
			if (dis[nex] > dis[cur] + Map[cur][nex])
			{
				dis[nex] = dis[cur] + Map[cur][nex];
				lin[nex] = cur;  // 记录上一个结点是当前结点
			}
			vis[cur] = 1;// 标记当前结点为已访问
		}
	}
	int	temp = findStation(end);
	while (temp != findStation(start))
	{
		ans.push_back(station[temp].name);// 从终点向起点回溯，将站点名称添加到路径中
		temp = lin[temp];// 获取上一个结点的编号
	}
	ans.push_back(start);// 将起点添加到路径中
	outans2.timans = ans;// 存储路径结果
	// 输出路径信息
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[ans.size() - i - 1] << "->";
	}
}

int	Ddismin(vector<int>arr, vector<int>brr)
{
	int	temp = INT_MAX;// 用于存储当前最小的距离值，初始化为无穷大	
	int	ans = 0;// 用于存储最小距离值所在的数组索引
	for (int i = 1; i < arr.size(); i++)
	{
		// 如果当前数组索引对应的距离值小于 temp，并且该索引在数组 brr 中没有被标记为已访问
		if (arr[i] < temp && brr[i] != 1)// 遍历数组 arr 和 brr
		{
			temp = arr[i];// 更新最小距离值为当前距离值
			ans = i;// 更新最小距离值所在的数组索引为当前索引
		}
	}
	return	ans;// 返回最小距离值所在的数组索引
}
int	Ddismin2(vector<double>arr, vector<int>brr)
{
	int	temp = INT_MAX;// 用于存储当前最小的值，初始化为无穷大
	int	ans = 0;// 用于存储最小值所在的数组索引
	for (int i = 1; i < arr.size(); i++) // 遍历数组 arr 和 brr
	{
		if (arr[i] < temp && brr[i] != 1)// 如果当前数组索引对应的值小于 temp，并且该索引在数组 brr 中没有被标记为已访问
		{
			temp = arr[i]; // 更新最小值为当前值
			ans = i;// 更新最小值所在的数组索引为当前索引
		}
	}
	return	ans;// 返回最小值所在的数组索引
}

int findStation(string str)
{
	for (int i = 1; i < Stationnum; i++)
	{
		if (station[i].name == str)
			return	i;
	}
	return	-1;	//当不存在此站点时
}
int	findRoad(string start, string end)
{
	for (int i = 1; i < Roadnum; i++)
	{
		if (road[i].from == start && road[i].to == end)
			return	i;
	}
	return	-1;	//当不存在这个道路时
}
double	findspeed(string str)
{
	for (int i = 1; i < Sublinenum; i++)
	{
		if (subline[i].name == str)  // 检查当前地铁线路的名称是否与给定的参数字符串相匹配
			return	subline[i].speed;// 如果匹配，返回该地铁线路的速度
	}
	return	-1;      //如果未找到匹配的地铁线路，返回 -1 表示未找到
}
string findbelong(string start, string end)
{
	unordered_map<string, int>hash; // 创建一个无序映射，用于存储线路名称和计数
	int	cur = findStation(start);// 获取起始站点的编号
	int	nex = findStation(end);// 获取目标站点的编号
	for (int i = 0; i < 10; i++)// 遍历起始站点所属的前10个线路，并将线路名称添加到映射中，并计数加1
	{
		hash[station[cur].belongs[i]]++;
	}
	for (int i = 0; i < 10; i++)// 再次遍历目标站点所属的前10个线路
	{
		// 如果目标站点所属的线路在映射中计数大于0（即起始站点和目标站点有共同的线路）
		if (hash[station[nex].belongs[i]] > 0)
		{
			return	station[nex].belongs[i];   // 返回共同的线路名称
		}
	}
	return "";  //如果没有共同的线路，返回空字符串
}
int calculatemoney(double n)
{
	if (n <= 6)  //如果距离小于等于6公里
		return	3;// 返回票价为3元
	else if (n > 6 && n <= 12)
		return	4;
	else if (n > 12 && n <= 22)
		return	5;
	else if (n > 22 && n <= 32)
		return	6;
	else
	{
		return	(n - 32) / 20 + 1 + 6;
	}
}

void insertStation(int start, int end)
{
	if (station[start].nextStaion == NULL)   // 如果起始站点的下一个站点为空
	{
		Stations* newsta = new Stations;    //创建新的站点对象
		newsta->name = station[end].name;   // 设置新站点的名称为终点站的名称
		station[start].nextStaion = newsta;    // 将新站点链接到起始站点
		newsta->nextStaion = NULL;        // 将新站点的下一个站点设置为空
	}
	else
	{
		Stations* newsta = new Stations;      // 创建新的站点对象
		newsta->name = station[end].name;     // 设置新站点的名称为终点站的名称
		newsta->nextStaion = station[start].nextStaion;     // 将新站点的下一个站点指向起始站点的下一个站点
		station[start].nextStaion = newsta;	    //将新站点链接到起始站点（头插法）
	}
}
void insertroad(string start, string end, string length)
{
	if (findStation(end) == -1)	//如果没有存储这个站点（检查是否存在目标站点
	{
		station[insistnum].name = end;// 将目标站点添加到站点数组中
		insistnum++;// 更新站点数量
	}
	int s = findStation(start);                 // 获取起始站点的索引
	int e = findStation(end);                   // 获取目标站点的索引
	insertStation(s, e);                        // 插入起始站点和目标站点之间的邻接表（表示它们相邻）
	insertStation(e, s);                        // 插入目标站点和起始站点之间的邻接表（表示它们相邻）

	road[staynum].from = start;                 // 设置道路信息的起始站点
	road[staynum].to = end;                     // 设置道路信息的目标站点
	road[staynum].distance = atoi(length.c_str());// 将距离字符串转换为整数，并设置道路信息的距离
	staynum++;                                   // 更新道路数量
	road[staynum].to = start;                    // 设置道路信息的目标站点为起始站点
	road[staynum].from = end;                    // 设置道路信息的起始站点为目标站点
	road[staynum].distance = atoi(length.c_str());// 同样设置距离
	staynum++;                                   // 更新道路数量
}
void forbiddenstation(string name)
{
	int cur = findStation(name); // 查找目标站点在站点数组中的索引位置
	Stations* sta = station[cur].nextStaion; // 获取目标站点的邻接站点链表的头指针
	while (sta)
	{
		int nex = findRoad(station[cur].name, sta->name);  // 查找目标站点和邻接站点之间的道路在道路数组中的索引位置
		road[nex].ifuse = false; // 将该道路标记为不可用（被禁用）
		sta = sta->nextStaion;// 移动到下一个邻接站点
	}
	// 更新站点链表，将目标站点从链表中删除
	station[0].nextStaion = emptystation.nextStaion;// 将临时站点链表的头指针赋给站点数组的头指针
	station[cur].nextStaion = station[0].nextStaion;// 更新目标站点的邻接站点链表

}
void forbiddenroad(string name)
{
	for (int i = 1; i < Stationnum; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (station[i].belongs[j] == name)
			{
				forbiddenstation(station[i].name);// 调用 forbiddenstation 函数禁用与指定线路关联的站点和道路
				break;// 当找到匹配线路后，跳出内层循环，继续检查下一个站点
			}
		}
	}
}


int	main()
{

	//cout << findbelong("沙河", "昌平");	
	//string start;
	//string end;
	/*print1();
	print2();*/
	readfile1();    // 调用读取文件1的函数，加载地铁站点和线路信息
	readfile2();    // 调用读取文件2的函数，加载地铁平均速度信息
	initMap();       // 初始化地铁站点之间的关系图

	int Mode = 0;   // 用于判断处于什么模式，默认值0表示菜单模式
	string start;
	string end;
	int need;
	//char start[10] = {};            // 存储用户输入的起始站名称
	//char end[10] = {};              // 存储用户输入的终点站名称
	char insertstart[10] = {};      // 存储用户输入的插入道路的起始站名称
	char insertend[10] = {};        // 存储用户输入的插入道路的终点站名称
	char insertlength[10] = {};     // 存储用户输入的插入道路的长度
	char stopusesta[10] = {};       // 存储用户输入的要禁用的站点名称
	char stopuselin[10] = {};       // 存储用户输入的要禁用的线路名称
	cout << "请输入起点站:";
	cin >> start;
	cout << "请输入终点站：";
	cin >> end;
	cout << "请选择决策需求：" << endl << "1、最短距离" << endl << "2、最短时间" << endl << "3、最少换乘次数" << endl;
	cin >> need;
	if (need == 1)
	{
		dijkstra(start, end);
	}
	else if (need == 2)
	{
		dijkstra2(start, end);
	}
	else if (need == 3)
	{
		dijkstra3(start, end);
	}

	system("PAUSE");
	return 0;
}