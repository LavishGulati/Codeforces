#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	int n = s.length();

	int i = 0;
	int j = n-1;
	vector<int> v;
	vector< vector<int> > output;
	while(i < j){
		if(s[j] == ')'){
			while(i < j && s[i] != '('){
				i++;
			}

			if(i < j){
				v.pb(i);
				v.pb(j);
			}
			i++;
		}
		j--;
	}

	if(v.size() > 0){
		output.pb(v);
	}
	cout << output.size() << "\n";
	for(int i = 0; i < output.size(); i++){
		cout << output[i].size() << "\n";
		sort(all(output[i]));
		for(int j = 0; j < output[i].size(); j++){
			cout << output[i][j]+1 << " ";
		}
		cout << "\n";
	}
}