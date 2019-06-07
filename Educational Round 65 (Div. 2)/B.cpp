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

    int output[6];
    int helper[4];
    cout << "? 1 2" << endl;
    cin >> helper[0];
    cout << "? 2 3" << endl;
    cin >> helper[1];
    cout << "? 4 5" << endl;
    cin >> helper[2];
    cout << "? 5 6" << endl;
    cin >> helper[3];

    for(int i = 0; i < 4; i += 2){
        if(helper[i]%23 == 0 && helper[i+1]%23 != 0){
            output[3*(i/2)+0] = 23;
            output[3*(i/2)+1] = helper[i]/23;
            output[3*(i/2)+2] = helper[i+1]/output[3*(i/2)+1];
        }
        else if(helper[i]%23 != 0 && helper[i+1]%23 == 0){
            output[3*(i/2)+1] = helper[i+1]/23;
            output[3*(i/2)+0] = helper[i]/output[3*(i/2)+1];
            output[3*(i/2)+2] = 23;
        }
        else if(helper[i]%23 == 0 && helper[i+1]%23 == 0){
            output[3*(i/2)+0] = helper[i]/23;
            output[3*(i/2)+1] = 23;
            output[3*(i/2)+2] = helper[i+1]/23;
        }
        else if(helper[i]%7 == 0 && helper[i+1]%7 != 0){
            output[3*(i/2)+0] = 42;
            output[3*(i/2)+1] = helper[i]/42;
            output[3*(i/2)+2] = helper[i+1]/output[3*(i/2)+1];
        }
        else if(helper[i]%7 != 0 && helper[i+1]%7 == 0){
            output[3*(i/2)+1] = helper[i+1]/42;
            output[3*(i/2)+0] = helper[i]/output[3*(i/2)+1];
            output[3*(i/2)+2] = 42;
        }
        else if(helper[i]%7 == 0 && helper[i+1]%7 == 0){
            output[3*(i/2)+0] = helper[i]/42;
            output[3*(i/2)+1] = 42;
            output[3*(i/2)+2] = helper[i+1]/42;
        }
        else if(helper[i]%5 == 0 && helper[i+1]%5 != 0){
            output[3*(i/2)+0] = 15;
            output[3*(i/2)+1] = helper[i]/15;
            output[3*(i/2)+2] = helper[i+1]/output[3*(i/2)+1];
        }
        else if(helper[i]%5 != 0 && helper[i+1]%5 == 0){
            output[3*(i/2)+1] = helper[i+1]/15;
            output[3*(i/2)+0] = helper[i]/output[3*(i/2)+1];
            output[3*(i/2)+2] = 15;
        }
        else if(helper[i]%5 == 0 && helper[i+1]%5 == 0){
            output[3*(i/2)+0] = helper[i]/15;
            output[3*(i/2)+1] = 15;
            output[3*(i/2)+2] = helper[i+1]/15;
        }
        else if(helper[i] == 32){
            if(helper[i+1] == 128){
                output[3*(i/2)+0] = 4; output[3*(i/2)+1] = 8; output[3*(i/2)+2] = 16;
            }
            else{
                output[3*(i/2)+0] = 8; output[3*(i/2)+1] = 4; output[3*(i/2)+2] = 16;
            }
        }
        else if(helper[i] == 64){
            if(helper[i+1] == 128){
                output[3*(i/2)+0] = 4; output[3*(i/2)+1] = 16; output[3*(i/2)+2] = 8;
            }
            else{
                output[3*(i/2)+0] = 16; output[3*(i/2)+1] = 4; output[3*(i/2)+2] = 8;
            }
        }
        else{
            if(helper[i+1] == 64){
                output[3*(i/2)+0] = 8; output[3*(i/2)+1] = 16; output[3*(i/2)+2] = 4;
            }
            else{
                output[3*(i/2)+0] = 16; output[3*(i/2)+1] = 8; output[3*(i/2)+2] = 4;
            }
        }
    }

    cout << "! ";
    for(int i = 0; i < 6; i++) cout << output[i] << " ";
    cout << endl;
}
