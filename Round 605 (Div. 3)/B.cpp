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

	int q;
	cin >> q;
	string s;
	while(q--){
		cin >> s;
		int helper[26];
		for(int i = 0; i < 26; i++){
			helper[i] = 0;
		}

		int n = s.length();
		for(int i = 0; i < n; i++){
			helper[s[i]-'A']++;
		}

		int Ls = min(helper['L'-'A'], helper['R'-'A']);
		int Us = min(helper['U'-'A'], helper['D'-'A']);
		

		if(Ls == 0 || Us == 0){
			if(Us == 0 && Ls == 0){
				cout << 0 << endl;
				cout << endl;
			}
			else if(Us == 0){
				cout << 2 << endl;
				cout << "LR" << endl;
			}
			else{
				cout << 2 << endl;
				cout << "UD" << endl;
			}
		}
		else{
			cout << 2*(Ls+Us) << endl;
			for(int i = 0; i < Ls; i++){
				cout << 'L';
			}
			for(int i = 0; i < Us; i++){
				cout << 'U';
			}
			for(int i = 0; i < Ls; i++){
				cout << 'R';
			}
			for(int i = 0; i < Us; i++){
				cout << 'D';
			}
			cout << endl;
		}
	}
}