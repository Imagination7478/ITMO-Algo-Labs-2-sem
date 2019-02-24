#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream out;
	ifstream in;

	in.open("input.txt");
	out.open("output.txt");
	int n; //Вершины
	int m; //Ребра
	in >> n >> m;

	int **ptrArrOut = new int*[n];
	for (int i = 0; i < n; i++)
		ptrArrOut[i] = new int[n];

	int first, second;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ptrArrOut[i][j] = 0;

	for (int i = 0; i < m; i++)
	{
		in >> first >> second;
		ptrArrOut[first - 1][second - 1] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			out << ptrArrOut[i][j] << " ";
		}
		out << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] ptrArrOut[i];
	delete[] ptrArrOut;

	return 0;
}