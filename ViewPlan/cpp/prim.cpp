#include "../head/stdfax.h"

extern Graph graph;
extern Vex* vexs;
extern int adj[MAX][MAX];

void prim()
{
	cout << "== �����·�滮 ==\n";
	cout << "��������������֮�������·��\n";
	//initial
	int min, mark1, mark2;
	int total = 0;
	memcpy(adj, graph.adj, MAX*MAX);
	vexs = graph.getVexs();
	int vexNum = graph.getVexNum();
	bool *visit = new bool[vexNum];
	memset(visit, false, vexNum);
	//A is starting point
	visit[0] = true;
	//add other points
	for (int i = 1; i < vexNum; ++i)
	{
		min = MAXSIZE;
		//select min distance edge near visited point
		for (int j = 0; j < vexNum; ++j)
		{
			if (visit[j])
			{
				for (int k = 0; k < vexNum; ++k)
				{
					if (!visit[k] && adj[j][k] != 0 && adj[j][k] < min)
					{
						min = adj[j][k];
						mark1 = j;
						mark2 = k;
					}
				}
			}
		}
		visit[mark2] = true;		//mark the point
		total += min;	//add cost to total
		//print
		cout << vexs[mark1].name << "->" << vexs[mark2].name << "    ";
		printf("%d��\n", adj[mark1][mark2]);
	}
	printf("�����·���ܳ���Ϊ��%d��\n\n", total);
}