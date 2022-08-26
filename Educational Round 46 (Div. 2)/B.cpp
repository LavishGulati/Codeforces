#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
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

	ll n, m;
	cin >> n >> m;

	ll *a = new ll[n+2];
	a[0] = 0;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	a[n+1] = m;

	ll *start = new ll[n+2];
	for(ll i = 1; i < n+2; i += 2){
		start[i] = a[i]-a[i-1];
	}
	for(ll i = 3; i < n+2; i++){
		start[i] += start[i-2];
	}

	ll *end = new ll[n+2];
	for(ll i = n+1 - (n+1)%2; i > 0; i -= 2){
		end[i] = a[i]-a[i-1];
	}
	for(ll i = n+1 - (n+1)%2 - 2; i >= 0; i -= 2){
		end[i] += end[i+2];
	}

	ll ans = start[(n+1) - !((n+1)%2)], s;
	for(ll i = 0; i < n+1; i++){
		if(i%2){
			s = start[i];
			s += a[i+1]-a[i]-1;
			if(i+3 < n+2){
				s += end[i+3];
			}
		}
		else{
			s = 0;
			if(i-1 >= 0){
				s += start[i-1];
			}
			s += a[i+1]-a[i]-1;
			if(i+2 < n+2){
				s += end[i+2];
			}
		}
		ans = max(ans, s);
	}
	cout << ans << endl;
}