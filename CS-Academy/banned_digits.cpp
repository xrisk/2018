#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#define LL long long

using namespace std;

bool banned[10];

pair<LL, vector<int> > split(LL x) {
    vector<int> dig;
    while (x > 0) {
        dig.push_back(x % 10);
        x /= 10;
    }
    reverse(dig.begin(), dig.end());
    
    return make_pair(dig[0], dig);
}

LL len(LL x) {
    int cnt = 0;
    while (x > 0) { cnt ++; x /= 10;
    } return cnt;
}


long long solve( vector<int> x, bool f) {
    if (x.size() == 1) {
        int cnt = 0;
        for (int i = 0; i < (f ? 10 : x[0]); i++) {
            if (!banned[i]) cnt++;
        }
        return cnt;
    }
    vector<int> rst = vector<int>(x.begin() + 1, x.end());
    pair< LL, vector<int> > pr = make_pair(x[0], rst);
 
    

    int retpart = 1;
    
    int cnt = 0;
    for (int i = 0; i < 10; i++ ) if (!banned[i]) cnt++;
    retpart *= pow(cnt, pr.second.size());
    
    cnt = 0;
    for (int i = 0; i < pr.first; i++) if (!banned[i] || i == 0) cnt++;
    retpart *= cnt;
    
    if (banned[x[0]] ) return retpart;
    else
    return retpart + solve(pr.second, false);
}

int main() {

    #ifdef __APPLE__
    freopen("input.txt", "r", stdin);
    #endif
 
    for (int i = 0; i < 10; i++) {
        int x; cin >> x;
        banned[i] = (x == 1);
    }
    LL x; cin >> x;



    if (x < 10) {
        int cnt = 0;
        for (int i = 0; i < x; i++) if (!banned[i]) cnt++;
        cout << cnt << '\n';
        return 0;
    }
    vector<int> vec;
    while (x) { vec.push_back(x % 10); x /= 10; };
    reverse(vec.begin(), vec.end());
    cout << solve(vec, true) << '\n';
    
    
    
}