#include <bits/stdc++.h>

using namespace std;
int succ[200000][20];

int main(){
    int n,q;
    cin>>n>>q;

    succ[1][0] = -1;
    for(int i = 2; i <= n; i++){
        cin >> succ[i][0];
    }
    for(int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            if(succ[j][i-1] == -1) succ[j][i] = -1;
            else succ[j][i] = succ[succ[j][i-1]][i-1];
        }
    }//terminamos de preprocessar
    for (int t = 0; t < q; t++){
        int x,k;
        cin >> x >> k;

        int param=0;
        while (k >= (1<<param)){
            if(k & (1<<param)) x = succ[x][param];
            if(x==-1) break;
            param++;
        }
        cout<<x<<endl;
    }
    return 0;
}
