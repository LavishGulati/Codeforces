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

map< ll, multiset<ll> > height, width;

bool check(ll h, ll w, map< ll, multiset<ll> > height, map< ll, multiset<ll> > width) {
	ll newh, neww;
	bool checkh, checkw;
	while (!height.empty()) {
		newh = -1; neww = -1;
		checkh = false; checkw = false;
		auto it = height.find(h);
		if (it != height.end()) {
			newh = h;
			while (height[h].size()) {
				auto it2 = height[h].begin();
				neww = *it2;
				w -= neww;
				height[h].erase(it2);
				it2 = width[neww].find(h);
				width[neww].erase(it2);
				if (width[neww].empty()) {
					width.erase(neww);
				}
			}
			height.erase(h);
			checkh = true;
			continue;
		}
		it = width.find(w);
		if (it != width.end()) {
			neww = w;
			while (width[w].size()) {
				auto it2 = width[w].begin();
				newh = *it2;
				h -= newh;
				width[w].erase(it2);
				it2 = height[newh].find(w);
				height[newh].erase(it2);
				if (height[newh].empty()) {
					height.erase(newh);
				}
			}
			width.erase(w);
			checkw = true;
		}
		if (!checkh && !checkw) {
			return false;
		}
	}
	if (checkh) {
		return h == newh && w == 0;
	} else if (checkw) {
		return h == 0 && w == neww;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		height.clear();
		width.clear();
		ll area = 0, h, w;
		for (ll i = 0; i < n; i++) {
			cin >> h >> w;
			height[h].insert(w);
			width[w].insert(h);
			area += h*w;
		}

		vector<pll> output;
		h = -1; w = -1;
		h = height.rbegin()->first;
		if (area%h == 0) {
			w = area / h;
			if (check(h, w, height, width)) {
				output.pb(mp(h, w));
			}
		}

		ll neww = width.rbegin()->first;
		if (neww != w && area%neww == 0) {
			h = area / neww;
			if (check(h, neww, height, width)) {
				output.pb(mp(h, neww));
			}
		}

		cout << output.size() << endl;
		for (auto& it : output) {
			cout << it.f << " " << it.s << endl;
		}
	}
}