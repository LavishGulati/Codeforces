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

#define MAX 100005
#define MOD 1000000007

int a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int l, r;
		cin >> l >> r;
		l--; r--;

		ll sum = 0, help = 0;
		for (int i = l; i <= r; i++) {
			sum += a[i];
			help ^= a[i];
		}
		ll target = sum-help;

		int x = l, y = l+1, left = l, right = r+1;
		sum = a[x]; help = a[x];
		while (x <= r) {
			while (y <= r && sum-help < target) {
				sum += a[y];
				help ^= a[y];
				y++;
			}
			if (sum-help == target && y-x < right-left) {
				left = x;
				right = y;
			}

			sum -= a[x];
			help ^= a[x];
			x++;
			if (y <= x) {
				y = x+1;
				sum = a[x];
				help = a[x];
			}
		}

		cout << left+1 << " " << right << endl;
	}
}