#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool els[100001];

int main(){
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int n,i;
    cin>>n;
    vector<int> bessie;
    vector<int> elsie(n);
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        els[x]=true;
        elsie[i]=x;
    }
    for(i=1;i<=2*n;i++){
        if(els[i]==false) bessie.push_back(i);
    }
    sort(elsie.begin(),elsie.begin()+n/2);
    sort(elsie.begin()+n/2,elsie.end());
    sort(bessie.begin(),bessie.end());
    int parambessie=n-1;
    int paramelsie=n/2-1;
    int pontos=0;
    while(paramelsie>=0){
        if(bessie[parambessie]>elsie[paramelsie]){
            parambessie--;
            pontos++;
        }
        paramelsie--;
    }
    parambessie=0;
    paramelsie=n/2;
    while(paramelsie<n){
        if(bessie[parambessie]<elsie[paramelsie]){
            parambessie++;
            pontos++;
        }
        paramelsie++;
    }
    cout<<pontos;
    return 0;
}
