#include <iostream>
using namespace std;

int d[1000][3];

int process()
{
  int N, COST[1000][3];
  cin >> N;
  for (int i=0; i<N; i++)
  {
    cin >> COST[i][0] >> COST[i][1] >> COST[i][2];

    if (i!=0)
    {
      d[i][0] = d[i][1] = d[i][2] = 2000000000;
      for (int prev_color=0; prev_color<3; prev_color++) // current color
      {
        for (int curr_color=0; curr_color<3; curr_color++) // next color
        {
          if (prev_color == curr_color) continue;

          int new_cost = d[i-1][prev_color] + COST[i][curr_color];
          int old_cost = d[i][curr_color];
          d[i][curr_color] = (new_cost < old_cost) ? new_cost : old_cost;
        }
      }
    }
    else
    {
      d[i][0] = COST[i][0];
      d[i][1] = COST[i][1];
      d[i][2] = COST[i][2];
    }
  }

  int min = 2000000000;
  for (int color=0; color<3; color++)
  {
    if (d[N-1][color] < min) min = d[N-1][color];
  }

  return min;
}

int main()
{
  int answer = process();
  cout << answer << endl;
  return 0;
}
