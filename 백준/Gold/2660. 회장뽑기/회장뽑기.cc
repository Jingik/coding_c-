#include <iostream>
#include <vector>

using namespace std;

int n; 
int score[51];
vector <int> V[51];

int dist[51][51];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)continue;
			else dist[i][j] = 1000000000;
		}
	}

	int x, y;
	while (true)
	{
		cin >> x >> y;

		if (x == y)break;

		dist[x][y] = 1;
		dist[y][x] = 1;
	}

	for (int t = 1; t <= n; t++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][t] + dist[t][j]) {
					dist[i][j] = dist[i][t] + dist[t][j];
				}
			}
		}
	}

	int score[51];
	int member = -1;
	for (int i = 1; i <= n; i++)
	{
		int m = 0;
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] > m) m = dist[i][j];
		}
		score[i] = m;
		if (member > m || member == -1) member = m;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (score[i] == member) cnt++;
	}

	cout << member << " " << cnt << "\n";
	for (int i = 1; i <= n; i++)
	{
		if (score[i] == member) cout << i << " ";
	}

	return 0;
}