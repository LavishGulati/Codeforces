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
    string s;
    cin >> s;

    int freq[n][26];
    for(int j = 0; j < 26; j++) freq[0][j] = 0;
    freq[0][s[0]-'a']++;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 26; j++){
            freq[i][j] = freq[i-1][j];
        }

        freq[i][s[i]-'a']++;
    }

    int q, m, si, ei, answer, mid;
    bool IsPossible;
    cin >> q;
    int helper[26];
    while(q--){
        cin >> s;
        m = s.length();
        for(int i = 0; i < 26; i++) helper[i] = 0;
        for(int i = 0; i < m; i++) helper[s[i]-'a']++;

        si = 0, ei = n-1;
        while(si <= ei){
            mid = (si+ei)/2;
            IsPossible = true;
            for(int i = 0; i < 26; i++){
                if(freq[mid][i] < helper[i]){
                    IsPossible = false;
                    break;
                }
            }

            if(IsPossible){
                answer = mid;
                ei = mid-1;
            }
            else si = mid+1;
        }

        cout << answer+1 << endl;
    }
}
