#include <iostream>
#include <cstdio>
#include <memory.h>

using namespace std;

int T,N,M;
int C[20];

// user
int d[20][10000];

int main()
{
	cin >> T;

	for (int test_case=0; test_case<T; test_case++)
	{
		// input and initiation
		cin >> N;
		for (int i=0; i<N; i++)	cin >> C[i];
		cin >> M;

		// initiation
		memset(d, 0x00, sizeof(d));
		int coin = C[0];
		for (int x = coin; x<=M; x+=coin) d[0][x] = 1;

		// process
		for (int step = 1; step<N; step++)
		{
			// copy previous step
			for (int amount=1; amount<=M; amount++)
				d[step][amount] = d[step-1][amount];

			// lets consider the new coin
			coin = C[step];
			for (int amount=1; amount <=M; amount++)
			{
				// how many coins can fit in amount?
				for (int count=1; count*coin<=amount; count++)
				{
					int diff = amount - count*coin;
					
					if (diff == 0)
					{
						d[step][amount]++;
					}
					else
					{
						if (d[step-1][diff] != 0)
							d[step][amount] += d[step-1][diff];

					}
				}
			
			}
			#ifdef DEBUG
			for (int i=1; i<=M; i++)
			{
				cout << d[step][i] << " ";
			}	
			cout << endl;
			#endif

		}	
		cout << d[N-1][M] << endl;
	}
}

		

		

