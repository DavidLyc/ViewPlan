#include "../head/stdfax.h"

Graph graph;

int Graph::getVexNum()
{
	return vexNum;
}

void Graph::addVex(Vex vex)
{
	int num = getVexNum();
	vexs[num] = vex;
	vexNum++;
}

void Graph::setAdjoinNode(int vex1, int vex2, int weight)
{
	adj[vex1][vex2] = weight;
	adj[vex2][vex1] = weight;
}

Vex* Graph::getVexs()
{
	return vexs;
}

void initGraph()
{
	ifstream file("txt/Vex.txt");
	string buffer;
	Vex vex;
	getline(file, buffer);
	int num = atoi(buffer.c_str());
	while (!file.eof())
	{
		getline(file, buffer);
		vex.num = atoi(buffer.c_str());
		getline(file, buffer);
		vex.name = buffer;
		getline(file, buffer);
		vex.desc = buffer;
		graph.addVex(vex);
	}
	file.close();
}

void initEdge()
{
	ifstream file("txt/Edge.txt");
	string buffer;
	Edge edge;
	while (!file.eof())
	{
		getline(file, buffer);
		char infos[256] = { '\0' };
		buffer.copy(infos, buffer.size());
		char *info = strtok(infos, "\t");
		edge.vex1 = atoi(info);
		info = strtok(NULL, "\t");
		edge.vex2 = atoi(info);
		info = strtok(NULL, "\t");
		edge.weight = atoi(info);
		graph.setAdjoinNode(edge.vex1, edge.vex2, edge.weight);
	}
	file.close();
}

void showViews()
{
	cout << "=== ��������ͼ ===" << endl;
	cout << "������Ŀ��" << graph.getVexNum() << endl;
	cout << "-- ���� --" << endl;
	Vex* vexs = graph.getVexs();
	for (int i = 0; i < graph.getVexNum(); ++i)
	{
		cout << i << " -- " << vexs[i].name << endl;
	}
}

void showRoads()
{
	cout << "\n-- ��· --\n";
	for (int j = 0; j < graph.getVexNum(); ++j)
	{
		for (int k = 0; k < graph.getVexNum(); ++k)
		{
			if (graph.adj[j][k] != 0)
			{
				printf("%d -> %d  %d��\n", j, k, graph.adj[j][k]);
			}
		}
	}
	cout << "\n\n";
}

void search()
{
	Vex *vexs = graph.getVexs();
	cout << "����Ҫ��ѯ�ľ����ţ�";
	int n;
	cin >> n;
	if (n >= graph.getVexNum() || n < 0)
		cout << "�����ڸþ���\n\n";
	else {
		string tip = "��";
		cout << vexs[n].name << "\n" << vexs[n].desc << "\n\n";
		cout << "--- �ܱ߾��� ---\n";
		for (int i = 0; i < graph.getVexNum(); ++i)
		{
			if (i != n&&graph.adj[n][i] != 0)
			{
				cout << vexs[i].name;
				cout << " ����" << graph.adj[n][i] << "��\n";
				tip.clear();
			}
		}
		cout << tip << "\n";
	}
}
