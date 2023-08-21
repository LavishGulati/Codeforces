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

#define MAX 200005
#define MOD 1000000007

int l[MAX], r[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> l[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> r[i];
		}

		int s = 0, c = 0, ans = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (l[i] == r[i]) {
				c++;
			} else {
				s += r[i]-l[i]+1;
			}

			if (s+c < k) {
				// do nothing
			} else if (s < k) {
				ans = min(ans, r[i] + 2 * (i+1-c + k-s));
			} else {
				ans = min(ans, r[i] - (s-k) + 2 * (i+1-c));
			}
		}
		cout << (ans == INT_MAX ? -1 : ans) << endl;
	}
}