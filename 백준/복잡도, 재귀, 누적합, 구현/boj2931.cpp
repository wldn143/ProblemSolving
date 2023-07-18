#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int r, c;
char map[26][26];
int visited[26][26];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int pipe0[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //|, -
int pipe1[2][2] = {{0, 1}, {1, 0}};
int pipe2[2][2] = {{-1, 0}, {0, 1}};
int pipe3[2][2] = {{0, -1}, {-1, 0}};
int pipe4[2][2] = {{0, -1}, {1, 0}};
int open[4] = {0, 0, 0, 0};