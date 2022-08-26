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

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		vector<int> output;

		for(int p = 1; p <= n; p++){
			output.pb(n/p);
			p = n/(n/p);
		}

		cout << output.size()+1 << endl;
		cout << 0 << " ";
		for(int i = output.size()-1; i >= 0; i--){
			cout << output[i] << " ";
		}
		cout << endl;
	}
}