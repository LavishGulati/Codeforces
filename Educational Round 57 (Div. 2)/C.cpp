#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
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

bool check(int angle, int n){
    int si = 1;
    int ei = n-2;
    int mid;
    while(si <= ei){
        mid = (si+ei)/2;
        double x = (((double(180))/(double(n)))*(double(mid)));
        if(angle == x) return true;
        else if(angle > x) si = mid+1;
        else ei = mid-1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int angle;
        cin >> angle;

        int n = 3;
        while(n <= 998244353){
            if(check(angle, n)){
                cout << n << endl;
                break;
            }
            n++;
        }
    }
}
