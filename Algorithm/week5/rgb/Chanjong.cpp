#include <iostream>
using namespace std;

int ary[1001][3];
int cache[1001][4];
int N;
#define INF 987654321

#define FORBID_RED	0
#define FORBID_GREEN	1
#define FORBID_BLUE	2
#define ALL_OK	3

#define RED	0
#define GREEN	1
#define BLUE	2

int MIN(int x, int y)
{
	if (x < y) return x;
	return y;
}

int dp(int n, int status)
{
	if (n == N) return 0;

	if (cache[n][status] != -1 ) return cache[n][status];
	int& ret = cache[n][status];
	ret = INF;

	if (status != FORBID_RED) ret = MIN(ret, dp(n + 1, FORBID_RED) + ary[n][RED]);
	if (status != FORBID_GREEN) ret = MIN(ret, dp(n + 1, FORBID_GREEN) + ary[n][GREEN]);
	if (status != FORBID_BLUE) ret = MIN(ret, dp(n + 1, FORBID_BLUE) + ary[n][BLUE]);

	return ret;
}

int main()
{
	for (int i = 0; i < 1001; i++)
		cache[i][0] = cache[i][1] = cache[i][2] = cache[i][3] = -1;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> ary[i][0] >> ary[i][1] >> ary[i][2];

	int min_Pay = dp(0, ALL_OK);
	
	cout << min_Pay << endl;

	return 0;
}
