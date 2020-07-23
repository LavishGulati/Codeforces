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

bool isprime(int n){
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		if(n == 1){
			cout << "FastestFinger" << endl;
		}
		else if(n == 2){
			cout << "Ashishgup" << endl;
		}
		else if(n%2){
			cout << "Ashishgup" << endl;
		}
		else{
			int k = 1;
			while(n > 1 && (n%2 == 0)){
				n /= 2;
				k *= 2;
			}

			if(k > 2){
				if(n == 1){
					cout << "FastestFinger" << endl;
				}
				else{
					cout << "Ashishgup" << endl;
				}
			}
			else{
				if(isprime(n)){
					cout << "FastestFinger" << endl;
				}
				else{
					cout << "Ashishgup" << endl;
				}
			}
		}
	}
}