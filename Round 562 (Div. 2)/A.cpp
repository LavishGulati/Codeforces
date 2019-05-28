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

    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    bool Cross1, Cross2;

    if(x < a) Cross1 = true;
    else Cross1 = false;

    if(y > b) Cross2 = true;
    else Cross2 = false;

    int time1, time2;
    bool answer = false;
    for(int i = 1; i <= n; i++){
        if(i >= a){
            if(Cross1) time1 = i-a;
            else if(i > x) time1 = INT_MAX;
            else time1 = i-a;
        }
        else{
            if(!Cross1) time1 = INT_MAX;
            else if(i <= x) time1 = n-a+i;
            else time1 = INT_MAX;
        }

        if(i > b){
            if(!Cross2) time2 = INT_MAX;
            else if(i >= y) time2 = n-i+b;
            else time2 = INT_MAX;
        }
        else{
            if(Cross2) time2 = b-i;
            else if(i >= y) time2 = b-i;
            else time2 = INT_MAX;
        }

        if(time1 != INT_MAX && time2 != INT_MAX & time1 == time2){
            answer = true;
            break;
        }
    }

    if(answer) cout << "YES" << endl;
    else cout << "NO" << endl;
}
