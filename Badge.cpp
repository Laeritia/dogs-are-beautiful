#include <bits/stdc++.h>

using namespace std;

int succ[1001];

int floyd(int x){
    int a,b;
    a=succ[x];
    b=succ[succ[x]];
    while(a!=b){
        a=succ[a];
        b=succ[succ[b]];
    }
    a=x;
    while(a!=b){
        a=succ[a];
        b=succ[b];
    }
    return a;
}

int main(){
    //freopen("planting.in", "r", stdin);
    //freopen("planting.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>succ[i];
    }
    for(int i=1;i<=n;i++){
        if(i!=1) cout<<" ";
        cout<<floyd(i);
    }
    return 0;
}
