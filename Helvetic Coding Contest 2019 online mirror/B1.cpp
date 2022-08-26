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

    ll s, b;
    cin >> s >> b;

    pll A[s];
    for(ll i = 0; i < s; i++){
        cin >> A[i].f;
        A[i].s = i;
    }

    pll DG[b];
    for(ll i = 0; i < b; i++){
        cin >> DG[i].f >> DG[i].s;
    }

    sort(A, A+s);
    sort(DG, DG+b);

    ll output[s];
    ll j = 0;
    ll total = 0;
    for(ll i = 0; i < s; i++){
        while(j < b && DG[j].f <= A[i].f){
            total += DG[j].s;
            j++;
        }
        output[A[i].s] = total;
    }

    for(ll i = 0; i < s; i++){
        cout << output[i] << " ";
    }
    cout << endl;
}
