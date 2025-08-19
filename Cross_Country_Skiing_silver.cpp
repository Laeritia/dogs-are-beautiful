#include <bits/stdc++.h>

using namespace std;

int grid[500][500];
bool visited[500][500];
vector<pair<int,int>> waypoints;
int n,m;

void floodfill(int x,int y,int res){
    if((x<0||x>=n||y<0||y>=m)||visited[x][y]) return;
    visited[x][y]=true;
    if(abs(grid[x][y]-grid[x-1][y])<=res) floodfill(x-1,y,res);
    if(abs(grid[x][y]-grid[x+1][y])<=res) floodfill(x+1,y,res);
    if(abs(grid[x][y]-grid[x][y-1])<=res) floodfill(x,y-1,res);
    if(abs(grid[x][y]-grid[x][y+1])<=res) floodfill(x,y+1,res);
    return;
}

bool check(int res){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=false;
        }
    }
    floodfill(waypoints[0].first,waypoints[0].second,res);
    for(int i=1;i<(int)waypoints.size();i++){
        if(!visited[waypoints[i].first][waypoints[i].second]) return false;
    }
    return true;
}

int main(){
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            if(x==1) waypoints.push_back({i,j});
        }
    }
    int lo=0;
    int hi=1e9+1;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid)) hi=mid;
        else lo=mid+1;
    }
    cout<<hi;
    return 0;
}
