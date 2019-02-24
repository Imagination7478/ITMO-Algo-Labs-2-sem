#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream out;
	ifstream in;

	in.open("input.txt");
	out.open("output.txt");
	int n;
	in >> n;

	bool oriented = false;

	int **ptrArrOut = new int*[n];
	for (int i = 0; i < n; i++)
		ptrArrOut[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> ptrArrOut[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ptrArrOut[i][j] == 1 || ptrArrOut[j][i] == 1)
			{
				if (i == j && ptrArrOut[i][j] == ptrArrOut[j][i]){
					oriented = true;
					goto brk;
				}
				if (ptrArrOut[i][j] == ptrArrOut[j][i] == 1)
					oriented = false;
				else {
					oriented = true;
					goto brk;
				}

			}
		}
	}

brk:

	switch (!oriented)
	{
	case true:
	{
		out << "YES";
		break;
	}
	case false:
		out << "NO";
		break;
	}

	for (int i = 0; i < n; i++)
		delete[] ptrArrOut[i];
	delete[] ptrArrOut;

	return 0;
}