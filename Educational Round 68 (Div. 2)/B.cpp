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

    int q, n, m;
    cin >> q;
    while(q--){
        cin >> n >> m;
        char grid[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cin >> grid[i][j];
        }

        int row[n];
        int col[m];
        for(int i = 0; i < n; i++) row[i] = 0;
        for(int j = 0; j < m; j++) col[j] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '*'){
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int answer = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '*'){
                    answer = min(answer, m+n-row[i]-col[j]);
                }
                else{
                    answer = min(answer, m+n-1-row[i]-col[j]);
                }
            }
        }

        cout << answer << endl;
    }
}
