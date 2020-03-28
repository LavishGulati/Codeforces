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

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll u, v;
	cin >> u >> v;

	ll x, y;
	x = u;
	y = v;

	if(u == v){
		if(u == 0){
			cout << 0 << "\n";
			return 0;
		}
		else{
			cout << "1\n" << u << "\n";
			return 0;
		}
	}

	ll output[3];
	output[0] = output[1] = output[2] = 0;

	ll a, b;
	ll *carry = new ll[64];
	carry[0] = 0;
	ll helper = 1;
	ll num = 0;
	while(u > 0 || v > 0){
		a = u%2;
		b = v%2;
		u /= 2;
		v /= 2;

		// cout << num << " " << a << " " << b << " " << carry[num] << "\n";

		if(a && !b){
			if(!carry[num]){
				if(helper == 1){
					cout << -1 << endl;
					return 0;
				}
				else if(output[0]/(helper/2)){
					output[1] += helper/2;
					output[2] += helper/2;
				}
				else{
					output[0] += helper/2;
					output[1] += helper/2;
				}
			}

			output[0] += helper;
			carry[num+1] = 1;
		}
		else if(!a && b){
			if(!carry[num]){
				if(helper == 1){
					cout << -1 << endl;
					return 0;
				}
				else if(output[0]/(helper/2)){
					output[1] += helper/2;
					output[2] += helper/2;
				}
				else{
					output[0] += helper/2;
					output[1] += helper/2;
				}
			}
			carry[num+1] = 0;
		}
		else if(a && b){
			if(carry[num]){
				if(output[0]/(helper/2)){
					output[1] += helper/2;
					output[2] += helper/2;
				}
				else{
					output[0] += helper/2;
					output[1] += helper/2;
				}
				carry[num+1] = 1;
				// cout << -1 << endl;
				// return 0;
			}
			else{
				carry[num+1] = 0;
			}
			output[0] += helper;
		}
		else{
			if(carry[num]){
				if(output[0]/(helper/2)){
					output[1] += helper/2;
					output[2] += helper/2;
				}
				else{
					output[0] += helper/2;
					output[1] += helper/2;
				}
				carry[num+1] = 1;
				// cout << -1 << endl;
				// return 0;
			}
			else{
				carry[num+1] = 0;
			}
		}

		helper *= 2;
		num++;
	}

	if(carry[num]){
		cout << -1 << endl;
		return 0;
	}

	if(output[2] == 0){
		cout << 2 << endl;
		cout << output[0] << " " << output[1] << endl;
	}
	else{
		cout << 3 << endl;
		cout << output[0] << " " << output[1] << " " << output[2] << endl;
	}
}