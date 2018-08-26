#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int flag = 1;
        for(int i = 0; i < n; i++){
            int x = abs(s[i]-s[n-i-1]);
            x = x%26;
            if(x > 2 || x == 1){
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }

        if(flag) cout << "YES" << endl;
    }
}
