#include <fstream>
#include <vector>
using namespace std;

void dfs(int v, int used[], vector<int> &comp, vector<vector<int>> &graph) {
	used[v] = 1;
	comp.push_back(v);
	for (size_t i = 0; i < graph[v].size(); ++i) {
		int to = graph[v][i];
		if (used[to] == 0)
			dfs(to, used, comp, graph);
	}
}

void find_comps(int used[], int tops, vector<int> &comp, vector<vector<int>> &graph, ofstream &out) {
	int *result = new int[tops];
	int g = 0;
	int compSize = 0;

	for (int i = 0; i < tops; ++i)
		used[i] = 0;
	for (int i = 0; i < tops; ++i)
		if (used[i] == 0) {
			comp.clear();
			dfs(i, used, comp, graph);
			
			for (size_t j = 0; j < comp.size(); ++j) {
				result[comp[j]] = g + 1;
			}

			g++;
			compSize++;
		}

	out << compSize << "\n";
	for (int i = 0; i < tops; i++)
		out << result[i] << " ";

	delete[] result;
}

int main()
{
	vector<int> comp;
	ifstream in;
	ofstream out;

	int tops, edges;
	int first, second;
	in.open("components.in");
	out.open("components.out");
	in >> tops >> edges;

	vector<vector <int>> graph;
	int *used = new int[tops];

	for (int i = 0; i < tops; i++)
		graph.push_back(vector<int>());

	for (int i = 0; i < edges; i++)
	{
		in >> first >> second;
		graph[first - 1].push_back(second - 1);
		graph[second - 1].push_back(first - 1);
	}
	
	find_comps(used, tops, comp, graph, out);

	delete[] used;
	return 0;
}