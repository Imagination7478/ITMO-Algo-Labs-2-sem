#include <fstream>
#include <vector>
using namespace std;

int *color;
vector<vector<int>> graph;
bool ok = true;

void dfs(int start)
{
	for (int u = 0; u < graph[start].size(); ++u)
		if (color[graph[start][u]] == 0)
		{
			color[graph[start][u]] = 3 - color[start];
			dfs(graph[start][u]);
		}
		else if (color[graph[start][u]] == color[start])
			ok = false;
}

int main() {
	ifstream in;
	ofstream out;
	int tops, edges;
	in.open("bipartite.in");
	out.open("bipartite.out");
	in >> tops >> edges;
	
	graph.resize(tops + 1);
	int top1, top2;
	for (int i = 0; i < edges; i++)
	{
		in >> top1 >> top2;
		graph[top1].push_back(top2);
	}

	color = new int[tops];
	for (int i = 0; i < tops; i++)
		color[i] = 0;
	
	for (int i = 1; i <= tops; ++i)
	if (color[i] == 0)
	{
		color[i] = 1;
		dfs(i);
	}
	
	out << (ok ? "YES" : "NO");
	return 0;
}