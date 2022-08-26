#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll *input = new ll[n];
    for(ll i = 0; i < n; i++){
        cin >> input[i];
    }

    ll gcd;
    if(n == 1) gcd = input[0];
    else gcd = __gcd(input[0], input[1]);

    for(ll i = 2; i < n; i++){
        gcd = __gcd(gcd, input[i]);
    }

    ll answer = 1, num;
    for(ll i = 2; i*i <= gcd; i++){
        num = 0;
        while(gcd%i == 0){
            num++;
            gcd /= i;
        }
        answer = answer*(num+1);
    }
    if(gcd > 1){
        answer *= 2;
    }
    cout << answer << endl;
}
