#include <iostream>
using namespace std;

int coins[21];
int cache[21][20001];
int N;
int dfs(int c, int money, const int goal)
{
	if (c >= N) return 0;
	if (money == goal) return 1;
	
	if (money > goal) return 0;

	if (cache[c][money] != -1) return cache[c][money];
	int& ret = cache[c][money] = 0;

	ret += dfs(c, money + coins[c], goal);
	ret += dfs(c + 1, money, goal);
	
	return ret;
}

void process()
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 20001; j++) cache[i][j] = -1;
	}

	cin >> N;
	for (int i = 0; i < N; i++) cin >> coins[i];
	
	int goal = 0;
	cin >> goal;

	int result = dfs(0, 0, goal);

	cout << result << endl;
}

int main()
{
	int C;
	cin >> C;
	for (int i = 0; i < C; i++) process();
	return 0;
}
