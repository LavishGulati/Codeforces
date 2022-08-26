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

#define MAX 505
#define MOD 1000000007

string a[MAX];
bool ind1, ind2;
int n, m;

void check(int i, int j) {
	if (i+1 < n && j+1 < m) {
		int s = a[i][j] + a[i+1][j] + a[i][j+1] - 3 * '0';
		if (s <= 1) {
			ind1 = true;
			return;
		} else if (s == 2) {
			ind2 = true;
		}
	}
	if (i+1 < n && j-1 >= 0) {
		int s = a[i][j] + a[i+1][j] + a[i][j-1] - 3 * '0';
		if (s <= 1) {
			ind1 = true;
			return;
		} else if (s == 2) {
			ind2 = true;
		}
	}
	if (i-1 >= 0 && j+1 < m) {
		int s = a[i][j] + a[i-1][j] + a[i][j+1] - 3 * '0';
		if (s <= 1) {
			ind1 = true;
			return;
		} else if (s == 2) {
			ind2 = true;
		}
	}
	if (i-1 >= 0 && j-1 >= 0) {
		int s = a[i][j] + a[i-1][j] + a[i][j-1] - 3 * '0';
		if (s <= 1) {
			ind1 = true;
			return;
		} else if (s == 2) {
			ind2 = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ind1 = ind2 = false;
		cin >> n >> m;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '1') {
					cnt++;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				check(i, j);
			}
		}

		if (ind1) {
			cout << cnt << endl;
		} else if (ind2) {
			cout << cnt-1 << endl;
		} else {
			cout << cnt-2 << endl;
		}
	}
}