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
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		if (a[n-1] == 1) {
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;
		int ei = n-1;
		while (ei >= 0) {
			int si = ei-1, ones = 0;
			while (si >= 0 && !(a[si] == 0 && a[si+1] == 1)) {
				if (a[si] == 1) {
					ones++;
				}
				si--;
			}
			for (int i = 0; i < ei-si-1; i++) {
				cout << 0 << " ";
			}
			cout << ones << " ";
			ei = si;
		}
		cout << endl;
	}
}