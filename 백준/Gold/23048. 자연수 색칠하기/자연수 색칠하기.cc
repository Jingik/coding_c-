#include <iostream>
#include <vector>

using namespace std;

int Color[500001] = {};

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	Color[1] = 1;
	int ColorCnt = 1;

	for (int i = 2; i <= N; ++i)
	{
		int Num = i;
		
		if (Color[i] != 0)
			continue;

		++ColorCnt;

		while (Num <= N)
		{
			Color[Num] = ColorCnt;
			Num += i;
		}
	}

	cout << ColorCnt << '\n';
	for (int i = 1; i <= N; ++i)
	{
		cout << Color[i] << ' ';
	}

}