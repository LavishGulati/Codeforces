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
	bool poss;
	while(t--){
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;

		poss = true;
		vector<int> pos[20];
		for(int i = 0; i < n; i++){
			pos[b[i]-'a'].pb(i);
			if(b[i] < a[i]){
				poss = false;
				break;
			}
		}

		if(!poss){
			cout << -1 << endl;
			continue;
		}

		char *change = new char[20];
		for(int i = 0; i < 20; i++){
			change[i] = '.';
		}

		int ans = 0;
		for(int i = 0; i < 20; i++){
			if(pos[i].size() > 0){
				for(int id : pos[i]){
					while(change[a[id]-'a'] != '.' && a[id] != b[id] && a[id] != change[a[id]-'a']){
						a[id] = change[a[id]-'a'];
					}

					if(a[id] != b[id]){
						change[a[id]-'a'] = b[id];
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
}