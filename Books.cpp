#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int livros_temp[100002];
int esq=1,dir=1;
int soma;
int t,n;
int max_books=0;

void sum_subarray (void){
    while(dir+1<n+1&&soma+livros_temp[dir+1]<=t){
        dir++;
        soma+=livros_temp[dir];
    }
    max_books=max(max_books,dir-esq+1);
    return;
}

int main(){
    int i,flag=0;
    cin>>n>>t;
    for(i=1;i<=n;i++){
        cin>>livros_temp[i];
        if(livros_temp[i]<=t){
            flag=1;
        }
    }
    if(n==1){
        if(livros_temp[1]<=t){
            cout<<n;
        } else{
            cout<<0;
        }
    } else{
        soma=livros_temp[1];
        while(dir<n){
            sum_subarray();
            soma-=livros_temp[esq];
            esq++;
        }
        if(flag==0){
            cout<<0;
        } else{
            cout<<max_books;
        }
    }
    return 0;
}
