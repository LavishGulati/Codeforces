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

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		int *helper = new int[26];
		bool *done = new bool[n];
		for(int i = 0; i < n; i++){
			done[i] = false;
		}
		set<int> v1;
		set<int> v2;

		int ans = 0;
		for(int i = 0; i < n; i++){
			if(!done[i]){
				v1.clear();
				v2.clear();

				for(int j = i; j < n; j += k){
					// v1.pb(j);
					v1.insert(j);
					done[j] = true;
				}

				for(int j : v1){
					if(n-j-1 < n){
						// v2.pb(n-v1[j]-1);
						v2.insert(n-j-1);
						done[n-j-1] = true;
					}
				}

				for(int j : v2){
					v1.insert(j);
				}

				for(int j = 0; j < 26; j++){
					helper[j] = 0;
				}

				for(int j : v1){
					helper[s[j]-'a']++;
					// cout << j << " ";
				}

				int maxfreq = 0;
				for(int i = 0; i < 26; i++){
					maxfreq = max(maxfreq, helper[i]);
				}

				ans += v1.size()-maxfreq;
			}
		}
		cout << ans << endl;
	}
}