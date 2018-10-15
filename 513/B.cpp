#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll convert(string s){
    ll answer = 0;
    for(ll i = 0; i < s.length(); i++){
        answer += (s[s.length()-i-1]-'0')*(ll)pow(10,i);
    }
    return answer;
}

int main(){
    string s;
    cin >> s;

    ll n = convert(s);
    // cout << n << endl;

    ll digitsN = s.length();
    ll a = (s[0]-'0'-1)*pow(10, digitsN-1);

    ll helper = 1;
    for(ll i = 0; i < digitsN-1; i++){
        a += helper*9;
        helper *= 10;
    }

    ll b = n - a;

    ll total = 0;
    while(a != 0){
        total += a%10;
        a /= 10;
    }
    while(b != 0){
        total += b%10;
        b /= 10;
    }

    cout << total << endl;
}
