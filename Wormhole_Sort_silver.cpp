#include <bits/stdc++.h>

using namespace std;

int n;
bool visitado[100002];
int componente[100002];
vector<int> posicoes(100002);
vector<vector<pair<int,int>>> grafo(100001);

void dfs(int x,int res){
    if(visitado[x]) return;
    visitado[x]=true;
    for(auto u:grafo[x]){
        if(u.second>=res){
            componente[u.first]=componente[x];
            dfs(u.first,res);
        }
    }
}

bool check(int res){
    for(int i=1;i<=n;i++){
        visitado[i]=false;
        componente[i]=0;
    }
    int numcomponente=0;
    for(int i=1;i<=n;i++){
        if(visitado[i]) continue;
        numcomponente++;
        componente[i]=numcomponente;
        dfs(i,res);
    }
    //if(res==464787753||res==463245283) cout<<res<<" "<<numcomponente<<endl;
    for(int i=1;i<=n;i++){
        if(componente[i]!=componente[posicoes[i]]) return false;
    }
    return true;
}

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>posicoes[i];
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        grafo[a].push_back({b,c});
        grafo[b].push_back({a,c});
    }
    int lo=0;
    int hi=1e9+1;
    while(lo<hi){
        int mid=lo+(hi-lo+1)/2;
        if(check(mid)){
            lo=mid;
        }
        else hi=mid-1;
    }
    int flag=0;
    for(int i=1;i<=n;i++){
        if(posicoes[i]!=i){
            flag=1;
            cout<<lo;
            break;
        }
    }
    if(flag==0) cout<<-1;
    return 0;
}
