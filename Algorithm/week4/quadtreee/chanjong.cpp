#include <iostream>
using namespace std;

int ary[513][513];
int N;
char hexa[17] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };


class square
{
public:
	int y;
	int x;
	int len;

	square()
	{
		y = x = len = 0;
	};
	square(int a, int b, int c)
	{
		y = a;
		x = b;
		len = c;
	};
	~square()
	{};
	void operator = (const square right)
	{
		x = right.x;
		y = right.y;
		len = right.len;
	};
};

square que[10000];
int head = 0;
int tail = 0;

void enque(square in)
{
	que[(++head)%10000] = in;
}

square deque()
{
	return que[(++tail)%10000];
}

int isEmpty()
{
	if (head == tail) return 1;
	return 0;
}

int binaryToHex(char binary[], int size, char dst[])
{
	char src[300000] = { 0 };
	int mod = 4-(size % 4);
	if (mod == 4) mod = 0;

	int dstIter = 0;
	for (int i = 0; i < size; i++) src[mod + i] = binary[i]-'0';
	
	for (int i = 0; i < size + mod; i++)
	{
		if (i % 4 == 3)
		{
			int dec = (src[i] * 1) + (src[i - 1] * 2) + (src[i - 2] * 4) + (src[i - 3] * 8);
			dst[dstIter++] = hexa[dec];
		}
	}
	return dstIter;
}

void bfs()
{
	enque(square(0, 0, N));
	char result[300000];
	char hexaRes[100000];
	int iteration = 0;

	while (!isEmpty())
	{
		square sq = deque();
		int prev = ary[sq.y][sq.x];
		for (int i = sq.y; i < sq.y + sq.len; i++)
		{
			for (int j = sq.x; j < sq.x + sq.len; j++)
			{
				if (ary[i][j] != prev) prev = -1;
			}
		}

		if (prev != -1)
		{
			result[iteration++] = '0';
			result[iteration++] = ('0' + prev);
		}
		else
		{
			result[iteration++] = '1';
			enque(square(sq.y, sq.x, sq.len >> 1));
			enque(square(sq.y, sq.x + (sq.len >> 1), sq.len >> 1));
			enque(square(sq.y + (sq.len>>1), sq.x, sq.len >> 1));
			enque(square(sq.y + (sq.len >> 1), sq.x + (sq.len >> 1), sq.len >> 1));
		}
	}

	int resSize = binaryToHex(result, iteration, hexaRes);
	
	for (int i = 0; i < resSize; i++)
		cout << hexaRes[i];
	cout << endl;
}


int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> ary[i][j];
		}
	}

	bfs();

	return 0;
}
