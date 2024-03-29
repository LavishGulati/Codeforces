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

		string s;
		cin >> s;

		string output = "";
		output += s[0];
		bool sim;
		for(int i = 1; i < n; i++){
			sim = false;
			for(int j = 0; j < output.length(); j++){
				if(s[i+j] == output[j]){
					sim = true;
					break;
				}
			}

			if(!sim){
				output += s[i+output.length()];
			}
		}

		while(output.length() < n){
			output += '0';
		}

		cout << output << endl;
	}
}