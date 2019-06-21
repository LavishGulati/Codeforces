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

class cell{
public:
    char c;
    ll x, y;
    map<ll, ll> m;

    cell(){

    }

    cell(char d, ll a, ll b){
        c = d;
        x = a;
        y = b;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    char c;
    cell grid[n][m];
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> c;
            grid[i][j] = cell(c, 1, 1);
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 1; j < m; j++){
            if(grid[i][j-1].c == grid[i][j].c){
                grid[i][j].y += grid[i][j-1].y;
            }
        }
    }

    for(ll j = 0; j < m; j++){
        for(ll i = 1; i < n; i++){
            if(grid[i-1][j].c == grid[i][j].c){
                grid[i][j].x += grid[i-1][j].x;
            }
        }
    }

    ll answer = 0, a, b, e, d;
    for(ll j = m; j >= 0; j--){
        for(ll i = n-1; i > 0; ){
            a = grid[i][j].x;
            if(i-a >= 0 && i+a < n){
                if(grid[i-a][j].c != grid[i][j].c && grid[i][j].c != grid[i+a][j].c){
                    if(grid[i-a][j].x >= a && grid[i+a][j].x >= a){
                        b = e = d = INT_MAX;
                        for(ll k = i-a; k >= i-2*a+1; k--) b = min(b, grid[k][j].y);
                        for(ll k = i+1; k <= i+a; k++) e = min(e, grid[k][j].y);
                        for(ll k = i; k > i-a; k--) d = min(d, grid[k][j].y);
                        answer += min(b, min(e, d));
                    }
                }
            }
            i -= a;
        }
    }

    cout << answer << endl;
}
