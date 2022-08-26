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

	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;

		int n = s.length();

		int *freq = new int[26];
		for(int i = 0; i < 26; i++){
			freq[i] = 0;
		}
		for(int i = 0; i < n; i++){
			freq[s[i]-'a']++;
		}
		int it = 25;

		int m;
		cin >> m;

		int *b = new int[m];
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}

		vector<int> v;
		int cnt = 0;
		for(int i = 0; i < m; i++){
			if(b[i] == 0){
				v.pb(i);
			}
		}

		string t = "";
		for(int i = 0; i < m; i++){
			t += ' ';
		}

		bool *marked = new bool[m];
		for(int i = 0; i < m; i++){
			marked[i] = false;
		}

		while(cnt < m){
			while(freq[it] < v.size()){
				it--;
			}

			for(int i = 0; i < v.size(); i++){
				t[v[i]] = ('a'+it);
				marked[v[i]] = true;
				cnt++;
			}

			it--;
			
			for(int i = 0; i < m; i++){
				for(int j = 0; j < v.size(); j++){
					b[i] -= abs(i-v[j]);
				}
			}

			v.clear();
			for(int i = 0; i < m; i++){
				if(b[i] == 0 && !marked[i]){
					v.pb(i);
				}
			}
		}

		cout << t << endl;
	}
}