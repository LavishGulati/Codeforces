#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MAX 10001

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q, n, x;
    bool ans;
    int input[MAX];
    cin >> q;
    while(q--){
        cin >> n;
        for(int i = 0; i < MAX; i++) input[i] = 0;

        for(int i = 0; i < 4*n; i++){
            cin >> x;
            input[x]++;
        }

        ll area = -1;
        int i = 0, j = MAX - 1;
        ans = true;
        while(i <= j){
            while(i < MAX && input[i] == 0) i++;
            while(j >= 0 && input[j] == 0) j--;

            if(j < 0 || i >= MAX) break;

            if(input[i]%2 == 1){
                // cout << i << " " << input[i] << endl;
                // cout << 1 << endl;
                ans = false;
                break;
            }
            if(input[j]%2 == 1){
                // cout << 2 << endl;
                ans = false;
                break;
            }

            if(area == -1){
                area = i;
                area *= j;
            }
            else{
                if(area != ll(i)*ll(j)){
                    // cout << i << " " << j << endl;
                    // cout << 3 << endl;
                    ans = false;
                    break;
                }
            }

            input[i] -= 2;
            input[j] -= 2;
        }

        if(!ans) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
