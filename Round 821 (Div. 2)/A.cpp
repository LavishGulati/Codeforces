#include <bits/stdc++.h>
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
int help[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < k; i++) {
			help[i] = -1;
		}

		for (int i = 0; i < k; i++) {
			int j = i;
			while (j < n) {
				help[i] = max(help[i], a[j]);
				j += k;
			}
		}

		ll ans = 0;
		for (int i = 0; i < k; i++) {
			ans += help[i];
		}
		cout << ans << endl;
	}
}