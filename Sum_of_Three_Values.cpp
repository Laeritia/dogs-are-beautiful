#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x,i,y,flag=0,esq,dir;
    cin>>n>>x;
    vector <pair<int,int>> arr(n);
    for(i=0;i<n;i++){
        cin>>y;
        arr[i].first=y;
        arr[i].second=i;
    }
    sort(arr.begin(),arr.end());
    for(i=1;i<n-1;i++){
        esq=0;
        dir=n-1;
        if(arr[i].first>x){
            continue;
        }
        int valor=x-arr[i].first;
        while(esq<dir&&dir!=i&&esq!=i){
            if(arr[esq].first+arr[dir].first==valor){
                flag=1;
                cout<<arr[esq].second+1<<" "<<arr[i].second+1<<" "<<arr[dir].second+1;
                break;
            }
            if(arr[esq].first+arr[dir].first<valor){
                esq++;
            }
            if(arr[esq].first+arr[dir].first>valor){
                dir--;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(flag==0){
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
