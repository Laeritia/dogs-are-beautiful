#include <bits/stdc++.h>

using namespace std;

int n,m;
char grid[1000][1000];
bool mark[1000][1000];

void floodfill(int x,int y){
    if((x<0||x>=n||y<0||y>=m)||mark[x][y]) return;
    if(grid[x][y]=='#'){
        mark[x][y]=true;
        return;
    }
    mark[x][y]=true;
    floodfill(x-1,y);
    floodfill(x+1,y);
    floodfill(x,y-1);
    floodfill(x,y+1);
}

int main(){
    //freopen("wormsort.in", "r", stdin);
    //freopen("wormsort.out", "w", stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int numquarto=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mark[i][j]) continue;
            if(grid[i][j]=='#'){
                mark[i][j]=true;
                continue;
            }
            numquarto++;
            floodfill(i,j);
        }
    }
    cout<<numquarto;
    return 0;
}
