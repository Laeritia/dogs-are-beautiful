#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,char>>> grafo(100001);
bool visited[100001];
int cor[100001];
queue<int> fila;

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    bool impossible=false;
    int n,m,i;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        char a;
        cin>>a;
        int b,c;
        cin>>b>>c;
        grafo[b].push_back({c,a});
        grafo[c].push_back({b,a});
    }
    int numcomponente=0;
    for(i=1;i<=n;i++){
        if(visited[i]) continue;
        numcomponente++;
        visited[i]=true;
        cor[i]=1;
        fila.push(i);
        while(!fila.empty()){
            int s=fila.front();
            fila.pop();
            for(auto u:grafo[s]){
                if(visited[u.first]){
                    if(u.second=='S'&&cor[u.first]!=cor[s]){
                        impossible=true;
                        break;
                    }
                    if(u.second=='D'&&cor[u.first]==cor[s]){
                        impossible=true;
                        break;
                    }
                    continue;
                }
                visited[u.first]=true;
                if(u.second=='S') cor[u.first]=cor[s];
                else{
                    if(cor[s]==1) cor[u.first]=2;
                    if(cor[s]==2) cor[u.first]=1;
                }
                fila.push(u.first);
            }
            if(impossible==true) break;
        }
        if(impossible==true) break;
    }
    if(impossible) cout<<0;
    else{
        cout<<1;
        for(int i=0;i<numcomponente;i++){
            cout<<0;
        }
    }
    return 0;
}
