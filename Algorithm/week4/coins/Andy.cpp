#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

int T;
int N;
int C[20];
int M;

int d[20][1001];
int result;

void init()
{
  cin >> N;
  for (int i=0; i<N; i++)
  {
    cin >> C[i];
  }
  cin >> M;

  memset(d, 0x00, sizeof(d));
  result = 0;
}

int main()
{
  cin >> T;

  for (int test_case=0; test_case<T; test_case++)
  {
    // input
    init();

    // process
    // 첫번째 코인의 배수에 모두 1씩 경우의 수 추가해주기
    for (int coin=C[0]; coin<=M; coin+=C[0])
      d[0][coin]++;

    // 새로운 코인이 추가될 때 앞의 경우를 고려하여 경우의 수 구하기
    for (int i=1; i<N; i++)
    {
      int coin = C[i];

      // 앞의 케이스 복사
      for (int j=1; j<=M; j++)
        d[i][j] = d[i-1][j];

      for (int j=1; j<=M; j++) // j를 만들 수 있는 경우의 수는
      {
        if (coin < j) // 새로운 코인이 추가될 수 없을때. 앞의 경우의 수와 같다
        {
          continue;
        }
        else // 그렇지 않을 때에는
        {
          for (int k=1; k*coin<=j; k++) // 코인이 k개 들어갈 때 남은 동전과 함께 금액을 구성할 수 있는지 확인해보자
          {
            if (j == k*coin) // 코인이 똑 떨어질 때에는 다른 코인이 필요 없다
              d[i][j]++;
            else if (d[i-1][j-k*coin]) // 그렇지 않을 때에는 나머지 동전으로 남은 금액을 구성할 수 있어야만 가능하다.
              d[i][j]++;
            else
              continue;
          }
        }
      }
    }

    // result
    cout << d[N-1][M] << endl;
  }
}
