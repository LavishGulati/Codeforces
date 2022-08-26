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
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		bool poss = true;
		char c;
		for(int i = 0; i < k; i++){
			c = s[i];
			for(int j = i; j < n; j += k){
				if(c == '?'){
					c = s[j];
				}
				else if(s[j] != '?' && c != s[j]){
					poss = false;
					break;
				}
			}
			if(c != '?'){
				for(int j = i; j < n; j += k){
					s[j] = c;
				}
			}
		}

		if(!poss){
			cout << "NO" << endl;
		}
		else{
			int cnt[3] = {0, 0, 0};
			for(int i = 0; i < k; i++){
				if(s[i] == '?'){
					cnt[2]++;
				}
				else{
					cnt[s[i]-'0']++;
				}
			}

			int y = cnt[2]+cnt[1]-cnt[0];
			if(y >= 0 && (y%2 == 0) && y/2 <= cnt[2]){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
	}
}