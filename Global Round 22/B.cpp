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
		int n, k;
		cin >> n >> k;

		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}

		vector<int> v;
		bool poss = true;
		for (int i = k-1; i > 0; i--) {
			if (v.size() > 0 && a[i]-a[i-1] > v.back()) {
				poss = false;
				break;
			}
			v.pb(a[i]-a[i-1]);
		}
		int rem = a[0], m = n-k+1;

		if (!poss) {
			cout << "No" << endl;
			continue;
		}

		if (v.size() > 0 && ceil(double(rem)/m) > v.back()) {
			poss = false;
		}
		cout << (poss ? "Yes" : "No") << endl;
	}
}