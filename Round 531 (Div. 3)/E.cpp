#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 998244353

ll power(ll n){
	if(n == 1) return 2;
	if(n == 0) return 1;

	if(n%2 == 0){
		return (power(n/2)*power(n/2))%MOD;
	}
	else{
		return (2*(power((n-1)/2)*power((n-1)/2))%MOD)%MOD;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int input[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}

	map<int, pii *> m;
	for(int i = 0; i < n; i++){
		if(m.find(input[i]) == m.end()){
			m[input[i]] = new pii;
			m[input[i]]->f = i;
			m[input[i]]->s = i;
		}
		else{
			m[input[i]]->f = min(m[input[i]]->f, i);
			m[input[i]]->s = max(m[input[i]]->s, i);
		}
	}

	// for(int i = 0; i < n; i++){
	// 	cout << m[input[i]].f << " " << m[input[i]].s << endl;
	// }

	int x;
	for(int i = 1; i < n; i++){
		if(m[input[i]]->f < m[input[i-1]]->s){
			m[input[i-1]]->s = max(m[input[i]]->s, m[input[i-1]]->s);
			m[input[i]] = m[input[i-1]];
		}
	}

	// for(int i = 0; i < n; i++){
	// 	cout << m[input[i]].f << " " << m[input[i]].s << endl;
	// }

	ll num = 1;
	for(int i = 1; i < n; i++){
		if(m[input[i]] != m[input[i-1]]){
			num++;
		}
	}

	cout << power(num-1) << endl;
}
