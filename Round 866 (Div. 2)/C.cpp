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

int a[MAX];
bool pres[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i <= n+1; i++) {
			pres[i] = false;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] <= n+1) {
				pres[a[i]] = true;
			}
		}

		int mex;
		for (int i = 0; i <= n+1; i++) {
			if (!pres[i]) {
				mex = i;
				break;
			}
		}

		if (!pres[mex+1]) {
			if (mex == n) {
				cout << "No" << endl;
			} else {
				cout << "Yes" << endl;
			}
		} else {
			int si = 0;
			while (si < n && a[si] != mex+1) {
				si++;
			}
			int ei = n-1;
			while (ei >= 0 && a[ei] != mex+1) {
				ei--;
			}

			bool added = false;
			for (int i = 0; i <= mex; i++) {
				pres[i] = false;
			}
			for (int i = 0; i < si; i++) {
				pres[a[i]] = true;
			}
			for (int i = ei+1; i < n; i++) {
				pres[a[i]] = true;
			}

			bool ans = true;
			for (int i = 0; i <= mex; i++) {
				if (!pres[i]) {
					if (!added) {
						added = true;
					} else {
						ans = false;
						break;
					}
				}
			}

			cout << (ans ? "Yes" : "No") << endl;
		}
	}
}