#ifndef GLOBAL_H
#define GLOBAL_H
#include "stdfax.h"

struct Vex
{
	int num; //������
	string name; //��������
	string desc; //�������
};

struct Edge
{
	//�����ڵ�������
	int vex1;
	int vex2;
	int weight;  //Ȩֵ
};

const int MAX = 100;

#endif