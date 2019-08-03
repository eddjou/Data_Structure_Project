#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Dis {
	string path;
	int value;
	bool visit;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph_DG {
private:
	int vexnum;   //图的顶点个数
	int edge;     //图的边数
	int **arc;   //邻接矩阵
	Dis * dis;   //记录各个顶点最短路径的信息
public:
	
	Graph_DG(int vexnum, int edge);
	
	~Graph_DG();
	bool check_edge_value(int start, int end, int weight);
	void createGraph();
	void print();
	void Dijkstra(int begin);
	void print_path(int);
};
