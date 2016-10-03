#include <iostream>
#include <memory.h>
using namespace std;

int T,N,COINS[20],M;
int finished[20], d[20][10001];

// 0~c 코인을 고려하여 M 금액을 만들 수 있는 경우의 수를 알고 있을 때,
// 0~c 코인을 고려하여 M 금액을 만들 수 있는 경우의 수
// 불가능하면 return -1
void process(int c)
{
  int coin = COINS[c];

  // 기저상태처리
  if ( c>=N || c<0 ) return;
  if ( c==0 )
  {
    for (int x=1; x*coin <= M; x++) d[0][coin*x] = 1;
    finished[0] = 1;
    return;
  }

  // 재귀
  if ( finished[c-1]==-1 ) process(c-1);

  // process
  for (int x=0; x<=M; x++) d[c][x] = d[c-1][x];

  for (int cost=1; cost<=M; cost++)
  {
    if ( cost<coin )
    {
      d[c][cost] = d[c-1][cost];
      continue;
    }
    else
    {
      for (int x=1; x*coin<=cost; x++)
      {
        if ( cost==x*coin )
          d[c][cost]++;
        else if ( d[c-1][cost-x*coin] )
          d[c][cost] += d[c-1][cost-x*coin];
        else
         continue;
      }
    }
  }

  finished[c] = 1;
  return;
}

int main()
{
  cin >> T;

  for (int test_case=0; test_case<T; test_case++)
  {
    cin >> N;
    for (int i=0; i<N; i++) cin >> COINS[i];
    cin >> M;

    memset(finished, -1, sizeof(finished));
    memset(d, 0, sizeof(d));
    process(N-1);

    cout << d[N-1][M] << endl;
  }
}
