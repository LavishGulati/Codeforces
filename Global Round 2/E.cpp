#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pq priority_queue

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	ll *a = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}

	ll ans = 0, cnt1 = 0, x;
	for(ll i = 0; i < n; i++){
		if(cnt1 > 0){
			x = min(cnt1, a[i]/2);
			ans += x;
			a[i] -= 2*x;
			cnt1 -= x;
		}

		x = a[i]/3;
		a[i] -= 3*x;
		ans += x;
		cnt1 += a[i];
	}

	cout << ans << endl;
}