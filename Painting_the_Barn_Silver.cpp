#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int muro[1002][1002];

int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n,k,i,j,x1,x2,y1,y2,num_correto=0;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        muro[x1][y1]++;
        muro[x2][y1]--;
        muro[x1][y2]--;
        muro[x2][y2]++;
    }
    for(i=0;i<=1000;i++){
        for(j=0;j<=1000;j++){
            if(i>0) muro[i][j]+=muro[i-1][j];
            if(j>0) muro[i][j]+=muro[i][j-1];
            if(i>0&&j>0) muro[i][j]-=muro[i-1][j-1];
            if(muro[i][j]==k){
                num_correto++;
            }
        }
    }
    cout<<num_correto;
    return 0;
}

