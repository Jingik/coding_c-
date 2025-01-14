#include <cstdio>

#define MAX_N		1023

typedef long long ll;

ll nos[MAX_N];

int main() {
	int s, e, i, t;
	ll cur;

	for (s = e = 0; e < 10; ++e) nos[e] = e;
	--e;

	while (s <= e) {
		cur = nos[s++];
		t = cur % 10;
		for (i = 0; i < t; ++i) nos[++e] = cur * 10 + i;
	}

	scanf("%d", &t);
	printf("%lld", (t < 1023) ? nos[t]: -1);

	return 0;
}
