#include <iostream>
#include <stdio.h>
#include "Andy.h"
using namespace std;

int switchPushed[10];
int clockstate;
int minHit;

int main()
{
	freopen("input_simple.txt", "r", stdin);

	int T;
	unsigned short switch[10] = { 0x003, 0x0a88, 0xc210, 0x00f1, 0x15c0,
				      0xc005, 0xc008, 0xc0b0, 0x0032, 0x2238 };
	cin >> T;

	for (int t=0; t<T; t++)
	{
		clockstate = 0x00;
	//	unsigned short switch[10];
		int minHit = 0x7fffffff;

		// input clock_state
		for (int i=0; i<16; i++)
		{
			int x, flag;
			cin >> x;
			flag = 0x03 << (i*2);

			switch(x)
			{
				case 3: clockstate = clockstate | (0x03 & 1) << (i*2); break;
				case 6: clockstate = clockstate | (0x03 & 2) << (i*2); break;
				case 9: clockstate = clockstate | (0x03 & 3) << (i*2); break;
				case 12: break;
			}
		}

	//	cout << "clockstate:" << clockstate << endl;

		for (int i=0; i<3; i++)	
			generateAllCase(0, i);

		cout << minHit << endl;
	}

	return 0;
}

int sumPushed()
{
	int pushed = 0;
	for (int i=0; i<10; i++)
		pushed += switchPushed[i];

	return pushed;
}

void generateAllCase(int targetSwitch, int hitn)
{
	if (targetSwitch == 10 && allClockTwelve()))
	{
		int pushed = sumPushed();
		if (pushed < minHit)
			minHit = pushed;
		return;
	}

	switchPushed[targetSwitch] = hitn;

	for (int i=0; i<3; i++)
		generateAllCase(targetSwitch +1, i);
}

int allClockTwelve()
{
	int clockstate_cp = clockstate;

	for (int i=0; i<10; i++)
	{
		int target = (0xff << (2 * i)) && clockstate_cp;
		target = target >> (2 * i);

		if (target != 0)
			

		
	}
	
}
