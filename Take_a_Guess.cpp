#include <bits/stdc++.h>

using namespace std;

int operand[4];
int operor[4];
int soma[4];

int main(){
    //freopen("planting.in", "r", stdin);
    //freopen("planting.out", "w", stdout);
    int n,k;
    scanf("%d %d", &n, &k);
    vector<int> valores(n+1);
    for(int i=1;i<=2;i++){
        for(int j=i+1;j<=3;j++){
            printf("and %d %d\n", i, j);
            fflush(stdout);
            int num=(i+j);
            if(num==5) num++;
            scanf("%d", &operand[num/2]);
            printf("or %d %d\n", i, j);
            fflush(stdout);
            scanf("%d", &operor[num/2]);
        }
    }
    for(int i=1;i<=3;i++) soma[i] = ((~operand[i])&operor[i])+2*operand[i];
    int primeiro=(soma[1]+soma[2]-soma[3])/2;
    valores[1]=primeiro;
    valores[2]=((soma[1]+soma[3]-soma[2])/2);
    valores[3]=((soma[2]+soma[3]-soma[1])/2);
    for(int i=4;i<=n;i++){
        int andbit,orbit;
        printf("and 1 %d\n", i);
        fflush(stdout);
        scanf("%d", &andbit);
        printf("or 1 %d\n", i);
        fflush(stdout);
        scanf("%d", &orbit);
        int soma=((~andbit)&orbit)+2*andbit;
        valores[i]=(soma-primeiro);
    }
    sort(valores.begin()+1,valores.end());
    printf("finish %d", valores[k]);
    return 0;
}
