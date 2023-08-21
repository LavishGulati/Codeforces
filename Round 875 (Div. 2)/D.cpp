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
#define SQRTMAX 635
#define MOD 1000000007
 
ll a[MAX], b[MAX];
int freq[SQRTMAX][MAX];
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll limit = sqrt(n*2);
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (ll i = 0; i < n; i++) {
			cin >> b[i];
			if (a[i] <= limit) {
				freq[a[i]][b[i]]++;
			} 
		}
		
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			if (a[i] <= limit && a[i]*a[i]-b[i] >= 1 && a[i]*a[i]-b[i] <= n) {
				ans += freq[a[i]][a[i]*a[i]-b[i]];
			}
		}
		for (ll i = 2; i <= limit; i += 2) {
			ans -= freq[i][i*i/2];
		}
		ans /= 2;
 
		for (ll i = 0; i < n; i++) {
			for (ll j = 1; j <= limit && j <= min(a[i]-1, 2*n/a[i]); j++) {
				if (a[i]*j-b[i] >= 1 && a[i]*j-b[i] <= n) {
					ans += freq[j][a[i]*j-b[i]];
				}
			}
		}
		for (ll i = 0; i < n; i++) {
			if (a[i] <= limit) {
				freq[a[i]][b[i]] = 0;
			}
		}
		cout << ans << endl;
	}
}