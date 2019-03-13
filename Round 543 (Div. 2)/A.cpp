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

    int n, m, k;
    cin >> n >> m >> k;
    pii stud[n];
    for(int i = 0; i < n; i++) cin >> stud[i].f;
    for(int i = 0; i < n; i++) cin >> stud[i].s;

    int id[k];
    for(int i = 0; i < k; i++) cin >> id[i];

    int answer = 0;
    for(int i = 0; i < k; i++){
        int studId = id[i]-1;
        int maxStud = stud[studId].f;
        for(int j = 0; j < n; j++){
            if(stud[j].s == stud[studId].s && maxStud < stud[j].f){
                maxStud = stud[j].f;
            }
        }
        if(stud[studId].f != maxStud) answer++;
    }

    cout << answer << endl;
}
