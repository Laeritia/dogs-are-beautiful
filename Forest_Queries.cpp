#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int floresta[1001][1001];

int main(){
    int n,q,i,j;
    string linha;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        cin>>linha;
        for(j=1;j<=n;j++){
            if(linha[j-1]=='*'){
                floresta[i][j]=1;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            floresta[i][j]=floresta[i-1][j]+floresta[i][j-1]-floresta[i-1][j-1]+floresta[i][j];
        }
    }
    int y1,x1,y2,x2;
    for(j=0;j<q;j++){
        cin>>x1>>y1>>x2>>y2;
        cout<<floresta[x2][y2]-floresta[x1-1][y2]-floresta[x2][y1-1]+floresta[x1-1][y1-1]<<endl;
    }
    return 0;
}

