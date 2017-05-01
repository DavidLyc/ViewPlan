#include "../head/stdfax.h"

extern Graph graph;
Vex* vexs = graph.getVexs();
int adj[MAX][MAX];

void printPath(vector<int> path, int& road)
{
	int size = path.size();
	printf("·��%d��", ++road);
	for (int i = 0; i < size - 1; ++i)
	{
		cout << vexs[path[i]].name << " -> ";
	}
	cout << vexs[path[size - 1]].name << "\n";
}

void dfs(vector<int> path, bool* visit, int& road)
{
	if (path.size() >= graph.getVexNum())
	{
		printPath(path, road);
		return;
	}
	int now = path.back();
	for (int to = 0; to < graph.getVexNum(); ++to)
	{
		if (!visit[to] && adj[now][to] != 0)
		{
			visit[to] = true;  //mark visited point
			path.push_back(to);  //add point
			dfs(path, visit, road);
			//reset
			visit[to] = false;
			path.pop_back();
		}
	}
}

void navigate()
{
	cout << "== ���ξ��㵼�� ==\n\n";
	printf("�����뾰����(0��%d)��", graph.getVexNum() - 1);
	int v;
	cin >> v;
	if (v < 0 || v >= graph.getVexNum())
	{
		cout << "�����ڸþ��㣡\n\n";
	}
	else
	{
		memcpy(adj, graph.adj, MAX*MAX);
		int road = 0;
		vector<int> path;  //travel path
		path.push_back(v);
		bool *visit = new bool[graph.getVexNum()];
		memset(visit, false, graph.getVexNum());
		visit[v] = true;
		dfs(path, visit, road);
	}
	printf("\n");
}