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

bool compare(pii a, pii b){
    if(a.f < b.f) return true;
    else if(a.f == b.f) return a.s < b.s;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    if(n == 1){
        cout << "NO" << endl;
        return 0;
    }

    vector<pii> *input = new vector<pii>;
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        input->pb(mp(min(x,y)-1, max(x,y)-1));
    }

    sort(allp(input), compare);

    x = 0;
    y = 1;
    for(int i = 0; i < input->size(); i++){
        if(input->at(i).f == x && input->at(i).s == y){
            if(y == n-1){
                x++;
                y = x+1;
            }
            else y++;
        }
        else break;
    }

    if(x >= n-1){
        cout << "NO" << endl;
        return 0;
    }

    int **output = new int*[2];
    output[0] = new int[n];
    output[1] = new int[n];

    for(int i = 0; i < n; i++){
       output[0][i] = 0;
       output[1][i] = 0;
    }

    output[0][x] = 1;
    output[0][y] = 2;
    output[1][x] = 1;
    output[1][y] = 1;
    x = 3;
    for(int i = 0; i < n; i++){
        if(output[0][i] == 0){
            output[0][i] = x;
            output[1][i] = x;
            x++;
        }
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << output[0][i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++) cout << output[1][i] << " ";
    cout << endl;
}
