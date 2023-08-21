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

#define MAX 300005
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

		if (n == 1) {
			cout << 1 << endl;
			continue;
		}

		int ans = 1;
		int inc;
		if (a[1] > a[0]) {
			inc = 1;
		} else if (a[1] == a[0]) {
			inc = 0;
		} else {
			inc = -1;
		}

		for (int i = 1; i < n-1; i++) {
			if (inc == 0) {
				if (a[i+1] > a[i]) {
					inc = 1;
				} else if (a[i+1] < a[i]) {
					inc = -1;
				}
			} else if (inc == 1) {
				if (a[i+1] >= a[i]) {
					// do nothing
				} else {
					ans++;
					inc = -1;
				}
			} else if (inc == -1) {
				if (a[i+1] <= a[i]) {
					// do nothing
				} else {
					ans++;
					inc = 1;
				}
			}
		}

		if (inc == 0) {
			cout << 1 << endl;
		} else {
			cout << ans+1 << endl;
		}
	}
}