#include "stdfax.h"
#define MAXSIZE 1000000

extern Graph graph;
extern Vex* vexs;
extern int adj[MAX][MAX];

void printShortestPath(vector<vector<int>> path, int start, int end)
{
	printf("最短路线为：");
	stack<int> shortestPath;
	shortestPath.push(end);
	while (start != end)
	{
		for (int i = path[end].size() - 1; i >= 0; --i)
		{
			shortestPath.push(path[end][i]);
		}
		end = path[end][0];
	}
	while (shortestPath.size() != 1)
	{
		cout << vexs[shortestPath.top()].name << "->";
		shortestPath.pop();
	}
	cout << vexs[shortestPath.top()].name << "\n";
}

void dijkstra()
{
	int start, end;
	int vexNum = graph.getVexNum();
	map<int, int> shortestSet;  //map<viewCode,distance>
	vector<vector<int>> path(vexNum);
	bool *visit = new bool[vexNum];
	memset(visit, false, vexNum);
	memcpy(adj, graph.adj, MAX*MAX);
	printf("== 搜索最短路径 ==\n\n");
	printf("请输入起点的编号(0-%d)：", vexNum - 1);
	scanf("%d", &start);
	printf("请输入终点的编号(0-%d)：", vexNum - 1);
	scanf("%d", &end);
	//initDistanceSet
	for (int n = 0; n < vexNum; ++n)
	{
		if (adj[start][n] != 0 || n == start)
		{
			shortestSet.insert(pair<int, int>(n, adj[start][n]));
			path[n].push_back(start);
		}
		else
			shortestSet.insert(pair<int, int>(n, MAXSIZE));
	}
	visit[start] = true;
	for (int i = 1; i < vexNum; ++i)
	{
		int min = MAXSIZE;
		int mark;
		//select min in unmarked points
		for (int j = 0; j < vexNum; ++j)
		{
			if (!visit[j] && shortestSet[j] < min)
			{
				min = shortestSet[j];
				mark = j;
			}
		}
		//mark selected min point
		visit[mark] = true;
		//update min distance
		for (int k = 0; k < vexNum; ++k)
		{
			if (!visit[k] && adj[mark][k] != 0 && min + adj[mark][k] < shortestSet[k])
			{
				shortestSet[k] = adj[mark][k] + min;
				path[k].push_back(mark);  //record travel path
			}
		}
	}
	delete[] visit;
	//print result
	printShortestPath(path, start, end);
	printf("最短距离为：%d米\n\n", shortestSet[end]);
}