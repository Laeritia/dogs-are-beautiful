#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arvore(100005);
string prefere;
int componente[100005];
int numcomponente=0;

void formador_de_componente(int atual, int ant, char vaca){//separa em componentes com G ou H
    if(prefere[atual-1]!=vaca) return;
    componente[atual]=numcomponente;
    for(auto u : arvore[atual]){
        if(u!=ant) formador_de_componente(u,atual,vaca);
    }
    return;
}

int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    cin>>prefere;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(componente[i]!=0) continue;
        numcomponente++;
        formador_de_componente(i,0,prefere[i-1]);
    }
    /*for(int i=1;i<=n;i++){
        cout<<componente[i]<<" ";
    }*/
    //cout<<endl;
    for(int i=0;i<m;i++){
        int a,b;
        char c;
        cin>>a>>b>>c;
        if(componente[a]!=componente[b]) cout<<1;
        else{
            if(prefere[a-1]==c) cout<<1;
            else cout<<0;
        }
    }
    return 0;
}
