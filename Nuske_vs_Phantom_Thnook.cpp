#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

char grid[2001][2001];
int pref[2002][2002];
int pref_linha[2002][2002];
int pref_coluna[2002][2002];;

int main(){
    int n,m,q,i,j;
    string s;
    cin>>n>>m>>q;
    grid[0][0]='0';
    for(i=1;i<=n;i++){
        cin>>s;
        grid[i][0]='0';
        for(j=1;j<=m;j++){
            grid[i][j]=s[j-1];
        }
    }
    i=0;
    while(i<=m){
        grid[0][i]='0';
        i++;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            int flag=0;
            if(grid[i][j]=='1'){
                if(grid[i-1][j]=='1'&&grid[i][j-1]=='1'){
                    pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]-1;//o caminho leva um merge, por isso o menos um
                    flag=1;
                }
                if(grid[i-1][j]=='0'&&grid[i][j-1]=='0'){
                    pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+1;//adiciona um novo componente
                    flag=1;
                }
                if(flag==0){
                    pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
                }
            } else{
                pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            pref_linha[i][j]=pref_linha[i][j-1];
            pref_coluna[i][j]=pref_coluna[i-1][j];
            if(grid[i][j]=='1'){
                pref_linha[i][j] += grid[i][j-1]=='0';
                pref_coluna[i][j] += grid[i-1][j]=='0';
            }
        }
    }
    for(i=0;i<q;i++){
        int x1,y1,x2,y2,res=0;
        cin>>x1>>y1>>x2>>y2;
        if(grid[x1][y1]=='1'){
            res++;
        }
        res+=(pref[x2][y2]-pref[x2][y1]-pref[x1][y2]+pref[x1][y1]);
        res+= (pref_linha[x1][y2]-pref_linha[x1][y1]);
        res+= (pref_coluna[x2][y1]-pref_coluna[x1][y1]);
        cout<<res<<endl;
    }
    return 0;
}

