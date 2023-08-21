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

#define MAX 105
#define MOD 1000000007

int a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int ans = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			if (a[i]) {
				ans = max(ans, cur);
				cur = 0;
			} else {
				cur++;
			}
		}
		ans = max(ans, cur);
		cout << ans << endl;
	}
}