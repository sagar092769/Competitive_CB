#include <bits/stdc++.h>
using namespace std;
#define pb push_back
class Graph {
	unordered_map<int, list<int>> gr;
public:
	void addEdge(int x, int y) {
		gr[x].pb(y);
		gr[y].pb(x);
	}
	void display() {
		for (auto node : gr) {
			cout << "Node is:" << node.first << "-> ";
			for (auto nbrs : gr[node.first]) {
				cout << nbrs << " ";
			}
			cout << endl;
		}
	}
};

int main() {
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.addEdge(5, 6);
	g.display();
	return 0;

}