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

	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}

		map<ll, ll> freq;
		for(ll i = 0; i < n; i++){
			if(a[i]%k != 0){
				freq[k-a[i]%k]++;
			}
		}

		ll maxFreq = 0;
		ll id = -1;
		for(pll i : freq){
			if(maxFreq <= i.s){
				maxFreq = i.s;
				id = i.f;
			}
		}
		if(maxFreq == 0){
			cout << 0 << endl;
		}
		else{
			// cout << maxFreq << " " << id << endl;
			cout << (maxFreq-1)*k + id + 1 << endl;
		}
	}
}