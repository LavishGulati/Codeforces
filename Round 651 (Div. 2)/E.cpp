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

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	int ones = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			ones++;
		}
	}

	int onet = 0;
	for(int i = 0; i < n; i++){
		if(t[i] == '1'){
			onet++;
		}
	}

	if(onet != ones){
		cout << "-1\n";
		return 0;
	}

	set<int> sone, szero;
	for(int i = 0; i < n; i++){
		if(s[i] == '1' && t[i] == '0'){
			sone.insert(i);
		}
		else if(s[i] == '0' && t[i] == '1'){
			szero.insert(i);
		}
	}

	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		if(s[i] != t[i]){
			if(s[i] == '0' && szero.find(i) != szero.end()){
				int j = i;
				ans++;
				while(1){
					auto it = sone.upper_bound(j);
					if(it != sone.begin()){
						it--;
						auto it2 = szero.upper_bound(*it);
						
						if(it2 != szero.begin()){
							it2--;
							j = *it2;
							szero.erase(j);
							sone.erase(it);
						}
						else{
							szero.erase(j);
							sone.erase(it);
							break;
						}
					}
					else{
						break;
					}			
				}
			}
			else if(s[i] == '1' && sone.find(i) != sone.end()){
				int j = i;
				ans++;
				while(1){
					auto it = szero.upper_bound(j);
					if(it != szero.begin()){
						it--;
						auto it2 = sone.upper_bound(*it);
						
						if(it2 != sone.begin()){
							it2--;
							j = *it2;
							sone.erase(j);
							szero.erase(it);
						}
						else{
							sone.erase(j);
							szero.erase(it);
							break;
						}
					}
					else{
						break;
					}			
				}
			}
		}
	}

	cout << ans << endl;
}