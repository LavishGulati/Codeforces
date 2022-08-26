#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	string input[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}

	map<string, int> mp;
	for(int i = 0; i < n; i++){
		mp[input[i]]++;
	}

	ll answer = 0;
	for(auto i = mp.begin(); i != mp.end(); i++){
		auto j = i;
		j++;
		for(; j != mp.end(); j++){
			string a = i->f;
			string b = j->f;
			string c = "";
			for(int k = 0; k < m; k++){
				if(a[k] == b[k]){
					c += a[k];					
				}
				else{
					if(a[k] != 'S' && b[k] != 'S'){
						c += 'S';
					}
					else if(a[k] != 'E' && b[k] != 'E'){
						c += 'E';
					}
					else{
						c += 'T';
					}
				}
			}

			if(mp.find(c) != mp.end()){
				answer += (i->s)*(j->s)*mp[c];
			}
		}
	}

	cout << answer/3 << endl;
}