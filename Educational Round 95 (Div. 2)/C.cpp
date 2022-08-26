#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
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

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		bool *a = new bool[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		int ans = 0;
		int id = 0, i = 0;
		while(i < n-1){
			if(!id){
				if(!a[i] && !a[i+1]){
					i += 2;
				}
				else if(!a[i] && a[i+1]){
					i += 1;
				}
				else if(a[i] && !a[i+1]){
					ans++;
					i += 2;
				}
				else{
					ans++;
					i += 1;
				}
			}
			else{
				if(!a[i] && !a[i+1]){
					i += 1;
				}
				else if(!a[i] && a[i+1]){
					i += 2;
				}
				else if(a[i] && !a[i+1]){
					i += 1;
				}
				else{
					i += 2;
				}
			}
			id ^= 1;
		}

		if(i < n && !id && a[i]){
			ans++;
		}
		cout << ans << endl;
	}
}