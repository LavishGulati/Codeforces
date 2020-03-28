#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n;
	string s, output;

	bool possible, allques;

	cin >> t;
	while(t--){
		cin >> s;
		n = s.length();
		output = s;
		
		possible = true;
		allques = true;

		for(int i = 0; i < n-1; i++){
			if(s[i] != '?' && s[i+1] != '?' && s[i] == s[i+1]){
				possible = false;
				break;
			}
		}
		if(!possible){
			cout << -1 << endl;
			continue;
		}

		for(int i = 0; i < n; i++){
			if(s[i] != '?'){
				allques = false;
				break;
			}
		}

		if(allques){
			for(int i = 0; i < n; i++){
				output[i] = 'a'+(i%3);
			}
		}

		for(int i = 1; i < n; i++){
			if(output[i-1] != '?' && output[i] == '?'){
				if(i+1 < n && output[i+1] != '?'){
					if(output[i-1] != 'a' && output[i+1] != 'a') output[i] = 'a';
					else if(output[i-1] != 'b' && output[i+1] != 'b') output[i] = 'b';
					else output[i] = 'c';
				}
				else{
					if(output[i-1] != 'a') output[i] = 'a';
					else if(output[i-1] != 'b') output[i] = 'b';
					else output[i] = 'c';
				}				
			}
			// cout << output << endl;
		}

		for(int i = n-2; i >= 0; i--){
			if(output[i+1] != '?' && output[i] == '?'){
				if(i-1 >= 0 && output[i-1] != '?'){
					if(output[i-1] != 'a' && output[i+1] != 'a') output[i] = 'a';
					else if(output[i-1] != 'b' && output[i+1] != 'b') output[i] = 'b';
					else output[i] = 'c';
				}
				else{
					if(output[i+1] != 'a') output[i] = 'a';
					else if(output[i+1] != 'b') output[i] = 'b';
					else output[i] = 'c';
				}				
			}
			// cout << output << endl;
		}

		cout << output << endl;
		// cout << "Final: " << output << endl;
	}
}