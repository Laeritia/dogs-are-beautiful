#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,r,i;
    vector<int> vacas;
    vector<pair<int,int>> comprar;
    vector<int> vender;
    cin>>n>>m>>r;
    for(i=0;i<n;i++){
        int x;
        cin>>x;
        vacas.push_back(x);
    }
    sort(vacas.rbegin(),vacas.rend());
    for(i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        comprar.push_back({y,x});
    }
    sort(comprar.rbegin(),comprar.rend());
    for(i=0;i<r;i++){
        int x;
        cin>>x;
        vender.push_back(x);
    }
    sort(vender.rbegin(),vender.rend());
    long long ans=0;
    int indcomp=0;
    int indvend=0;
    for(i=0;i<n;i++){
        int galoes=0;
        long long valorleite=0;
        while(indcomp<m&&galoes<vacas[i]){
            if(vacas[i]-galoes>=comprar[indcomp].second){
                galoes+=comprar[indcomp].second;
                valorleite+=(ll)comprar[indcomp].second*(ll)comprar[indcomp].first;
                indcomp++;
            } else{
                valorleite+=(ll)(vacas[i]-galoes)*(ll)comprar[indcomp].first;
                comprar[indcomp].second-=(vacas[i]-galoes);
                galoes=vacas[i];
            }
        }
        while(indvend<r&&(n>i&&(ll)vender[indvend]>valorleite)){
            n--;
            ans+=(ll)vender[indvend];
            indvend++;
        }
        if(n>i) ans+=valorleite;
    }
    cout<<ans;
    return 0;
}
