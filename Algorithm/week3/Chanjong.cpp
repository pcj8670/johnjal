#include <iostream>
using namespace std;


int ary[1100][1100];
int pow2[11] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024 };
int color = 1;
int N;

void dfs(int y, int x, int len,  int fy, int fx)
{
	int half = (len >> 1);
	if (len <= 2)
	{
		for (int i = y; i < y + len; i++)
		{
			for (int j = x; j < x + len; j++)
			{
				if (ary[i][j] == -1) ary[i][j] = color;
			}
		}
		color++;
		return;
	}
	else
	{ 
		int centerColor = color++;
		if (!(fy < y + half && fx < x + half))
		{
			ary[y + half - 1][x + half - 1] = centerColor;
			dfs(y, x, half, y + half - 1, x + half - 1);
		}
		else dfs(y, x, half, fy, fx);

		if (!(fy < y + half && fx >= x + half))
		{
			ary[y + half - 1][x + half] = centerColor;
			dfs(y, x + half, half, y + half - 1, x + half);
		}
		else dfs(y, x + half, half, fy, fx);

		if (!(fy >= y + half && fx < x + half))
		{
			ary[y + half][x + half - 1] = centerColor;
			dfs(y + half, x, half, y + half, x + half - 1);
		}
		else dfs(y + half, x, half, fy, fx);

		if (!(fy >= y + half && fx >= x + half))
		{
			ary[y + half][x + half] = centerColor;
			dfs(y + half, x + half, half, y + half, x + half);
		}
		else dfs(y + half, x + half, half, fy, fx);
	}
}
void process()
{
	for (int i = 0; i < 520; i++)
	{
		for (int j = 0; j < 520; j++) ary[i][j] = -1;
	}
	int N;
	int fy, fx;
	cin >> N >> fy >> fx;
	ary[fy][fx] = 0;

	dfs(1, 1, pow2[N], fy, fx);

	for (int i = 1; i <= pow2[N]; i++)
	{
		for (int j = 1; j <= pow2[N]; j++)
			cout << ary[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	process();
	return 0;
}
