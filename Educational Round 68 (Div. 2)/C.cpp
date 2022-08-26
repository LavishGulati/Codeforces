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

bool IsSubseq(string s, string t){
    int n = s.length();
    int m = t.length();
    int i = 0;
    for(int j = 0; j < m; j++){
        if(i == n) break;
        if(s[i] == t[j]) i++;
    }
    if(i == n) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q;
    string s, t, p;

    int helper[3][26];
    cin >> q;
    bool ans;
    while(q--){
        ans = true;
        cin >> s >> t >> p;

        if(!IsSubseq(s, t)){
            cout << "NO" << endl;
            continue;
        }

        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 3; j++){
                helper[j][i] = 0;
            }
        }

        for(int i = 0; i < s.length(); i++){
            helper[0][s[i]-'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            helper[1][t[i]-'a']++;
        }
        for(int i = 0; i < p.length(); i++){
            helper[2][p[i]-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(helper[0][i]+helper[2][i] < helper[1][i]){
                ans = false;
                break;
            }
        }

        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
