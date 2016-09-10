#include <iostream>
using namespace std;

#define CLOCKNUMBER	16
#define BTNUMBER	10
#define INF 987654321

int __clock[CLOCKNUMBER];//Clock Status Array
int btCnt[BTNUMBER] = {3,4,4,5,5,4,3,5,5,5}; //a number of clocks depends on button
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
}; //Button options

int mincnt = INF; //Initilize of minimum integer

int MIN(int x, int y) // Return smaller integer
{
	if (x < y) return x;
	return y;
}

void dfs(int btNum, int cnt)
{
	for (int i = 0; i <= CLOCKNUMBER; i++)
	{
		if (i == CLOCKNUMBER)//All checked
		{
			if(mincnt>cnt) mincnt = cnt;
			return;
		}//all clocks are 0
		if (__clock[i] != 0) break; //clock[i] is not 0(12)
	}//Check current Clocks' status

	if (btNum >= BTNUMBER/*10*/ || mincnt <= cnt) return; //cnt is larger than minimun cnt or btNumber is overed

	for (int i = 1; i <= 4; i++)//push clock button
	{
		for (int j = 0; j < btCnt[btNum]; j++)
		{
			__clock[bt[btNum][j]] = ((__clock[bt[btNum][j]]+3)%12);
		} //Change clocks status

		dfs(btNum + 1, cnt + (i % 4)); //go to the other status
	}
	
	return;
}

void process()
{
	mincnt = INF;//initialize of minimum data
	for (int i = 0; i < CLOCKNUMBER; i++) cin >> __clock[i]; //input of clock
	for (int i = 0; i < CLOCKNUMBER; i++) __clock[i] %= 12;  //change 12 O'clock  to  0 O'clock

	dfs(0, 0); //dfs start

	if (mincnt == INF) mincnt = -1; //if it is impossible.... cout -1
	cout << mincnt << endl;
}
int main()
{
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) process();

	return 0;
}
