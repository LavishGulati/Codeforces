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
 
	ll t;
	cin >> t;
	bool draw;
	while(t--){
		ll n;
		cin >> n;
 
		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
 
		ll *count = new ll[32];
		for(ll i = 0; i < 32; i++){
			count[i] = 0;
		}
 
		for(ll i = 31; i >= 0; i--){
			for(ll j = 0; j < n; j++){
				if(a[j]&(1<<i)){
					count[i]++;
				}
			}
		}
 
		ll id = 32;
		draw = true;
		for(ll i = 31; i >= 0; i--){
			if(count[i]%2){
				id = i;
				draw = false;
				break;
			}
		}
 
		if(draw){
			cout << "DRAW" << endl;
		}
		else if(!(((count[id]-1)/2)%2)){
			cout << "WIN" << endl;
		}
		else if((n-count[id])%2){
			cout << "WIN" << endl;
		}
		else{
			cout << "LOSE" << endl;
		}
	} 
}