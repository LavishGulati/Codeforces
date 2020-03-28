#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, n;
    string s, t;
    bool possible[2][26], answer;
    cin >> q;
    while(q--){
        cin >> s >> t;
        for(int i = 0; i < 26; i++){
            possible[0][i] = possible[1][i] = false;
        }
        answer = false;

        n = s.length();
        for(int i = 0; i < n; i++){
            possible[0][s[i]-'a'] = true;
        }
        for(int i = 0; i < n; i++){
            possible[1][t[i]-'a'] = true;
        }

        for(int i = 0; i < 26; i++){
            if(possible[0][i] && possible[1][i]){
                answer = true;
                break;
            }
        }
        if(answer){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
