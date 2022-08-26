#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
// #define mp make_pair

// map<ll, ll> mp;

ll solve(ll x, ll n){
	ll answer = 0;

	if(x%2){
		answer = 1;
		x *= 2;
	}
	
	if(x > n){
		return answer;
	}

	ll helper = 0;
	ll y = x, a = x+1;
	while(2*y <= n){
		y *= 2;
		a = a*2+1;
		helper++;
	}

	ll z = 2;
	while(helper > 0){
		z = (z*2)+2;
		helper--;
	}

	// cout << z << " " << a << endl;
	answer += z;
	answer -= max((a - n), 0LL);
	return answer;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll k, n;
	cin >> n >> k;

	// cout << solve(3, 26) << endl;

	ll si = 1;
	ll ei = n;
	ll num, mid, num2;
	ll answer = -1;
	while(si <= ei){
		mid = (si+ei)/2;
		num = solve(mid, n);
		num2 = solve(mid+1, n);

		// cout << mid << " " << num << endl;
		// cout << mid+1 << " " << num2 << endl;

		if(mid+1 <= n && num2 >= k){
			answer = mid+1;
			si = mid+2;
		}
		else if(num >= k){
			answer = mid;
			si = mid+2;
		}
		else{
			ei = mid-1;
		}
	}

	cout << answer << endl;
}