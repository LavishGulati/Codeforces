#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int zero, one, two, three;
	cin >> zero >> one >> two >> three;

	int l1, r1;
	if(one < zero){
		cout << "NO" << endl;
		return 0;
	}
	else if(one == zero){
		l1 = r1 = 1;
	}
	else if(zero == 0){
		l1 = one-zero;
		r1 = 2*(one-zero);
	}
	else{
		l1 = one-zero;
		r1 = 2*(one-zero)+1;
	}

	int l2, r2;
	if(two < three){
		cout << "NO" << endl;
		return 0;
	}
	else if(two == three){
		l2 = r2 = 1;
	}
	else if(three == 0){
		l2 = two-three;
		r2 = 2*(two-three);
	}
	else{
		l2 = two-three;
		r2 = 2*(two-three) + 1;
	}

	if(l2 > r1 || l1 > r2){
		cout << "NO" << endl;
		return 0;
	}

	int k;
	if(l1 <= r2 && l1 >= l2){
		k = l1;
	}
	else{
		k = l2;
	}


	int *output = new int[zero+one+two+three];
	if(k == 2*(one-zero)+1){
		
	}
	else{

	}
}