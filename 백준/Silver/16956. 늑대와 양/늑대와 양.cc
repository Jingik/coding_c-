#include <iostream>
#include <string>
using namespace std;

int r, c;
string a[500];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		cin >> a[i];

	bool isSheep = false;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			if (a[i][j] == 'S') {
				for (int k = 0; k < 4; ++k) {
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (!(0 <= ny && ny < r && 0 <= nx && nx < c)) continue;

					if (a[ny][nx] == 'W')
						isSheep = true;
				}
			}
		}

	if (isSheep)
		cout << 0 << "\n";
	else {
		cout << 1 << "\n";
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j) {

				if (a[i][j] == 'S') {

					for (int k = 0; k < 4; ++k) {
						int ny = i + dy[k];
						int nx = j + dx[k];

						if (!(0 <= ny && ny < r && 0 <= nx && nx < c)) continue;

						if (a[ny][nx] == '.')
							a[ny][nx] = 'D';
					}
				}
			}

		for (int i = 0; i < r; ++i)
			cout << a[i] << "\n";
	}
	return 0;
}