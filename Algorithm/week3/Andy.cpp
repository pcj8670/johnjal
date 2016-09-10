#include <iostream>
using namespace std;

int N,X,Y;
int answer[600][600] = {0};
int g_count;

inline int getTwoSquareN(int n)
{
  int result = 2;

  for (int i=1; i<n; i++)
    result = result * 2;

  return result;
}

int getFillType(int size, int base_x, int base_y, int target_x, int target_y)
{
  int half_w, half_h;
  half_w = base_x + size/2;
  half_h = base_y + size/2;

  if (target_x < half_w && target_y < half_h)
    return 1;
  else if (target_x >= half_w && target_y < half_h)
    return 2;
  else if (target_x >= half_w && target_y >= half_h)
    return 3;
  else
    return 4;
}

void solve(int size, int base_x, int base_y, int target_x, int target_y);
void fill(int size, int base_x, int base_y, int filltype);

int main()
{
  cin >> N >> X >> Y;

  // initialize
  int size = getTwoSquareN(N);
  answer[Y][X] = 0;
  g_count = 0;

  // solve problem
  solve(size, 1, 1, X, Y);

  // print answer
  for (int i=1; i<=size; i++)
  {
    for (int j=1; j<=size; j++)
    {
      cout << answer[i][j] << " ";
    }
    cout << endl;
  }
}

void solve(int size, int base_x, int base_y, int target_x, int target_y)
{
  if (size == 1)
    return;

  int filltype = getFillType(size, base_x, base_y, target_x, target_y);

  // find next base
  int next_base_x, next_base_y;
  switch (filltype)
  {
    case 1:
      next_base_x = base_x;
      next_base_y = base_y;
      break;
    case 2:
      next_base_x = base_x + size/2;
      next_base_y = base_y;
      break;
    case 3:
      next_base_x = base_x + size/2;
      next_base_y = base_y + size/2;
      break;
    case 4:
      next_base_x = base_x;
      next_base_y = base_y + size/2;
      break;
  }

  solve(size/2, next_base_x, next_base_y, target_x, target_y);
  fill(size/2, base_x, base_y, filltype);
}

void fill(int size, int base_x, int base_y, int filltype)
{
  if (size == 2)
  {
    ++g_count;
    switch(filltype)
    {
      case 1:
        answer[base_y][base_x+1] = answer[base_y+1][base_x+1] = answer[base_y+1][base_x] = g_count;
        break;
      case 2:
        answer[base_y][base_x] = answer[base_y+1][base_x+1] = answer[base_y+1][base_x] = g_count;
        break;
      case 3:
        answer[base_y][base_x] = answer[base_y][base_x+1] = answer[base_y+1][base_x] = g_count;
        break;
      case 4:
        answer[base_y][base_x] = answer[base_y][base_x+1] = answer[base_y+1][base_x+1] = g_count;
        break;
    }
  }
  else
  {
    size = size/2;
    switch(filltype)
    {
      case 1:
        fill(size, base_x + size/2, base_y + size/2, 1);
        fill(size, base_x+size, base_y, 4);
        fill(size, base_x + size, base_y + size, 1);
        fill(size, base_x, base_y + size, 2);
        break;
      case 2:
        fill(size, base_x + size/2, base_y + size/2, 2);
        fill(size, base_x, base_y, 3);
        fill(size, base_x, base_y + size, 2);
        fill(size, base_x + size, base_y + size, 1);
        break;
      case 3:
        fill(size, base_x + size/2, base_y + size/2, 3);
        fill(size, base_x, base_y, 3);
        fill(size, base_x + size, base_y, 4);
        fill(size, base_x, base_y + size, 2);
        break;
      case 4:
        fill(size, base_x + size/2, base_y + size/2, 4);
        fill(size, base_x, base_y, 3);
        fill(size, base_x + size, base_y, 4);
        fill(size, base_x + size, base_y + size, 1);
        break;
    }
  }
}
