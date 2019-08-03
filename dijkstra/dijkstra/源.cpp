#include"Dijkstra.h"

bool check(int Vexnum, int edge) {
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
		return false;
	return true;
}
int main() {
	int vexnum; int edge;

	cout << "enter vertex and edge num:" << endl;
	cin >> vexnum >> edge;
	while (!check(vexnum, edge)) {
		cout << "ilegal, please retry" << endl;
		cin >> vexnum >> edge;
	}
	Graph_DG graph(vexnum, edge);
	graph.createGraph();
	graph.print();
	graph.Dijkstra(1);
	graph.print_path(1);
	system("pause");
	return 0;
}
