#include <bits/stdc++.h>

using namespace std;

bool visited[200001];
int seguinte[200001];
int teleportations[200001];

void acessar(int i){
    queue<int> fila;
    stack<int> resto;
    while(!visited[i]){
        visited[i]=true;
        fila.push(i);
        i=seguinte[i];
    }
    while(!fila.empty()&&fila.front()!=i){
        resto.push(fila.front());
        fila.pop();
    }
    int tamciclo=(int)fila.size()+teleportations[i];
    while(!fila.empty()){
        teleportations[fila.front()]=tamciclo;
        fila.pop();
    }
    while(!resto.empty()){
        tamciclo++;
        teleportations[resto.top()]=tamciclo;
        resto.pop();
    }
    return;
}

int main(){
    //freopen("planting.in", "r", stdin);
    //freopen("planting.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>seguinte[i];
    }
    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        acessar(i);
    }
    for(int i=1;i<=n;i++){
        if(i!=1) cout<<" ";
        cout<<teleportations[i];
    }
    return 0;
}
