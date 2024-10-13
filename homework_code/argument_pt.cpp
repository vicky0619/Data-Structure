#include <bits/stdc++.h>
using namespace std;

int t = 0;
int par[55], dfn[55], low[55], isAP[55];
map<int, set<int> > adj;

void init(){
    t = 0;
    for(int i=0; i<55; i++){
        par[i] = -1;
        dfn[i] = -1;
        low[i] = -1;
        isAP[i] = false;
    }
    return;
}

void articPt(int u, int d){
    dfn[u] = d;
    low[u] = d;
    int cnt = 0;
    for(auto v:adj[u]){
        if(dfn[v]<0){
            cnt++;
            par[v] = u;
            articPt(v, d+1);
            if(dfn[u]<=low[v]) isAP[u] = true;
            if(low[v]<low[u]) low[u] = low[v];
        }
        else if(v!=par[u]){
            if(dfn[v]<low[u]) low[u] = dfn[v];
        }
    }
    if(dfn[u]==0){
        if(cnt>1) isAP[u] = true;
        else isAP[u] = false;
    }
    return;
}


int main(){
    int a, b, s;
    string line;
    while(getline(cin, line)){
        if(line.length()<=0) break;
        stringstream ss(line);
        ss >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
        s = a;
    }
    init();
    articPt(0, 0);
    int apCnt = 0;
    for(int i=0; i<55; i++) if(isAP[i]) apCnt++;
    if(apCnt>0){
        cout << "false\n";
        for(int i=0; i<55; i++){
            if(isAP[i]){
                cout << i;
                if(apCnt>1) cout << " ";
                apCnt--;
            }
        }
    }
    else cout << "true";

    return 0;
}