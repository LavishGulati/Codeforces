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
		string s;
		cin >> s;

		int x;
		cin >> x;

		int n = s.length();

		string w(n, ' ');
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				if(i-x >= 0){
					w[i-x] = '0';
				}
				if(i+x < n){
					w[i+x] = '0';
				}
			}
		}


		bool poss = true;
		for(int i = 0; i < n; i++){
			if(s[i] == '1'){
				if(i-x < 0 && i+x >= n){
					poss = false;
					break;
				}
				else if(i-x < 0){
					if(w[i+x] == '0'){
						poss = false;
						break;
					}
					else{
						w[i+x] = '1';
					}
				}
				else if(i+x >= n){
					if(w[i-x] == '0'){
						poss = false;
						break;
					}
					else{
						w[i-x] = '1';
					}
				}
				else{
					if(w[i-x] == '0' && w[i+x] == '0'){
						poss = false;
						break;
					}
					else if(w[i-x] == '0'){
						w[i+x] = '1';
					}
					else if(w[i+x] == '0'){
						w[i-x] = '1';
					}
					else{
						w[i-x] = w[i+x] = '1';
					}
				}
			}
		}

		for(int i = 0; i < n; i++){
			if(w[i] == ' '){
				w[i] = '0';
			}
		}

		if(!poss){
			cout << -1 << endl;
		}
		else{
			cout << w << endl;
		}
	}
}