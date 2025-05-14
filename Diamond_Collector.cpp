#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int arr[50002];
int max_num_leftmosti[50002];//o numero de diamantes que podem ser colocados juntos a partir do diamante i.
int max_inter_maiorig[50002];//maximo intervalo de numeros depois e a partir do i. Ou seja, quando x>=i.

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n,k,i,dir=0;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    dir=0;
    for(i=0;i<n;i++){
        while(dir<n-1&&arr[dir+1]-arr[i]<=k){
            dir++;
        }
        max_num_leftmosti[i]=dir-i+1;
    }
    for(i=n-1;i>=0;i--){
        max_inter_maiorig[i]=max(max_inter_maiorig[i+1], max_num_leftmosti[i]);
    }
    int ans=0;
    for(i=0;i<n;i++){//para cada i, primeiro pegamos o maior intervalo que tem o elemento i mais à esquerda. Em seguida, somamos com o maior intervalo que não é pego por esse q acabamos de somar. Por isso adicionamos o tamanho do intervalo no indice do outro elemento.
        ans=max(ans,max_num_leftmosti[i]+max_inter_maiorig[i+max_num_leftmosti[i]]);
    }
    cout<<ans;
    return 0;
}
