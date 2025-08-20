#include <bits/stdc++.h>

using namespace std;

struct Node{
    bool cima, baixo, esq, dir;
};

int n,numcomponente=0;
Node grid[101][101];
bool saovacas[101][101];
bool visited[101][101];
int componente[101];

void floodfill(int x,int y){
    if(visited[x][y]||(x<1||x>n||y<1||y>n)) return;
    visited[x][y]=true;
    if(saovacas[x][y]) componente[numcomponente]++;
    if(grid[x][y].cima) floodfill(x-1,y);
    if(grid[x][y].baixo) floodfill(x+1,y);
    if(grid[x][y].esq) floodfill(x,y-1);
    if(grid[x][y].dir) floodfill(x,y+1);
    return;
}

int main(){
    freopen("countcross.in", "r", stdin);
    freopen("countcross.out", "w", stdout);
    int k,r;
    cin>>n>>k>>r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            grid[i][j].baixo=true;
            grid[i][j].cima=true;
            grid[i][j].esq=true;
            grid[i][j].dir=true;
        }
    }
    for(int i=0;i<r;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int loc1,loc2;
        loc1=a-c;
        loc2=b-d;
        if(loc1==0){
            if(loc2==1){
                grid[a][b].esq=false;
                grid[c][d].dir=false;
            } else{
                grid[a][b].dir=false;
                grid[c][d].esq=false;
            }
        } else{
            if(loc1==1){
                grid[a][b].cima=false;
                grid[c][d].baixo=false;
            } else{
                grid[a][b].baixo=false;
                grid[c][d].cima=false;
            }
        }
    }
    vector<pair<int,int>> vacas(k);
    for(int i=0;i<k;i++){
        cin>>vacas[i].first>>vacas[i].second;
        saovacas[vacas[i].first][vacas[i].second]=true;
    }
    for(int i=0;i<k;i++){
        if(visited[vacas[i].first][vacas[i].second]) continue;
        numcomponente++;
        floodfill(vacas[i].first,vacas[i].second);
    }
    int numpairs=0;
    for(int i=1;i<=numcomponente;i++){
        for(int j=1;j<=numcomponente;j++){
            if(i==j) continue;
            numpairs+=componente[i]*componente[j];
        }
    }
    cout<<numpairs/2;
    return 0;
}
