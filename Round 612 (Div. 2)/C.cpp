#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	
	vector<int> helper;
	int input[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
		if(input[i] != 0){
			helper.pb(input[i]);
		}
	}

	sort(all(helper));
	vector<int> even;
	vector<int> odd;
	int j = 0;
	for(int i = 1; i <= n; i++){
		if(j < helper.size() && helper[j] == i){
			j++;
		}
		else{
			// i is odd
			if(i%2){
				odd.pb(i);
			}
			else{
				even.pb(i);
			}
		}
	}

	int l = 0;
	int m = 0;

	vector<pii> sorter;

	for(int i = 0; i < n; i++){
		if(input[i] != 0){
			int j = i+1;
			while(j < n && input[j] == 0){
				j++;
			}

			if(j < n){

				if(input[i]%2 == 1 && input[j]%2 == 1){
					sorter.pb(mp(j-i, i));
				}
				else if(input[i]%2 == 0 && input[j]%2 == 0){
					sorter.pb(mp(j-i, i));
				}

				// sorter.pb(mp(j-i, i));

				// if(input[i]%2 == 1 && input[j]%2 == 1){
				// 	int k = i+1;
				// 	while(k < j && l < odd.size()){
				// 		input[k] = odd[l];
				// 		l++;
				// 		k++;
				// 	}
				// }
				// else if(input[i]%2 == 0 && input[j]%2 == 0){
				// 	int k = i+1;
				// 	while(k < j && m < even.size()){
				// 		input[k] = even[m];
				// 		m++;
				// 		k++;
				// 	}
				// }
			}
		}
	}

	sort(all(sorter));
	for(int k = 0; k < sorter.size(); k++){
		int i = sorter[k].s;
		int j = i+1;
		while(j < n && input[j] == 0){
			j++;
		}

		if(j < n){
			if(input[i]%2 == 1 && input[j]%2 == 1 && j-i-1 <= odd.size()-l){
				int k = i+1;
				while(k < j && l < odd.size()){
					input[k] = odd[l];
					l++;
					k++;
				}
			}
			else if(input[i]%2 == 0 && input[j]%2 == 0 && j-i-1 <= even.size()-m){
				int k = i+1;
				while(k < j && m < even.size()){
					input[k] = even[m];
					m++;
					k++;
				}
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	cout << input[i] << " ";
	// }
	// cout << endl;

	if(input[0] == 0){
		int i = 1;
		while(i < n && input[i] == 0){
			i++;
		}
		if(i < n){
			if(input[i]%2){
				i--;
				while(i >= 0 && l < odd.size()){
					input[i] = odd[l];
					l++; i--;
				}	
			}
			else{
				i--;
				while(i >= 0 && m < even.size()){
					input[i] = even[m];
					m++; i--;
				}	
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	cout << input[i] << " ";
	// }
	// cout << endl;

	if(input[n-1] == 0){
		int i = n-2;
		while(i >= 0 && input[i] == 0){
			i--;
		}
		if(i >= 0){
			if(input[i]%2){
				i++;
				while(i < n && l < odd.size()){
					input[i] = odd[l];
					l++; i++;
				}	
			}
			else{
				i++;
				while(i < n && m < even.size()){
					input[i] = even[m];
					m++; i++;
				}	
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	cout << input[i] << " ";
	// }
	// cout << endl;

	for(int i = 0; i < n; i++){
		if(input[i] != 0){
			int k = i+1;
			if(input[i]%2){
				while(k < n && input[k] == 0 && l < odd.size()){
					input[k] = odd[l];
					l++; k++;
				}
			}
			else{
				while(k < n && input[k] == 0 && m < even.size()){
					input[k] = even[m];
					m++;
					k++;
				}
			}
			
			k = i-1;
			if(input[i]%2){
				while(k >= 0 && input[k] == 0 && l < odd.size()){
					input[k] = odd[l];
					l++; k--;
				}
			}
			else{
				while(k >= 0 && input[k] == 0 && m < even.size()){
					input[k] = even[m];
					m++;
					k--;
				}
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	cout << input[i] << " ";
	// }
	// cout << endl;

	for(int i = 0; i < n; i++){
		if(input[i] == 0){
			if(l < odd.size()){
				input[i] = odd[l];
				l++;
			}
			else if(m < even.size()){
				input[i] = even[m];
				m++;
			}
		}
	}

	// for(int i = 0; i < n; i++){
	// 	cout << input[i] << " ";
	// }
	// cout << endl;

	int answer = 0;
	for(int i = 1; i < n; i++){
		if(input[i]%2 == 1 && input[i-1]%2 == 0){
			answer++;
		}
		else if(input[i]%2 == 0 && input[i-1]%2 == 1){
			answer++;
		}
	}

	cout << answer << endl;
}