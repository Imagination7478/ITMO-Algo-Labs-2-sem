#include <fstream>
#include <vector>
using namespace std;

int cycle_st = -1, cycle_end;

void dfs(int v, int used[], vector<vector<int>> &graph, vector<int> &result, vector<int> &p) {
	used[v] = 1;

	for (size_t i = 0; i < graph[v].size(); ++i) {
		int to = graph[v][i];
		if (used[to] == 0) {
			p[to] = v;
			dfs(to, used, graph, result, p);
		}
		else if (used[to] == 1) {
			cycle_end = v;
			cycle_st = to;
			
		}
	}
	used[v] = 2;
	result.push_back(v);
}

int main()
{
	ifstream in;
	ofstream out;

	int tops, edges;
	in.open("cycle.in");
	out.open("cycle.out");
	in >> tops >> edges;

	vector<vector<int>> graph;
	graph.resize(tops + 1);
	int top1, top2;
	for (int i = 0; i < edges; i++)
	{
		in >> top1 >> top2;
		graph[top1].push_back(top2);
	}

	vector<int> result;
	int *used = new int[tops + 1];
	for (size_t i = 0; i <= tops; i++)
		used[i] = 0;

	vector<int> p;
	p.resize(tops + 1);
	int j = 1;
	while (j != (graph.size()))
	{
		if (used[j] == 0) {
			dfs(j, used, graph, result, p);
			j++;
		}
		else
			j++;
	}

	if (cycle_st == -1)
	{
		out << "NO";
	}
	else {
		out << "YES" << endl;
		vector<int> cycle;
		cycle.push_back(cycle_st);
		for (int v = cycle_end; v != cycle_st; v = p[v])
			cycle.push_back(v);

		for (int i = cycle.size() - 1; i >= 0 ; i--)
			out << cycle[i] << " ";
	}
	
	delete[] used;
	return 0;
}