#ifndef GRAPH_H
#define GRAPH_H
#include "stdfax.h"

void initGraph();
void initEdge();
void showViews();
void showRoads();
void search();

class Graph
{
private:
	Vex vexs[MAX];  //��������
	int vexNum;  //�������

public:
	int adj[MAX][MAX];  //�ڽӾ���
	Graph() { vexNum = 0; }
	void addVex(Vex vex); //����һ����
	Vex* getVexs();
	int getVexNum();    //���ض�������
	void setAdjoinNode(int vex1, int vex2, int weight);
};

#endif