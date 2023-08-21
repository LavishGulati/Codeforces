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

#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	unordered_map<ll, ll> mp;
	unordered_map< ll, unordered_set<ll> > rev;
	unordered_set<ll> seen;
	seen.insert(0);

	while (n--) {
		char query;
		ll x;
		cin >> query >> x;

		if (query == '+') {
			seen.insert(x);
			if (mp.find(x) == mp.end()) {
				mp[x] = x;
				rev[x].insert(x);
			}

			for (ll key : rev[x]) {
				while (seen.find(mp[key]) != seen.end()) {
					mp[key] += key;
				}
				rev[mp[key]].insert(key);
			}
			rev.erase(x);
		} else {
			if (mp.find(x) != mp.end()) {
				cout << mp[x] << endl;
			} else {
				cout << x << endl;
			}
		}
	}
}