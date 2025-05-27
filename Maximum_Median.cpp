#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//int mat[2001][5][8002];
ll arr[200001];

int main(){
    int n,i,dir,flag=0;
    ll k,meio,soma=0;
    cin>>n>>k;
    for(i=0;i<n;i++){cin>>arr[i];}
    sort(arr,arr+n);
    meio=n/2;
    dir=meio+1;
    int novo=meio;
    while(flag==0&&n!=1){
        flag=1;
        if(soma+((ll)(dir-(meio)))*(arr[dir]-arr[novo])<=k){
            soma+=((ll)(dir-(meio)))*(arr[dir]-arr[novo]);
            flag=0;
            novo=dir;
        }
        if(flag==1||dir>=n-1){
            break;
        }
        if(dir<n-1&&arr[dir]==arr[dir+1]){
            while(dir<n-1&&arr[dir]==arr[dir+1]){
                dir++;
            }
        }
        dir++;
        if(dir==n){
            dir--;
        }
    }
    if(novo==dir) dir++;

    cout<<(k-soma)/(dir-meio)+arr[novo];
    return 0;
}

/*int n,i,Q,q;
    cin>>n;
    vector<int> arr(n);
    for(i=0;i<n;i++){cin>>arr[i];}
    sort(arr.begin(),arr.end());
    vector<int>::iterator low,up;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(i=0;i<n;i++){
        for(q=0;q<=8000;q++){
            low=lower_bound(arr.begin(),arr.begin()+i+1,q-4000);
            up=upper_bound(arr.begin(),arr.begin()+i+1,q-4000);
            mat[i][1][q]=up-low;
            if(q==4004){
                cout<<mat[i][1][q]<<" "<<i<<endl;
            }
        }
    }
    for(q=3990;q<=4030;q++){
        for(i=0;i<n-1;i++){
            mat[i+1][2][q]=mat[i][2][q];
            if(q-arr[i+1]-4000>=0)
                mat[i+1][2][q]+=mat[i][1][q-arr[i+1]-4000];
            cout<<mat[i+1][2][q]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<mat[7][2][4008]<<endl;
    for(q=3990;q<=4030;q++){
        for(i=0;i<n-1;i++){
            mat[i+1][3][q]=mat[i][3][q];
            if(q-arr[i+1]-4000>=0)
                mat[i+1][3][q]+=mat[i][2][q-arr[i+1]-4000];
            cout<<mat[i+1][3][q]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(q=3990;q<=4030;q++){
        for(i=0;i<n-1;i++){
            mat[i+1][4][q]=mat[i][4][q];
            if(q-arr[i+1]-4000>=0)
                mat[i+1][4][q]+=mat[i][3][q-arr[i+1]-4000];
            cout<<mat[i+1][4][q]<<" ";
        }
        cout<<endl;
    }
    int num;
    cin>>Q;
    for(i=0;i<Q;i++){
        cin>>num;
        cout<<mat[n-1][4][num+4000];
    }*/
