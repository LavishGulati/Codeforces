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
	while(t--){
		ll p, f;
		cin >> p >> f;

		ll cnts, cntw;
		cin >> cnts >> cntw;

		ll s, w;
		cin >> s >> w;

		if(s > w){
			swap(s, w);
			swap(cnts, cntw);
		}

		ll si = 0, ei = cnts+cntw, mid, ans = 0;
		bool poss;
		while(si <= ei){
			mid = (si+ei)/2;

			poss = false;
			for(ll n1 = 0; n1 <= cnts && n1*s <= p; n1++){
				ll n2 = (p - n1*s)/w;
				if(n1+n2 >= mid){
					poss = true;
					break;
				}

				ll m1 = min(f/s, cnts-n1);
				ll m2 = min(cntw-n2, (f - m1*s)/w);
				if(n1+n2+m1+m2 >= mid){
					poss = true;
					break;
				}
			}

			if(poss){
				ans = mid;
				si = mid+1;
			}
			else{
				ei = mid-1;
			}
		}

		cout << ans << endl;
	}
}