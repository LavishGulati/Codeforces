#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	ll *a1 = new ll[n1];
	ll tot1 = 0;
	for(ll i = 0; i < n1; i++){
		cin >> a1[i];
		tot1 += a1[i];
	}

	ll *a2 = new ll[n2];
	ll tot2 = 0;
	for(ll i = 0; i < n2; i++){
		cin >> a2[i];
		tot2 += a2[i];
	}

	ll *a3 = new ll[n3];
	ll tot3 = 0;
	for(ll i = 0; i < n3; i++){
		cin >> a3[i];
		tot3 += a3[i];
	}

	sort(a1, a1+n1);
	sort(a2, a2+n2);
	sort(a3, a3+n3);

	ll x = min(tot1, min(tot2, tot3));
	x = min(x, a1[0]+a2[0]);
	x = min(x, a1[0]+a3[0]);
	x = min(x, a2[0]+a3[0]);
	cout << ll(tot1+tot2+tot3-2*x) << endl;
}