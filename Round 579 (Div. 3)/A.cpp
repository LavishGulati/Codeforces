#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q, n, id;
    bool ans;
    cin >> q;
    while(q--){
        cin >> n;
        int *input = new int[n];
        for(int i = 0; i < n; i++) cin >> input[i];

        id = 0;
        for(int i = 0; i < n; i++){
            if(input[i] == 1){
                id = i;
                break;
            }
        }

        ans = true;
        for(int i = (id+1)%n; i != id; i = (i+1)%n){
            if(input[i] != input[(i-1+n)%n]+1){
                // cout << i << " 1" << endl;
                ans = false;
                break;
            }
        }

        if(ans){
            cout << "YES" << endl;
            continue;
        }

        ans = true;
        for(int i = (id-1+n)%n; i != id; i = (i-1+n)%n){
            if(input[i] != input[(i+1)%n]+1){
                // cout << i << " 2" << endl;
                ans = false;
                break;
            }
        }
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
