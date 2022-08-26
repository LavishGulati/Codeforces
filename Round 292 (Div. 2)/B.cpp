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

bool solve(){
	int n, m, b, g, x;
	cin >> n >> m;

	uset<int> boys;
	uset<int> girls;

	cin >> b;
	for(int i = 0; i < b; i++){
		cin >> x;
		boys.insert(x);
	}

	cin >> g;
	for(int i = 0; i < g; i++){
		cin >> x;
		girls.insert(x);
	}

	x = __gcd(n, m);
	if(x == 1 && (b > 0 || g > 0)){
		return true;
	}

	vector<int> temp1, temp2;
	bool allUnhappy;
	for(int i = 0; i < x; i++){
		temp1.clear();
		temp2.clear();
		for(int j = i; j < n; j += x){
			temp1.pb(j);
		}
		for(int j = i; j < m; j += x){
			temp2.pb(j);
		}

		allUnhappy = false;
		for(int x : temp1){
			if(boys.find(x) != boys.end()){
				allUnhappy = true;
				break;
			}
		}

		for(int x : temp2){
			if(girls.find(x) != girls.end()){
				allUnhappy = true;
				break;
			}
		}

		if(!allUnhappy){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	if(!solve()){
		cout << "No\n";
	}
	else{
		cout << "Yes\n";
	}
}