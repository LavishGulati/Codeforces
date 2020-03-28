#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define f first
#define s second
#define pb push_back
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    char **A = new char *[n];
    for(int i = 0; i < n; i++){
        A[i] = new char[m];
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }

    char **B = new char *[n];
    for(int i = 0; i < n; i++){
        B[i] = new char[m];
        for(int j = 0; j < m; j++){
            B[i][j] = '0';
        }
    }

    vector<pii> output;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] == '1' && B[i][j] == '0'){
                if(i+1 < n && j+1 < m && A[i+1][j] == '1' && A[i][j+1] == '1' && A[i+1][j+1] == '1'){
                    output.pb(mp(i, j));
                    B[i+1][j] = '1';
                    B[i][j+1] = '1';
                    B[i+1][j+1] = '1';
                    B[i][j] = '1';
                }
                else if(j-1 >= 0 && i+1 < n && A[i][j-1] == '1' && A[i+1][j-1] == '1' && A[i+1][j] == '1'){
                    output.pb(mp(i, j-1));
                    B[i][j-1] = '1';
                    B[i+1][j-1] = '1';
                    B[i+1][j] = '1';
                    B[i][j] = '1';
                }
                else if(i-1 >= 0 && j-1 >= 0 && A[i-1][j-1] == '1' && A[i][j-1] == '1' && A[i-1][j] == '1'){
                    output.pb(mp(i-1, j-1));
                    B[i-1][j-1] = '1';
                    B[i][j-1] = '1';
                    B[i-1][j] = '1';
                    B[i][j] = '1';
                }
                else if(i-1 >= 0 && j+1 < m && A[i-1][j] == '1' && A[i-1][j+1] == '1' && A[i][j+1] == '1'){
                    output.pb(mp(i-1, j));
                    B[i-1][j] = '1';
                    B[i-1][j+1] = '1';
                    B[i][j+1] = '1';
                    B[i][j] = '1';
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] != B[i][j]){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int l = output.size();
    cout << l << endl;
    for(int i = 0; i < l; i++){
        cout << output[i].f+1 << " " << output[i].s+1 << endl;
    }
}
