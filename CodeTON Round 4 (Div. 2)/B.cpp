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

vector<int> ans;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ans.clear();

		if (!(n%2)) {
			cout << -1 << endl;
			continue;
		}

		n = (n-1)/2;

		while (n > 1) {
			if (n%2) {
				ans.pb(2);
			} else {
				ans.pb(1);
			}
			n /= 2;
		}
		ans.pb(2);

		cout << ans.size() << endl;
		for (int i = ans.size()-1; i >= 0; i--) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}