#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int zero, one, two, three;
	cin >> zero >> one >> two >> three;

	vector<int> poss1;

	int diff1 = one-zero;
	if(diff1 < 0){
		cout << "NO" << endl;
		return 0;
	}
	else if(diff1 == 0){
		poss1.pb(1);
	}
	else{
		poss1.pb(2*diff1-1);
		poss1.pb(2*diff1);
		poss1.pb(2*diff1+1);
	}

	vector<int> poss2;

	int diff2 = two-three;
	if(diff2 < 0){
		cout << "NO" << endl;
		return 0;
	}
	else if(diff2 == 0){
		poss2.pb(1);
	}
	else{
		poss2.pb(2*diff2-1);
		poss2.pb(2*diff2);
		poss2.pb(2*diff2+1);
	}

	int k;
	bool match = false;
	for(int i = 0; i < poss1.size(); i++){
		for(int j = 0; j < poss2.size(); j++){
			if(poss1[i] == poss2[j]){
				match = true;
				k = poss1[i];
				break;
			}
		}
	}

	if(!match){
		cout << "NO" << endl;
		return 0;
	}

	int *output = new int[one+two+zero+three];

	if(diff1 == 0){
		for(int i = 0; i < zero; i++){
			output[2*i] = 0;
			output[2*i+1] = 1;
		}
	}
	else if(diff2 == 0){
		for(int i = 0; i < three; i++){
			output[2*i] = 3;
			output[2*i+1] = 2;
		}
	}

	if(k == 2*diff1-1){
		
	}
	else if(k == 2*diff1){

	}
	else{

	}
}