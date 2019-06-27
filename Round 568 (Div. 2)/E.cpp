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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        char **grid = new char *[n];
        for(int i = 0; i < n; i++){
            grid[i] = new char[m];
            for(int j = 0; j < m; j++) cin >> grid[i][j];
        }

        vector<pii> helper[26];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != '.'){
                    helper[grid[i][j]-'a'].pb(mp(i, j));
                }
            }
        }

        bool ans;
        int x, a, b;
        char c;
        int num = 25;
        while(num >= 0 && helper[num].size() == 0) num--;
        num++;

        if(num == 0){
            cout << "YES\n0" << endl;
            continue;
        }

        for(int i = 0; i < num; i++){
            ans = true;

            if(helper[i].size() == 0) continue;

            a = helper[i][0].f;
            b = helper[i][0].s;
            if(helper[i].size() == 1) continue;

            if(helper[i][0].f == helper[i][1].f){
                x = helper[i][0].f;
                c = 'R';
            }
            else if(helper[i][0].s == helper[i][1].s){
                x = helper[i][0].s;
                c = 'C';
            }
            else{
                ans = false;
            }

            if(!ans) break;

            for(int j = 2; j < helper[i].size(); j++){
                if(c == 'R' && helper[i][j].f != x){
                    ans = false;
                    break;
                }
                if(c == 'C' && helper[i][j].s != x){
                    ans = false;
                    break;
                }
            }
            if(!ans) break;
        }

        if(!ans){
            cout << "NO" << endl;
            continue;
        }

        for(int i = 0; i < num; i++){
            sort(all(helper[i]));
        }

        int l;
        ans = true;
        for(int i = num-1; i >= 0; i--){
            l = helper[i].size();
            if(l <= 1) continue;
            if(helper[i][0].f == helper[i][l-1].f){
                for(int j = helper[i][0].s; j <= helper[i][l-1].s; j++){
                    if(grid[helper[i][0].f][j]-'a' < i){
                        // cout << i << " " << helper[i][0].f << " " << j << endl;
                        ans = false;
                        break;
                    }
                }
                if(!ans) break;
            }
            else{
                for(int j = helper[i][0].f; j <= helper[i][l-1].f; j++){
                    if(grid[j][helper[i][0].s]-'a' < i){
                        // cout << i << " " << helper[i][0].f << " " << j << endl;
                        ans = false;
                        break;
                    }
                }
                if(!ans) break;
            }
        }

        if(!ans){
            cout << "NO" << endl;
            continue;
        }


        cout << "YES" << endl;
        cout << num << endl;
        int k;
        for(int i = 0; i < num; i++){
            k = helper[i].size();
            if(k == 0){
                cout << a+1 << " " << b+1 << " " << a+1 << " " << b+1 << endl;
            }
            else{
                cout << helper[i][0].f+1 << " " << helper[i][0].s+1 << " " << helper[i][k-1].f+1 << " " << helper[i][k-1].s+1 << endl;
            }
        }
    }
}
