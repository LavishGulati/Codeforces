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

int X[667], Y[667];

bool isRookPresent(int x, int y){
    for(int i = 1; i <= 666; i++){
        if(X[i] == x && Y[i] == y) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int u, v;
    cin >> u >> v;

    for(int i = 1; i <= 666; i++){
        cin >> X[i] >> Y[i];
    }

    int k, x, y;
    while(u != 500 || v != 500){
        if(u < 500){
            cout << u+1 << " " << v << endl;
            u++;
        }
        else if(u > 500){
            cout << u-1 << " " << v << endl;
            u--;
        }
        else if(v < 500){
            cout << u << " " << v+1 << endl;
            v++;
        }
        else if(v > 500){
            cout << u << " " << v-1 << endl;
            v--;
        }

        cin >> k >> x >> y;
        if(k == -1) return 0;
        else{
            X[k] = x;
            Y[k] = y;
        }
    }

    int upLeft = 0, upRight = 0, downLeft = 0, downRight = 0;
    for(int i = 1; i <= 666; i++){
        if(X[i] < 500 || Y[i] < 500) upLeft++;
        if(X[i] > 500 || Y[i] < 500) downLeft++;
        if(X[i] < 500 || Y[i] > 500) upRight++;
        if(X[i] > 500 || Y[i] > 500) downRight++;
    }

    int direction = max({upLeft, downLeft, upRight, downRight});
    if(direction == upLeft){
        while(1){
            if(isRookPresent(u-1, v-1)){
                cout << u-1 << " " << v << endl;
                u--;
            }
            else{
                cout << u-1 << " " << v-1 << endl;
                u--; v--;
            }

            cin >> k >> x >> y;
            if(k == -1) return 0;
            else{
                X[k] = x;
                Y[k] = y;
            }
        }
    }
    else if(direction == downLeft){
        while(1){
            if(isRookPresent(u+1, v-1)){
                cout << u+1 << " " << v << endl;
                u++;
            }
            else{
                cout << u+1 << " " << v-1 << endl;
                u++; v--;
            }

            cin >> k >> x >> y;
            if(k == -1) return 0;
            else{
                X[k] = x;
                Y[k] = y;
            }
        }
    }
    else if(direction == upRight){
        while(1){
            if(isRookPresent(u-1, v+1)){
                cout << u-1 << " " << v << endl;
                u--;
            }
            else{
                cout << u-1 << " " << v+1 << endl;
                u--; v++;
            }

            cin >> k >> x >> y;
            if(k == -1) return 0;
            else{
                X[k] = x;
                Y[k] = y;
            }
        }
    }
    else if(direction == downRight){
        while(1){
            if(isRookPresent(u+1, v+1)){
                cout << u+1 << " " << v << endl;
                u++;
            }
            else{
                cout << u+1 << " " << v+1 << endl;
                u++; v++;
            }

            cin >> k >> x >> y;
            if(k == -1) return 0;
            else{
                X[k] = x;
                Y[k] = y;
            }
        }
    }
}
