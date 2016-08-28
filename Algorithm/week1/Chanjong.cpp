#include <iostream>
using namespace std;

#define CLOCKNUMBER	16
#define BTNUMBER	10
#define INF 987654321

int __clock[CLOCKNUMBER];
int btCnt[BTNUMBER] = {3,4,4,5,5,4,3,5,5,5};
int bt[BTNUMBER][5] = {
	{ 0, 1, 2,-1, -1},
	{ 3, 7, 9,11, -1},
	{ 4,10,14,15, -1},
	{ 0, 4, 5, 6,  7},
	{ 6, 7, 8,10, 12},
	{ 0, 2,14,15, -1},
	{ 3,14,15,-1, -1},
	{ 4, 5, 7,14, 15},
	{ 1, 2, 3, 4,  5},
	{ 3, 4, 5, 9, 13}
};

int mincnt = INF;
int MIN(int x, int y) {
	if (x < y) return x;
	return y;
}

void dfs(int btNum, int cnt)
{
	for (int i = 0; i <= CLOCKNUMBER; i++)
	{
		if (i == CLOCKNUMBER)
		{
			if(mincnt>cnt) mincnt = cnt;
			return;
		}
		if (__clock[i] != 0) break;
	}

	if (btNum >= BTNUMBER || mincnt <= cnt) return;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < btCnt[btNum]; j++)
		{
			__clock[bt[btNum][j]] = ((__clock[bt[btNum][j]]+3)%12);
		}
		dfs(btNum + 1, cnt + ((i + 1) % 4));
	}
	return;
}

void process()
{
	mincnt = INF;
	for (int i = 0; i < CLOCKNUMBER; i++) cin >> __clock[i];
	for (int i = 0; i < CLOCKNUMBER; i++) __clock[i] %= 12;

	dfs(0, 0);

	if (mincnt == INF) mincnt = -1;
	cout << mincnt << endl;
}
int main()
{
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) process();

	return 0;
}
