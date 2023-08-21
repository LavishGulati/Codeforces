#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair< int, pair<int, int> > tii;
typedef pair< long long, pair<long long, long long> > tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		if (s == "^") {
			cout << 1 << endl;
			continue;
		}

		int n = s.length();
		int ans = 0;
		if (s[0] == '_') {
			ans++;
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == '_') {
				if (i+1 < n && s[i+1] == '_') {
					ans++;
				} else if (i+1 >= n) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}