#include <fstream>
#include <vector>
using namespace std;

bool cycle = false;

void dfs(int v, int used[], vector<vector<int>> &graph, vector<int> &result) {
	used[v] = 1;

	for (size_t i = 0; i < graph[v].size(); ++i) {
		int to = graph[v][i];
		if (used[to] == 0) {
			dfs(to, used, graph, result);
			
		}
		else if (used[to] == 1)
			cycle = true;
	}
	used[v] = 2;
	result.push_back(v);
}

int main()
{
	ifstream in;
	ofstream out;

	int tops, edges;
	in.open("topsort.in");
	out.open("topsort.out");
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

	int j = 1;
	while (j != (graph.size()))
	{
		if (used[j] == 0) {
			dfs(j, used, graph, result);
			j++;
		}
		else
			j++;
	}

	

	for (int i = result.size() - 1; i >= 0; i--) {
		if (cycle) {
			out << "-1";
			break;
		}
		else
			out << result[i] << " ";
	}


	delete[] used;
	return 0;
}