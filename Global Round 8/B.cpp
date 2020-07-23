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

	ll k;
	cin >> k;

	ll d = 1, x;
	while(pow(d, 10) <= k){
		d++;
	}
	d--;

	string temp = "codeforces";
	string out = "";
	for(ll i = 0; i < 10; i++){
		for(ll j = 0; j < d; j++){
			out += temp[i];
		}
	}

	x = pow(d, 10);
	string help;
	for(ll i = 0; i < 10 && x < k; i++){
		help = out.substr(0, i*d+i+1) + temp[i] + out.substr(i*d+i+1);
		out = help;
		x /= d;
		x *= d+1;
	}
	cout << out << endl;
}