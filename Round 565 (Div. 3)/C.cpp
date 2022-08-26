#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef vector<int> vi;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    int dp[n][6];
    for(int j = 0; j < 6; j++) dp[0][j] = 0;
    if(input[0] == 4) dp[0][0]++;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 6; j++) dp[i][j] = dp[i-1][j];

        if(input[i] == 4) dp[i][0]++;
        else if(input[i] == 8){
            dp[i][1] = min(dp[i][0], dp[i-1][1]+1);
        }
        else if(input[i] == 15){
            dp[i][2] = min(dp[i][1], dp[i-1][2]+1);
        }
        else if(input[i] == 16){
            dp[i][3] = min(dp[i][2], dp[i-1][3]+1);
        }
        else if(input[i] == 23){
            dp[i][4] = min(dp[i][3], dp[i-1][4]+1);
        }
        else if(input[i] == 42){
            dp[i][5] = min(dp[i][4], dp[i-1][5]+1);
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < 6; j++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    cout << n-6*dp[n-1][5] << endl;
}
