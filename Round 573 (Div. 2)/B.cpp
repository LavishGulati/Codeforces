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

    int input[3][10];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            input[i][j] = 0;
        }
    }

    string s;
    for(int i = 0; i < 3; i++){
        cin >> s;
        if(s[1] == 'm') input[0][s[0]-'0']++;
        else if(s[1] == 'p') input[1][s[0]-'0']++;
        else input[2][s[0]-'0']++;
    }

    int answer = 3, x;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            answer = min(answer, 3-input[i][j]);
            if(j+2 < 10){
                x = 0;
                if(input[i][j] > 0) x++;
                if(input[i][j+1] > 0) x++;
                if(input[i][j+2] > 0) x++;
                answer = min(answer, 3-x);
            }
        }
    }

    cout << answer << endl;
}
