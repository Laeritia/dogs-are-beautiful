#include <bits/stdc++.h>

using namespace std;

struct PCL{
    int toplinha,topcoluna;
    int bottomlinha,bottomcoluna;//definimos um retângulo com dois pontos.
    bool esta_dentro(PCL other){
        return (toplinha>=other.toplinha&&bottomlinha<=other.bottomlinha&&topcoluna>=other.topcoluna&&bottomcoluna<=other.bottomcoluna);
    }
};

char grid[21][21];
vector<PCL> plc_list;
bool visited[20][20];

void floodfill(PCL atual,int x,int y,char color){
    if((x<atual.toplinha||x>atual.bottomlinha||y<atual.topcoluna||y>atual.bottomcoluna)||visited[x][y]) return;
    if(grid[x][y]!=color) return;
    visited[x][y]=true;
    floodfill(atual,x-1,y,color);
    floodfill(atual,x+1,y,color);
    floodfill(atual,x,y-1,color);
    floodfill(atual,x,y+1,color);
    return;
}

void verificar_PCL(PCL atual){
    for(int i=atual.toplinha;i<=atual.bottomlinha;i++){
        for(int j=atual.topcoluna;j<=atual.bottomcoluna;j++){
            visited[i][j]=false;
        }
    }
    bool ePCL=true;
    char char1,char2='.';
    bool achou=false;
    int numcomponente1=0;
    int numcomponente2=0;
    char1=grid[atual.toplinha][atual.topcoluna];
    for(int i=atual.toplinha;i<=atual.bottomlinha;i++){
        for(int j=atual.topcoluna;j<=atual.bottomcoluna;j++){
            if(visited[i][j]) continue;
            if(achou&&(grid[i][j]!=char1&&grid[i][j]!=char2)){
                ePCL=false;
                break;
            }
            if(!achou&&grid[i][j]!=char1){
                char2=grid[i][j];
                achou=true;
            }
            if(grid[i][j]==char1) numcomponente1++;
            else numcomponente2++;
            floodfill(atual,i,j,grid[i][j]);
        }
        if(!ePCL) break;
    }
    if(ePCL&&(min(numcomponente1,numcomponente2)==1&&max(numcomponente1,numcomponente2)>1)) plc_list.push_back(atual);
    return;
}

int main(){
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int w=i;w<n;w++){
                for(int z=j;z<n;z++){
                    PCL novo;
                    novo.toplinha=i;
                    novo.topcoluna=j;
                    novo.bottomlinha=w;
                    novo.bottomcoluna=z;
                    verificar_PCL(novo);
                }
            }
        }
    }
    int ans=plc_list.size();
    int tamanho=ans;
    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            if(i==j) continue;
            if(plc_list[i].esta_dentro(plc_list[j])){
                ans--;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
