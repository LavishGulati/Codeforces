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
#define fir first
#define sec second
#define MOD 1000000007
#define PI acos(-1)

pii insert(char **board, char c){
    if(c == '0'){
        for(int i = 0; i < 4; i += 2){
            for(int j = 0; j < 4; j++){
                if(board[i][j] == 't' && board[i+1][j] == 't' && board[(i+2)%4][j] == '.' && board[(i+3)%4][j] == '.'){
                    board[(i+2)%4][j] = 't';
                    board[(i+3)%4][j] = 't';
                    return mp((i+2)%4, j);
                }
            }
        }

        for(int i = 0; i < 4; i++){
            int count = 0;
            for(int j = 0; j < 4; j++){
                if(board[i][j] == 't') count++;
            }

            if(count == 3){
                for(int j = 0; j < 4; j++){
                    if(board[i][j] == '.'){
                        if(i == 0 && board[1][j] == '.'){
                            board[0][j] = 't';
                            board[1][j] = 't';
                            return mp(0, j);
                        }
                        else if(i > 0 && board[i-1][j] == '.'){
                            board[i-1][j] = 't';
                            board[i][j] = 't';
                            return mp(i-1, j);
                        }
                        else if(i > 0 && board[i+1][j] == '.'){
                            board[i][j] = 't';
                            board[i+1][j] = 't';
                            return mp(i, j);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                if(board[i][j] == '.' && board[i+1][j] == '.'){
                    board[i][j] = 't';
                    board[i+1][j] = 't';
                    return mp(i, j);
                }
            }
        }
    }
    else{
        for(int j = 0; j < 4; j += 2){
            for(int i = 0; i < 4; i++){
                if(board[i][j] == 't' && board[i][j+1] == 't' && board[i][(j+2)%4] == '.' && board[i][(j+3)%4] == '.'){
                    board[i][(j+2)%4] = 't';
                    board[i][(j+3)%4] = 't';
                    return mp(i, (j+2)%4);
                }
            }
        }

        for(int j = 0; j < 4; j++){
            int count = 0;
            for(int i = 0; i < 4; i++){
                if(board[i][j] == 't') count++;
            }

            if(count == 3){
                for(int i = 0; i < 4; i++){
                    if(board[i][j] == '.'){
                        if(j == 0 && board[i][1] == '.'){
                            board[i][0] = 't';
                            board[i][1] = 't';
                            return mp(i, 0);
                        }
                        else if(j > 0 && board[i][j-1] == '.'){
                            board[i][j-1] = 't';
                            board[i][j] = 't';
                            return mp(i, j-1);
                        }
                        else if(j > 0 && board[i][j+1] == '.'){
                            board[i][j] = 't';
                            board[i][j+1] = 't';
                            return mp(i, j);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == '.' && board[i][j+1] == '.'){
                    board[i][j] = 't';
                    board[i][j+1] = 't';
                    return mp(i, j);
                }
            }
        }
    }
}

void deleteBoard(char **board){
    bool isComplete;
    for(int i = 0; i < 4; i++){
        isComplete = true;
        for(int j = 0; j < 4; j++){
            if(board[i][j] != 't'){
                isComplete = false;
                break;
            }
        }
        if(isComplete){
            for(int j = 0; j < 4; j++){
                board[i][j] = '.';
            }
        }
    }

    for(int j = 0; j < 4; j++){
        isComplete = true;
        for(int i = 0; i < 4; i++){
            if(board[i][j] != 't'){
                isComplete = false;
                break;
            }
        }
        if(isComplete){
            for(int i = 0; i < 4; i++){
                board[i][j] = '.';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    char **board = new char *[4];
    for(int i = 0; i < 4; i++){
        board[i] = new char[4];
        for(int j = 0; j < 4; j++) board[i][j] = '.';
    }

    for(int i = 0; i < s.length(); i++){
        pii point = insert(board, s[i]);
        cout << point.fir+1 << " " << point.sec+1 << endl;
        deleteBoard(board);
    }
}
