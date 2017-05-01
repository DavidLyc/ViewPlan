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
	Vex vexs[MAX];  //顶点数组
	int vexNum;  //顶点个数

public:
	int adj[MAX][MAX];  //邻接矩阵
	Graph() { vexNum = 0; }
	void addVex(Vex vex); //加入一个点
	Vex* getVexs();
	int getVexNum();    //返回顶点数量
	void setAdjoinNode(int vex1, int vex2, int weight);
};

#endif