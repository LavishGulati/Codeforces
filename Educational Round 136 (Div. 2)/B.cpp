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

int d[MAX], a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}

		bool multi = false;
		a[0] = d[0];
		for (int i = 1; i < n; i++) {
			if (d[i] == 0) {
				a[i] = a[i-1];
			} else if (a[i-1]-d[i] < 0) {
				a[i] = a[i-1]+d[i];
			} else {
				multi = true;
				break;
			}
		}

		if (multi) {
			cout << -1 << endl;
		} else {
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
}