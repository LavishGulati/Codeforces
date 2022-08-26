#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, n, k, id;
    string s;
    cin >> q;

    char helper[3] = {'R', 'G', 'B'};

    while(q--){
        cin >> n >> k;
        cin >> s;

        int dp[n-k+1][3];
        for(int i = 0; i < 3; i++){
            id = i;
            dp[n-k][i] = 0;
            for(int j = n-k; j < n; j++){
                if(s[j] != helper[id]) dp[n-k][i]++;
                id = (id+1)%3;
            }
        }

        for(int i = n-k-1; i >= 0; i--){
            for(int j = 0; j < 3; j++){
                dp[i][j] = 0;
                id = j;
                if(s[i] != helper[id]) dp[i][j]++;
                dp[i][j] += dp[i+1][(j+1)%3];
                if(s[i+k] != helper[(j+k)%3]) dp[i][j]--;
            }
        }

        // for(int j = 0; j < 3; j++){
        //     for(int i = 0; i <= n-k; i++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int answer = INT_MAX;
        for(int i = 0; i <= n-k; i++){
            for(int j = 0; j < 3; j++){
                answer = min(answer, dp[i][j]);
            }
        }
        cout << answer << endl;
    }
}
