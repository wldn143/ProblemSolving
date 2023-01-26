#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int h, w;

int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; i++)
	{
		int idx = -1;
		for (int j = 0; j < w; j++)
		{
			char c;
			cin >> c;

			if (c == 'c')
			{
				idx = 0;
				cout << idx << " ";
			}
			else if (idx != -1)
			{
				idx++;
				cout << idx << " ";
			}
			else if (idx == -1)
			{
				cout << idx << " ";
			}
		}
		cout << "\n";
	}
}