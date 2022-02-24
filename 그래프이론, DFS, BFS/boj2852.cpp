e<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
using namespace std;
int n, winteam, curTime, isWinning, prevTime;
int score[3], teamWinningTime[3];
string inputTime;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> winteam >> inputTime;
		score[winteam]++;
		curTime = ((inputTime[0] - '0') * 10 + inputTime[1] - '0') * 60 + ((inputTime[3] - '0') * 10 + inputTime[4] - '0');

		teamWinningTime[isWinning] += curTime - prevTime;

		prevTime = curTime;

		isWinning = score[2] > score[1] ? 2 : score[1] > score[2] ? 1 : 0;
	}
	teamWinningTime[isWinning] += (48 * 60) - prevTime;//마지막에 이긴 팀

	printf("%02d:%02d\n", teamWinningTime[1] / 60, teamWinningTime[1] % 60);
	printf("%02d:%02d\n", teamWinningTime[2] / 60, teamWinningTime[2] % 60);
}
