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

bool IsPlus(string *input, int row, int col, int h, int w){
    if(row == 0 || input[row-1][col] == '.') return false;
    if(col == 0 || input[row][col-1] == '.') return false;
    if(col == w-1 || input[row][col+1] == '.') return false;
    if(row == h-1 || input[row+1][col] == '.') return false;

    return true;
}

void mark(string *input, int row, int col, int h, int w){
    input[row][col] = '.';

    for(int i = row+1; i < h; i++){
        if(input[i][col] == '.') break;
        else input[i][col] = '.';
    }

    for(int i = row-1; i >= 0; i--){
        if(input[i][col] == '.') break;
        else input[i][col] = '.';
    }

    for(int j = col+1; j < w; j++){
        if(input[row][j] == '.') break;
        else input[row][j] = '.';
    }

    for(int j = col-1; j >= 0; j--){
        if(input[row][j] == '.') break;
        else input[row][j] = '.';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int h, w;
    cin >> h >> w;
    string *input = new string[h];
    for(int i = 0; i < h; i++){
        cin >> input[i];
    }

    bool answer = false;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(!answer){
                if(input[i][j] == '*' && IsPlus(input, i, j, h, w)){
                    answer = true;
                    mark(input, i, j, h, w);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(input[i][j] == '*'){
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if(answer){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
