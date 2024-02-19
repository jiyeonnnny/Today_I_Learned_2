#include <bits/stdc++.h>
#include<string>
using namespace std;
int cnt = 0;

int recursion(string s, int left, int right) {
	cnt++;
	if (left >= right) return 1;
	else if (s[left] != s[right]) return 0;
	else return recursion(s, left + 1, right - 1);
}

int isPalindrome(string s) {
	return recursion(s, 0, s.size() - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string word;
		cin >> word;
		cnt = 0;
		cout << isPalindrome(word) << " " << cnt << "\n";
	}
	return 0;
}

// 1차 fail 원인 : 함수 인자로 string을 전달하고 받는 것에서 시간 초과 발생