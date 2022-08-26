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

		string s;
		cin >> s;

		string output[2];
		output[0] = output[1] = "";
		int nextOne = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '2'){
				if(!nextOne){
					output[0] += '1';
					output[1] += '1';
				}
				else{
					output[0] += '0';
					output[1] += '2';
				}
			}
			else if(s[i] == '1'){
				if(!nextOne){
					output[0] += '1';
					output[1] += '0';
					nextOne = 1;
				}
				else{
					output[0] += '0';
					output[1] += '1';
				} 
			}
			else{
				output[0] += '0';
				output[1] += '0';
			}
		}

		cout << output[0] << endl << output[1] << endl;
	}
}