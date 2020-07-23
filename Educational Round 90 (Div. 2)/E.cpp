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

pll solve(ll sum){
	string output = "";
	if(sum >= 8){
		output += '8';
		sum -= 8;
	}
	while(sum >= 9){
		output += '9';
		sum -= 9;
	}
	char c = '0'+sum;
	output += c;
	reverse(all(output));
	return mp(stoll(output), output.length());
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll power[17];
	power[0] = 1;
	for(ll i = 1; i < 17; i++){
		power[i] = 10*power[i-1];
	}

	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;

		ll ans = LLONG_MAX;
		string help = "";
		for(ll nines = 0; nines < 17; nines++){
			for(ll d = 0; d < 10; d++){
				ll type1 = min(10-d, k+1);
				ll type2 = k+1-type1;

				ll sum = n - 9*nines*type1 - d*type1 - ((type1-1)*(type1))/2 - ((type2)*(type2+1))/2;
				if(sum < 0 || (sum)%(type1+type2) != 0){
					continue;
				}

				sum /= (type1+type2);
				pll pref = solve(sum);
				if(nines == 0 && pref.s < 17-nines && pref.f*10+d < ans){
					ans = pref.f*10+d;
				}
				else if(nines > 0 && pref.s < 17-nines && pref.f*power[nines+1]+stoll(help)*10+d < ans){
					ans = pref.f*power[nines+1]+stoll(help)*10+d;
				}
			}
			help += '9';
		}
		if(ans < LLONG_MAX){
			cout << ans << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}
