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

#define MAX 25
#define MOD 1000000007

int a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int gcd;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i == 0) {
				gcd = a[i];
			} else {
				gcd = __gcd(gcd, a[i]);
			}
		}

		if (gcd == 1) {
			cout << 0 << endl;
		} else if (__gcd(gcd, n) == 1) {
			cout << 1 << endl;
		} else if (n > 1 && __gcd(gcd, n-1) == 1) {
			cout << 2 << endl;
		} else {
			cout << 3 << endl;
		}
	}
}