#include "stdfax.h"

void outputMenu()
{
	cout << "1.��������ͼ\n";
	cout << "2.��ѯ������Ϣ\n";
	cout << "3.���ξ��㵼��\n";
	cout << "4.�������·��\n";
	cout << "5.�����·�滮\n";
	cout << "0.�˳�\n";
	cout << "�����������ţ�";
}

void showGraph()
{
	showViews();
	showRoads();
}

void menu()
{
	cout << "===  ������Ϣ����ϵͳ  ===\n";
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
		default:cout << "����˵�����\n";
			break;
		}
	}

}