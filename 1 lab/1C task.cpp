#include <iostream>
#include <fstream>
using namespace std;

int generateHash(int one, int two)
{
	return (one * two) * (one + two) % 100;
}

int main()
{
	ofstream out;
	ifstream in;

	in.open("input.txt");
	out.open("output.txt");
	int n, m, first, second;
	in >> n >> m;

	bool parallel = false;

	int Hash[100] = {0};

	for (int i = 0; i < m; i++)
	{
		in >> first >> second;

		Hash[generateHash(first, second)] += 1;
		if (Hash[generateHash(first, second)] > 1) {
			parallel = true;
			break;
		}
	}

	if (parallel)
		out << "YES";
	else
		out << "NO";
	
	return 0;
}