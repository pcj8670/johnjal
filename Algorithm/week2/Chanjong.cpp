 #include <iostream>
using namespace std;

#define _X	0
#define _Y	1
#define QSIZE 10010

struct Point
{
	int x;
	int y;
	int t;
}; //현재 좌표와 시작지점으로부터 거리를 저장하기 위한 구조체

int T,K;
int ary[102][102]; // 지도
Point water;	//홍수 시작 지점
Point _queue[QSIZE+2];
int head = 0;
int tail = 0;

int d[2][4] = { //현재위치에서 다음 위치 4방향
	{0, 0, 1, -1}, //다음 x좌표
	{1,-1, 0,  0}  //다음 y좌표
};

void push(Point data)
{
	_queue[(++head)%QSIZE] = data;
}
Point pop()
{
	return _queue[(++tail)%QSIZE];
}
int isEmpty()
{
	if (head == tail) return 1;
	return 0;
}

void process()
{
	int resultCount = 0;

	cin >> T; //배열사이즈 입력
	for (int i = 1; i <= T; i++)
	{
		for (int j = 1; j <= T; j++) cin >> ary[i][j]; //배열입력
	}
	cin >> water.x >> water.y >> K; //시작 지점 입력
	water.t = 0; //시작지점 경과시간 0
	push(water); //시작지점 push
	ary[water.y][water.x] = 1; //시작지점은 이미 물이있으니 1


	while (!isEmpty()) //큐가 비어있으면 모든 상황 종료
	{
		Point c = pop(); //현재 Point 수신
		if (c.t > K) break; //필요없는 구간(최적 댐건설 위치보다 먼곳)
		else if (c.t == K) resultCount++;
		//cout << c.y << " , " << c.x << " / " << c.t << endl;

		for (int i = 0; i < 4; i++)
		{
			Point next;
			next.x = c.x + d[_X][i]; //다음 x좌표 저장
			next.y = c.y + d[_Y][i]; //다음 y좌표 저장
			next.t = c.t + 1; //다음 지점 거리
			if (ary[next.y][next.x] == 0) push(next); //다음 위치 Push
			ary[next.y][next.x] = 1; //이미 물이찬곳은 1
		}
	}
	if (resultCount == 0) cout << "OH, MY GOD" << endl;
	else cout << resultCount << endl;
}

int main()
{
	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++) ary[i][j] = -1;
	}//초기화
	process();//계산
	return 0;
}
