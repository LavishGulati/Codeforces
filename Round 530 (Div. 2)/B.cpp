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

#define MAX 100000

bool isPerfectSquare(int n){
    ll si = 1;
    ll ei = MAX;
    while(si <= ei){
        ll mid = (si+ei)/2;
        if(mid*mid == n) return true;
        else if(mid*mid < n) si = mid+1;
        else ei = mid-1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    if(isPerfectSquare(n)){
        cout << int(sqrt(n))*2 << endl;
    }
    else{
        int x = int(sqrt(n)) + 1;
        cout << x*2 - (x*x-n)/x << endl;
    }
}
