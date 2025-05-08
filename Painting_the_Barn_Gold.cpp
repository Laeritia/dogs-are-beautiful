#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int muro[201][201];
int soma_prefix[201][201];
int top_best[201];
int bottom_best[201];
int left_best[201];
int right_best[201];

int sub_soma(int topo,int esq,int baix,int dir){
        return soma_prefix[baix+1][dir+1]-soma_prefix[baix+1][esq]-soma_prefix[topo][dir+1]+soma_prefix[topo][esq];
}


int main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    int n,k,i,area=0,x1,y1,x2,y2,j,z;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>x1>>y1>>x2>>y2;
        muro[x1][y1]++;
        muro[x2][y2]++;
        muro[x2][y1]--;
        muro[x1][y2]--;
    }
    for(i=0;i<200;i++){//pintar o muro
        for(j=0;j<200;j++){
            if(i>0&&j>0){
                muro[i][j]+=(muro[i-1][j]+muro[i][j-1]-muro[i-1][j-1]);
            } else{
                if(i>0){
                    muro[i][j]+=muro[i-1][j];
                }
                if(j>0){
                    muro[i][j]+=muro[i][j-1];
                }
            }
        }
    }
    for(i=0;i<200;i++){//substitui para maximar a area
        for(j=0;j<200;j++){
            if(muro[i][j]!=k&&muro[i][j]!=k-1){
                muro[i][j]=0;
            } else{
                if(muro[i][j]==k){
                    muro[i][j]=-1;
                    area++;
                }
                if(muro[i][j]==k-1)
                    muro[i][j]=1;
            }
        }
    }
    for(i=1;i<=200;i++){//soma de prefixo para matriz
        for(j=1;j<=200;j++){
            soma_prefix[i][j]=soma_prefix[i-1][j]+soma_prefix[i][j-1]-soma_prefix[i-1][j-1]+muro[i-1][j-1];
        }
    }
    for(i=0;i<200;i++){//tentar achar a submatriz maxima para: top_best: melhor matriz que tem topo i. Botto_best: melhor matriz com bottom i
            //left_best: melhor matriz que vai até linha i. right_best: melhor matriz com lado esquerdo em i.
        for(j=i;j<200;j++){
            int top_sum=0;
            int left_sum=0;
            int soma_analisada;
            for(z=1;z<=200;z++){
                soma_analisada=top_sum+sub_soma(z-1,i,z-1,j);
                top_best[z]=max(top_best[z], top_sum=max(0,soma_analisada));
                soma_analisada=left_sum+sub_soma(i,z-1,j,z-1);
                left_best[z]=max(left_best[z], left_sum=max(0,soma_analisada));
            }
            int bottom_sum=0;
            int right_sum=0;
            for(z=199;z>0;z--){
                soma_analisada=bottom_sum+sub_soma(z,i,z,j);
                bottom_best[z]=max(bottom_best[z], bottom_sum=max(0,soma_analisada));
                soma_analisada=right_sum+sub_soma(i,z,j,z);
                right_best[z]=max(right_best[z], right_sum=max(0,soma_analisada));
            }
        }
    }
    //tentar ver agora onde as matrizes ficam com a maior soma, fazendo divisões verticais e horizontais.
    int maxima_area=0;
    for(i=1;i<200;i++){//faznendo as somas para descobrir a melhor matriz até determinado i.
        top_best[i]=max(top_best[i],top_best[i-1]);
        left_best[i]=max(left_best[i],left_best[i-1]);
    }
    for(i=199-1;i>=0;i--){
        bottom_best[i]=max(bottom_best[i],bottom_best[i+1]);
        right_best[i]=max(right_best[i],right_best[i+1]);
    }
    for(i=0;i<200;i++){
        maxima_area=max(maxima_area,top_best[i]+bottom_best[i]);
        maxima_area=max(maxima_area,left_best[i]+right_best[i]);
    }
    cout<<area+maxima_area;
    return 0;
}

