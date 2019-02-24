#include<fstream>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int first, second, j, x, y;

	ifstream in;
	ofstream out;

	int tops, edges;
	int top1, top2;
	in.open("pathbge1.in");
	out.open("pathbge1.out");
	in >> tops >> edges;

	vector<vector<int>> graph;
	graph.resize(tops + 1);
	for (int i = 0; i < edges; i++) {
		in >> top1 >> top2;
		graph[top1].push_back(top2);
		graph[top2].push_back(top1);
	}
	vector<bool> used(tops + 1);
	vector<int> d(tops + 1);
	queue<int> q;

	for (int i = 0; i <= tops; i++) {
		used[i] = false;
		d[i] = 0;
	}

	used[1] = true;
	q.push(1);
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			y = graph[x][i];
			if (!used[y]) {
				used[y] = true;
				q.push(y);
				d[y] = d[x] + 1;
			}
		}
	}
	for (int i = 1; i <= tops; i++) {
		out << d[i] << " ";
	}

}