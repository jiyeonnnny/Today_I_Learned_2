#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	long long answer = 1;
	for (int i = 1; i <= n; i++) {
		answer *= i;
	}
	cout << answer << "\n";
	return 0;
}

// 1차 fail 원인 : type 범위