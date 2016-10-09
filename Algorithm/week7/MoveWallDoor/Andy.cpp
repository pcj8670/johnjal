#include <iostream>
using namespace std;

int N,X,Y,M,DOOR[20];
int minOpen = 2000000000;

void process(int D1, int D2, int problem, int cost)
{
  if (problem == M)
  {
    if (cost < minOpen)
      minOpen = cost;
    return;
  }

  int target = DOOR[problem];

  // process case
  if (target == D1 || target == D2)
    process(D1, D2, problem+1, cost);
  else if (target < D1)
    process(target, D2, problem+1, cost + D1 - target);
  else if (target > D2)
    process(D1, target, problem+1, cost + target - D2);
  else
  {
    process(target, D2, problem+1, cost + target - D1);
    process(D1, target, problem+1, cost + D2 - target);
  }
}

int main()
{
  cin >> N >> X >> Y >> M;
  for (int i=0; i<M; i++) cin >> DOOR[i];

  process (X, Y, 0, 0);
  cout << minOpen << endl;
}
