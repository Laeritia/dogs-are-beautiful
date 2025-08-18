#include <bits/stdc++.h>

using namespace std;

string grid[1000];
bool visited[1000][1000];
int n,perimetro,menorperimetro,maiorarea,area;

void floodfill(int x,int y){
    if((x<0||x>=n||y<0||y>=n)||grid[x][y]=='.') return;
    if(visited[x][y]){
        perimetro--;
        return;
    }
    visited[x][y]=true;
    if(area!=0) perimetro+=3;
    area++;
    floodfill(x-1,y);
    floodfill(x+1,y);
    floodfill(x,y-1);
    floodfill(x,y+1);
    return;
}

int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    maiorarea=0;
    menorperimetro=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]||grid[i][j]=='.') continue;
            area=0;
            perimetro=4;
            floodfill(i,j);
            if(area==maiorarea) menorperimetro=min(menorperimetro,perimetro);
            if(area>maiorarea){
                menorperimetro=perimetro;
                maiorarea=area;
            }
        }
    }
    cout<<maiorarea<<" "<<menorperimetro;
    return 0;
}
