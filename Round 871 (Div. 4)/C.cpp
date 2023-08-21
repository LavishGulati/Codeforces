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
		int n;
		cin >> n;

		unordered_map<string, int> mp;
		int x;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> x >> s;
			if (mp.find(s) != mp.end()) {
				mp[s] = min(mp[s], x);
			} else {
				mp[s] = x;
			}
		}

		int ans = INT_MAX;
		if (mp.find("11") != mp.end()) {
			ans = min(ans, mp["11"]);
		}
		if (mp.count("10") && mp.count("01")) {
			ans = min(ans, mp["10"]+mp["01"]);
		}
		cout << (ans == INT_MAX ? -1 : ans) << endl;
	}
}