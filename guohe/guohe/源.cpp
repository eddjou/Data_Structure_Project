#include<iostream>
using namespace std;
const int VertexNum = 16;
typedef struct
{
	int farmer; // 农夫
	int wolf; // 狼
	int sheep; // 羊
	int veget; // 白菜
}Vertex;
typedef struct
{
	int vertexNum; // 当前顶点数
	Vertex vertex[VertexNum]; // 顶点向量
	bool Edge[VertexNum][VertexNum]; // 邻接矩阵
}AdjGraph; // 定义图的邻接矩阵存储结构
bool visited[VertexNum] = { false }; 
int retPath[VertexNum] = { -1 }; 


int locate(AdjGraph *graph, int farmer, int wolf, int sheep, int veget)
{
	for (int i = 0; i < graph->vertexNum; i++)
	{
		if (graph->vertex[i].farmer == farmer && graph->vertex[i].wolf == wolf && graph->vertex[i].sheep == sheep && graph->vertex[i].veget == veget)
			return i; //返回当前位置
	}
	return -1;
}


bool isSafe(int farmer, int wolf, int sheep, int veget)
{
	if (farmer != sheep && (wolf == sheep || sheep == veget)) return false;
	else return true;
}

bool isConnect(AdjGraph *graph, int i, int j)
{
	int k = 0;
	if (graph->vertex[i].wolf != graph->vertex[j].wolf) k++;
	if (graph->vertex[i].sheep != graph->vertex[j].sheep) k++;
	if (graph->vertex[i].veget != graph->vertex[j].veget) k++;
	if (graph->vertex[i].farmer != graph->vertex[j].farmer && k <= 1) return true;
	else return false;
}

void CreateG(AdjGraph *graph)
{
	int i = 0; int j = 0;
	for (int farmer = 0; farmer <= 1; farmer++)
	{
		for (int wolf = 0; wolf <= 1; wolf++)
		{
			for (int sheep = 0; sheep <= 1; sheep++)
			{
				for (int veget = 0; veget <= 1; veget++)
				{
					if (isSafe(farmer, wolf, sheep, veget))
					{
						graph->vertex[i].farmer = farmer;
						graph->vertex[i].wolf = wolf;
						graph->vertex[i].sheep = sheep;
						graph->vertex[i].veget = veget;
						i++;
					}
				}
			}
		}
	}
	graph->vertexNum = i;
	for (i = 0; i < graph->vertexNum; i++)
	{
		for (j = 0; j < graph->vertexNum; j++)
		{
			if (isConnect(graph, i, j)) graph->Edge[i][j] = graph->Edge[j][i] = true;
			else graph->Edge[i][j] = graph->Edge[j][i] = false;
		}
	}
	return;
}

char* judgement(int state)
{
	if (state == 0) return "左岸";
	else return "右岸";
}
void printPath(AdjGraph *graph, int start, int end)
{
	int i = start;
	cout << "farmer" << "	wolf" << "	sheep" << "	vegetable" << endl;
	while (i != end) {
		cout <<judgement(graph->vertex[i].farmer) << "	" <<
			judgement(graph->vertex[i].wolf) << "	" << judgement(graph->vertex[i].sheep) << "	" <<
			judgement(graph->vertex[i].veget);
		cout << endl;
		i = retPath[i];
	}
	cout <<judgement(graph->vertex[i].farmer) << "	" <<
		judgement(graph->vertex[i].wolf) << "	" << judgement(graph->vertex[i].sheep) << "	" <<
		judgement(graph->vertex[i].veget);
	cout << endl;
}
//DFS--Depth First Search
void dfsPath(AdjGraph *graph, int start, int end)
{
	int i = 0;
	visited[start] = true;
	if (start == end) return;
	for (i = 0; i < graph->vertexNum; i++)
	{
		if (graph->Edge[start][i] && !visited[i])
		{
			retPath[start] = i;
			dfsPath(graph, i, end);
		}
	}
}
int main()
{
	AdjGraph graph;
	CreateG(&graph);
	int start = locate(&graph, 0, 0, 0, 0);
	int end = locate(&graph, 1, 1, 1, 1);
	dfsPath(&graph, start, end);
	if (visited[end])
	{
		printPath(&graph, start, end);
		return 0;
	}
	return -1;
}
