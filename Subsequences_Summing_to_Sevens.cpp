#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

long long prefix[50001];
int posicao[8];//esse vetor será preenchido quando percorrermos o vetor soma, e serão adicionados em cada posição o primeiro número que tiver o respectivo resto. Por exemplo: soma=6, resto 6. posicao[6]=6.

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int i,n,avaliar,intermax;
    long long sum=0,x;
    cin>>n;
    prefix[0]=0;
    for(i=0;i<n;i++){
        cin>>x;
        sum+=x;
        prefix[i+1]=sum;
        if(posicao[sum%7]==0&&sum%7!=0){
            posicao[sum%7]=i+1;
        }
    }
    intermax=0;
    for(i=n;i>0;i--){
        avaliar=i-posicao[prefix[i]%7];
        intermax=max(intermax,avaliar);
    }
    cout<<intermax;
    return 0;
}

