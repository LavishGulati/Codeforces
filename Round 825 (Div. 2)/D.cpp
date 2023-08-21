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

		string s;
		cin >> s;

		n *= 2;

		vector<int> change;
		int num = 0, ones = 0;
		for (int i = 0; i < n; i += 2) {
			if (s[i] == '1') {
				ones++;
			}
			if (s[i+1] == '1') {
				ones++;
			}
			if (s[i] != s[i+1]) {
				if (s[i]-'0' == num%2) {
					change.pb(i);
				} else {
					change.pb(i+1);
				}
				num++;
			}
		}

		if (ones%2) {
			cout << -1 << endl;
			continue;
		}

		cout << change.size() << " ";
		for (int id : change) {
			cout << id+1 << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i += 2) {
			cout << i+1 << " ";
		}
		cout << endl;
	}
}