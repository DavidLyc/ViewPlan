#include "stdfax.h"

void outputMenu()
{
	cout << "1.景区景点图\n";
	cout << "2.查询景点信息\n";
	cout << "3.旅游景点导航\n";
	cout << "4.搜索最短路径\n";
	cout << "5.铺设电路规划\n";
	cout << "0.退出\n";
	cout << "请输入操作编号：";
}

void showGraph()
{
	showViews();
	showRoads();
}

void menu()
{
	cout << "===  景区信息管理系统  ===\n";
	while (true)
	{
		outputMenu();
		char m;
		cin >> m;
		switch (m)
		{
		case '1':showGraph(); break;
		case '2':search(); break;
		case '3':navigate(); break;
		case '4':dijkstra(); break;
		case '5':prim(); break;
		case '0':return; break;
		default:cout << "输入菜单有误！\n";
			break;
		}
	}

}