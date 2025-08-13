#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int vacas[200][3];
vector<vector<int>> grafo(200);
bool visitado[200];

float distance(int a,int b){
    ll quadrado=(ll)pow(vacas[a][0]-vacas[b][0],2)+(ll)pow(vacas[a][1]-vacas[b][1],2);
    float res=sqrt(quadrado);
    return res;
}

int dfs(int x){
    if(visitado[x]) return 0;
    int res=0;
    visitado[x]=true;
    for(auto u:grafo[x]){
        res+=dfs(u);
    }
    res++;
    return res;
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n,i,j;

    cin>>n;
    for(i=0;i<n;i++){
        cin>>vacas[i][0]>>vacas[i][1]>>vacas[i][2];
    }
    //se a vaca i alcançar a jota, adiciono j.
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j) continue;
            if(distance(i,j)<=(float)(vacas[i][2])) grafo[i].push_back(j);
        }
    }
    int nummax=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++) visitado[j]=false;
        nummax=max(nummax,dfs(i));
    }
    cout<<nummax;
    return 0;
}
