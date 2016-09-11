#include <stdio.h>

#define MAX (1 << 9)

int point[4][2] = { { 0, 0 }, { 1, 0 }, { 0, 1 }, { 1, 1 } };
int tile[4][4] = {
    { 1, 1, 1, 0 }, //「 (0)
    { 1, 1, 0, 1 }, // ㄱ(1)
    { 1, 0, 1, 1 }, // ㄴ(2)
    { 0, 1, 1, 1 }  // 」(3)
};
int map[MAX + 2][MAX + 2];
int sx, sy;
int answer;
int N;

void makeTile(int x, int y, int n, int type) {
    if (n == 1) {
        answer++;
        for (int p = 0; p < 4; p++) {
            int px = x + (point[p][0] << (n - 1));
            int py = y + (point[p][1] << (n - 1));
            if (tile[type][p]) map[py][px] = answer;
        }
        return;
    }

    makeTile(x + (1 << (n - 2)), y + (1 << (n - 2)), n - 1, type);
    for (int p = 0; p < 4; p++) {
        if (tile[type][p]) {
            int px = x + (point[p][0] << (n - 1));
            int py = y + (point[p][1] << (n - 1));
            makeTile(px, py, n - 1, p);
        }
    }
}

void search(int x, int y, int n) {
    if (n == 0) { map[y][x] = 0; return; }

    for (int p = 0; p < 4; p++) {
        int px = point[p][0] << (n - 1);
        int py = point[p][1] << (n - 1);
        if (((x + px) <= sx && sx <= (x + (1 << (n - 1)) + px - 1)) &&
            ((y + py) <= sy && sy <= (y + (1 << (n - 1)) + py - 1))) {
            search(x + px, y + py, n - 1);
            makeTile(x, y, n, 3 - p);
            break;
        }
    }
}

void printMap() {
    for (int y = 1; y <= (1 << N); y++) {
        for (int x = 1; x <= (1 << N); x++)
            printf("%d ", map[y][x]);
        printf("\n");
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d %d", &sy, &sx);

    search(1, 1, N);

    printMap();

    return 0;
}
