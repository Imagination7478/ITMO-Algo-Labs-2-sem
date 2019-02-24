#include<fstream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

struct vertex {
	char x;
	char y;
	short int prev;
};

int main() {
	ifstream in;
	ofstream out;

	int tops, edges, i, S, T;;
	int top1, top2;
	in.open("input.txt");
	out.open("output.txt");
	in >> tops >> edges;

	vertex *a = new vertex[tops*edges];
	vector<bool> used(tops*edges);

	bool flag = 0;
	queue<int> q;

	for (i = 0; i < tops*edges; i++) {
		in >> a[i].x;

		if (a[i].x == 'S') {
			S = i;
		}

		if (a[i].x == 'T') {
			T = i;
		}
	}

	q.push(S);

	while ((!q.empty()) && (!flag)) {
		i = q.front();
		q.pop();

		if (i == T) {
			flag = 1;
			break;
		}

		if (!used[i]) {
			if ((i >= edges) && (a[i - edges].x != '#')) {
				q.push(i - edges);
				if (!used[i - edges]) {
					a[i - edges].prev = i;
					a[i - edges].y = 'U';
				}
			}

			if ((i < (tops - 1)*edges) && (a[i + edges].x != '#')) {
				q.push(i + edges);
				if (!used[i + edges]) {
					a[i + edges].prev = i;
					a[i + edges].y = 'D';
				}
			}

			if ((i % edges > 0) && (a[i - 1].x != '#')) {
				q.push(i - 1);
				if (!used[i - 1]) {
					a[i - 1].prev = i;
					a[i - 1].y = 'L';
				}
			}

			if ((i % edges < edges - 1) && (a[i + 1].x != '#')) {
				q.push(i + 1);
				if (!used[i + 1]) {
					a[i + 1].prev = i;
					a[i + 1].y = 'R';
				}
			}
		}
		used[i] = 1;
	}

	if (flag) {
		string s = "";

		while (T != S) {
			s = a[T].y + s;
			T = a[T].prev;
		}

		out << s.length() << endl << s;
	}
	else {
		out << "-1";
	}
}