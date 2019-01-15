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
#define MOD 1000000007

#define MAX 5009

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	int freq[MAX];
	for(int i = 0; i < MAX; i++) freq[i] = 0;

	int input[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
		freq[input[i]]++;
		if(freq[input[i]] > k){
			cout << "NO" << endl;
			return 0;
		}
	}

	if(n < k){
		cout << "NO" << endl;
		return 0;
	}

	map< int, set<int> > m;
	int answer[n];
	int color = 1, x;
	for(int i = 0; i < n; i++){
		x = input[i];
		if(m[x].find(color) != m[x].end()){
			for(int j = 1; j <= k; j++){
				if(m[x].find(j) == m[x].end()){
					answer[i] = j;
					m[x].insert(j);
					break;
				}
			}
		}
		else{
			answer[i] = color;
			m[x].insert(color);
			if(color < k) color++;
		}
	}

	cout << "YES" << endl;
	for(int i = 0; i < n; i++){
		cout << answer[i] << " ";
	}
	cout << endl;
}