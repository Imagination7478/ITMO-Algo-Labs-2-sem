#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct vertex {
	int used, colour;
	vector<int>graph, graph_transposed;
};

void dfs_g(int v, vector<vertex>&components, vector<int>&list) {
	components[v].used = 1;
	for (int i = 0; i < components[v].graph.size(); i++) {
		if (components[components[v].graph[i]].used != 1) 
			dfs_g(components[v].graph[i], components, list);
	}
	list.push_back(v);
}

void dfs_tg(int v, int color, vector<vertex>&components) {
	components[v].used = 2;
	components[v].colour = color;
	for (int i = 0; i<components[v].graph_transposed.size(); i++) {
		if (components[components[v].graph_transposed[i]].used != 2)
			dfs_tg(components[v].graph_transposed[i], color, components);
	}
}

int main() {
	int tops, edges, color = 0, answer = 0;
	cin >> tops >> edges;
	vector<int>list(tops);
	vector<vertex>components(tops);
	set<int> *ribs = new set<int>[edges];

	for (int i = 0; i < edges; i++) {
		int a, b;
		cin >> a >> b;
		components[a - 1].graph.push_back(b - 1);
		components[b - 1].graph_transposed.push_back(a - 1);
	}

	for (int i = 0; i < tops; i++) {
		if (components[i].used != 1)dfs_g(i, components, list);
	}
	for (int i = list.size() - 1; i >= 0; i--) {
		if (components[list[i]].used != 2) {
			dfs_tg(list[i], color, components);
			color++;
		}
	}
	for (int i = 0; i < tops; i++) {
		for (int j = 0; j<components[i].graph.size(); j++) {
			if (components[i].colour != components[components[i].graph[j]].colour) {
				ribs[components[i].colour].insert(components[components[i].graph[j]].colour);
			}
		}
	}
	for (int i = 0; i < 10000; i++)
		answer += ribs[i].size();
	cout << answer;
	return 0;
}