#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("planting.in", "r", stdin);
    //freopen("planting.out", "w", stdout);
    int numgrupo=0;
    while(numgrupo!=2){
        string nimporta;
        printf("next 0 1\n");
        fflush(stdout);
        scanf("%d",&numgrupo);
        for(int i=0;i<numgrupo;i++){
            cin>>nimporta;
        }
        printf("next 0\n");
        fflush(stdout);
        scanf("%d",&numgrupo);
        for(int i=0;i<numgrupo;i++){
            cin>>nimporta;
        }
    }
    while(numgrupo!=1){
        string nimporta;
        printf("next 0 1 2 3 4 5 6 7 8 9\n");
        fflush(stdout);
        scanf("%d",&numgrupo);
        for(int i=0;i<numgrupo;i++){
            cin>>nimporta;
        }
    }
    printf("done");
    fflush(stdout);
    return 0;
}
