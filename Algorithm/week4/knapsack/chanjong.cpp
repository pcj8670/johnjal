#include <iostream>
#include <iomanip>
using namespace std;

#define WEIGHT				0
#define VALUE				1
#define MAX(x,y) x>y ? x:y

int W, N;
int jw[101][2];
int cache[101][10001];
int maxMargin = 0;

int dfs(int w, int n) //현재 가방의 여유 무게  /  현재 몇번 보석을 보고 있는가
{
	if (n == N) return 0; //기저 상태(끝까지 돌앗을 때)

	if (cache[n][w] != 0) return cache[n][w]; //이전에 이미 해본거라면

	int& ret = cache[n][w]; //캐쉬(정답 보드)


	//다음 상태로 고고
	ret = MAX( dfs(w, n + 1), ret); //안 갖고 가는 경우
	if(w >= jw[n][WEIGHT]) ret = MAX( ret, dfs(w - jw[n][WEIGHT], n + 1) + jw[n][VALUE] ); //갖고 가는 경우

	return ret;
}

int main()
{
	cin >> W >> N;
	for (int i = 0; i < N; i++) cin >> jw[i][WEIGHT] >> jw[i][VALUE];


	cout << dfs(W, 0) << endl;

	cout << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <= 30; j++)
		{
			cout << setw(3) << cache[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}
