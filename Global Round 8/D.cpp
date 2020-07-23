#include <bits/stdc++.h>
using namespace std;

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

	ll n;
	cin >> n;

	ll *a = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a+n);

	for(ll d = 21; d >= 0; d--){
		ll i = 0;
		ll j = n-1;
		while(i < j){
			if(!(a[i]&(1<<d))){
				i++;
			}
			else if(a[j]&(1<<d)){
				j--;
			}
			else{
				a[i] = (a[i]^(1<<d));
				a[j] = (a[j]^(1<<d));
				i++; j--;
			}
		}
	}

	ll ans = 0;
	for(ll i = 0; i < n; i++){
		ans += a[i]*a[i];
	}
	cout << ans << endl;
}