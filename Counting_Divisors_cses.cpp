#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    for (int i = 0; i < n; i++){
        int x;
        int guarda;
        cin>>x;
        guarda=x;
        vector<int> factors;
        for(int j = 2; j*j <= x; j++){
            while(x%j==0){
                factors.push_back(j);
                x /= j;
            }
        }
        if(x>1) factors.push_back(x);
        int res=1;
        int param;
        if(guarda!=1) param=factors[0];
        int ind=0;
        while(ind<(int)factors.size()){
            int cont=0;
            while(ind<(int)factors.size()&&factors[ind]==param){
                cont++;
                ind++;
            }
            res *= (cont+1);
            if(ind != (int)factors.size()) param = factors[ind];
        }
        if(guarda==1) res=1;
        cout<<res<<endl;
    }
    return 0;
}
