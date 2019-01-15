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

struct rook{
    int num, x, y, dist;

    rook(){

    }

    rook(int num, int x, int y, int d){
        this->num = num;
        this->x = x;
        this->y = y;
        this->dist = d;
    }


};

struct compare{
    bool operator() (rook const& a, rook const& b){
        return a.dist > b.dist;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n = 1000;
    int numRooks = 666;

    // cout << "YUP3" << endl;

    char board[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            // cout << i << " " << j << endl;
            board[i][j] = '.';
        }
    }

    // cout << "YUP4" << endl;

    int x, y, u, v;
    cin >> x >> y;
    board[x][y] = 'k';
    u = x;
    v = y;

    // cout << "YUP2" << endl;

    rook a, b;
    priority_queue<rook, vector<rook>, compare> pq;

    for(int i = 1; i <= numRooks; i++){
        cin >> x >> y;
        board[x][y] = 'r';
        int dist = min(abs(u-x), abs(v-y));
        a = rook(i, x, y, dist);
        pq.push(a);
    }

    // cout << "YUP" << endl;

    bool isMoved;
    int aa, bb, cc;
    while(1){
        // cout << "YES" << endl;
        isMoved = false;
        board[u][v] = '.';

        a = pq.top();
        pq.pop();
        b = pq.top();

        if(abs(u-a.x) <= abs(v-a.y)){
            if(u > a.x){
                if(b.y < v && a.y < v && board[u-1][v-1] != 'r'){
                    cout << u-1 << " " << v-1 << endl;
                    u--; v--;
                    isMoved = true;
                }
                else if(b.y > v && a.y > v && board[u-1][v+1] != 'r'){
                    cout << u-1 << " " << v+1 << endl;
                    u--; v++;
                    isMoved = true;
                }

                if(!isMoved){
                    cout << u-1 << " " << v << endl;
                    u--;
                    isMoved = true;
                }
            }
            else{
                if(b.y < v && a.y < v && board[u+1][v-1] != 'r'){
                    cout << u+1 << " " << v-1 << endl;
                    u++; v--;
                    isMoved = true;
                }
                else if(b.y > v && a.y > v && board[u+1][v+1] != 'r'){
                    cout << u+1 << " " << v+1 << endl;
                    u++; v++;
                    isMoved = true;
                }

                if(!isMoved){
                    cout << u+1 << " " << v << endl;
                    u++;
                    isMoved = true;
                }
            }
        }
        else{
            if(v > a.y){
                if(b.x < u && a.x < u && board[u-1][v-1] != 'r'){
                    cout << u-1 << " " << v-1 << endl;
                    u--; v--;
                    isMoved = true;
                }
                else if(b.x > u && a.x > u && board[u+1][v-1] != 'r'){
                    cout << u+1 << " " << v-1 << endl;
                    u++; v--;
                    isMoved = true;
                }

                if(!isMoved){
                    cout << u << " " << v-1 << endl;
                    v--;
                    isMoved = true;
                }
            }
            else{
                if(b.x < u && a.x < u && board[u-1][v+1] != 'r'){
                    cout << u-1 << " " << v+1 << endl;
                    u--; v++;
                    isMoved = true;
                }
                else if(b.x > u && a.x > u && board[u+1][v+1] != 'r'){
                    cout << u+1 << " " << v+1 << endl;
                    u++; v++;
                    isMoved = true;
                }

                if(!isMoved){
                    cout << u << " " << v+1 << endl;
                    v++;
                    isMoved = true;
                }
            }
        }

        // if(!isMoved){
        //     cout << "Not moved" << endl;
        //     break;
        // }

        pq.push(a);
        board[u][v] = 'k';

        cin >> aa >> bb >> cc;

        if(aa == -1 && bb == -1 && cc == -1) break;

        stack<rook> st;
        while(pq.top().num != aa){
            st.push(pq.top());
            pq.pop();
        }

        a = pq.top();
        pq.pop();
        while(st.size() != 0){
            pq.push(st.top());
            st.pop();
        }

        board[a.x][a.y] = '.';
        a.x = bb;
        a.y = cc;
        board[a.x][a.y] = 'r';
        a.dist = min(abs(u-a.x), abs(v-a.y));
        pq.push(a);
    }
}
