#include <iostream>
#include <string>

using namespace std;

void solve(void)
{
	string bits;
	cin >> bits;

	int idx = 0;
	bool continue_flag = true;
	while (idx < bits.size() && continue_flag)
	{
		switch (bits[idx])
		{
		case '0':
			idx++;
			if (bits.size() <= idx || '0' == bits[idx])
				continue_flag = false;
			idx++;
			break;

		case '1':
			idx++;

			int next_1 = bits.find('1', idx);
			if (next_1 == string::npos || next_1 - idx < 2)
			{
				continue_flag = false;
				break;
			}

			int next_0 = bits.find('0', next_1);
			if (next_0 == bits.size() - 1)
			{
				continue_flag = false;
				break;
			}

			if (next_0 == string::npos)
			{
				idx = bits.size();
				break;
			}
			idx = next_0;
			if ('0' == bits[next_0 + 1] && 1 < next_0 - next_1)
				idx--;
			break;
		}
	}

	cout << (idx == bits.size() && continue_flag ? "YES" : "NO") << '\n';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int test_case;
	cin >> test_case;
	for (int t = 0; t < test_case; t++)
		solve();
}
