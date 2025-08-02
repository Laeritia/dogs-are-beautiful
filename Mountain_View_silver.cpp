#include <bits/stdc++.h>

using namespace std;

bool comparar(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main(){
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<pair<int,int>> intervalos(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        intervalos[i]={x-y,x+y};
    }
    sort(intervalos.begin(),intervalos.end(),comparar);
    int maisdireita=intervalos[0].second;
    int diminuir=0;
    for(int i=1;i<n;i++){
        if(intervalos[i].second<=maisdireita) diminuir++;
        else{
            maisdireita=intervalos[i].second;
        }
    }
    cout<<n-diminuir;
    return 0;
}
