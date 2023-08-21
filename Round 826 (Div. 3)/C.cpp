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

#define MAX 2005
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

		int ans = n, l, r, cur;
		ll pref = 0, sum;
		bool poss;
		for (int j = 0; j < n-1; j++) {
			pref += a[j];
			l = j+1;
			cur = j+1;
			poss = true;
			while (l < n) {
				r = l;
				sum = 0;
				while (r < n && sum < pref) {
					sum += a[r];
					r++;
				}
				if (sum != pref) {
					poss = false;
					break;
				}
				cur = max(cur, r-l);
				l = r;
			}
			if (poss) {
				ans = min(ans, cur);
			}
		}

		cout << ans << endl;
	}
}