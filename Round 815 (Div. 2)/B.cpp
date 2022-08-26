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

#define MAX 100005
#define MOD 1000000007

ll a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		ll max1 = 0, max2 = 0, min1 = INT_MAX, min2 = INT_MAX;
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] > max1) {
				max2 = max1;
				max1 = a[i];
			} else if (a[i] > max2) {
				max2 = a[i];
			}

			if (a[i] < min1) {
				min2 = min1;
				min1 = a[i];
			} else if(a[i] < min2) {
				min2 = a[i];
			}
		}
		cout << max1+max2-min1-min2 << endl;
	}
}