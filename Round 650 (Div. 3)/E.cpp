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

#define MAX 2005

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		int *freq = new int[26];
		for(int i = 0; i < 26; i++){
			freq[i] = 0;
		}

		for(int i = 0; i < n; i++){
			freq[s[i]-'a']++;
		}
		sort(freq, freq+26);

		for(int len = n; len >= 1; len--){
			vector<bool> used(len);
			vector<int> cycles;

			for(int i = 0; i < len; i++){
				if(used[i]){
					continue;
				}

				int j = (i+k)%len;
				used[i] = true;
				cycles.pb(0);
				cycles.back()++;
				while(!used[j]){
					cycles.back()++;
					used[j] = true;
					j = (j+k)%len;
				}
			}

			sort(all(cycles));
			int *help = new int[26];
			for(int i = 0; i < 26; i++){
				help[i] = freq[i];
			}

			int i = 0, j = 0;
			while(j < cycles.size() && i < 26){
				if(cycles[j] <= help[i]){
					help[i] -= cycles[j];
					j++;
				}
				else{
					i++;
				}
			}
			if(j >= cycles.size()){
				cout << len << "\n";
				break;
			}
		}
	}
}