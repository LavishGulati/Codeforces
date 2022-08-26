#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

bool repeat(string &s, string &help){
	for(int i = 0; i < s.length(); i++){
		if(s[i] != help[i%help.length()]){
			return false;
		}
	}
	return true;
}

string find(string &s){
	int n = s.length();
	string help = "";
	for(int i = 0; i < n; i++){
		help += s[i];
		if(n%(i+1) == 0 && repeat(s, help)){
			return help;
		}
	}
	return "";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int q;
	cin >> q;
	while(q--){
		string s, t;
		cin >> s >> t;

		string a, b;
		a = find(s);
		b = find(t);

		if(a == "" || b == "" || a != b){
			cout << -1 << endl;
			continue;
		}

		int n = s.length();
		int m = t.length();
		int lcm = (n*m)/__gcd(n, m);
		string output = "";
		for(int i = 0; i < lcm/a.length(); i++){
			output += a;
		}
		cout << output << endl;
	}
}