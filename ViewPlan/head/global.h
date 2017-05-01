#ifndef GLOBAL_H
#define GLOBAL_H
#include "stdfax.h"
#define MAXSIZE 1000000

struct Vex
{
	int num; //景点编号
	string name; //景点名字
	string desc; //景点介绍
};

struct Edge
{
	//边相邻的两个点
	int vex1;
	int vex2;
	int weight;  //权值
};

const int MAX = 100;

#endif