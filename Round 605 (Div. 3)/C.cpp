#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

#define pb push_back
#define umap unordered_map
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	bool present[26];
	for(ll i = 0; i < 26; i++){
		present[i] = false;
	}

	char c;
	for(ll i = 0; i < k; i++){
		cin >> c;
		present[c-'a'] = true;
	}

	ll answer = 0;
	ll count = 0;
	ll i;
	for(i = 0; i < n; i++){
		if(present[s[i]-'a']){
			count++;
		}
		else{
			answer += (count*(count+1))/2;
			count = 0;
		}
	}
	answer += (count*(count+1))/2;
	cout << answer << endl;
}