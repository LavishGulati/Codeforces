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
		int n;
		cin >> n;

		int three = 0, two = 0;
		while(n%3 == 0){
			n /= 3;
			three++;
		}
		while(n%2 == 0){
			n /= 2;
			two++;
		}

		if(n != 1 || two > three){
			cout << -1 << endl;
		}
		else{
			cout << 2*(three-two)+two << endl;
		}
	}
}