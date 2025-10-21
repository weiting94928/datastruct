#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXA 1000000

long long best[ MAXA+5 ];  // 存g的總和

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int maxa=0;
    int* a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>maxa) maxa=a[i];
    }

    for(int i=0;i<n;i++){
        int x=a[i];
        for(int d=1;d*d<=x;d++){
            if(x%d==0){
                int g1=d;
                int g2=x/d;
                best[g1]+=1ll*(x/g1)*g1;
                if(g1!=g2) best[g2]+=1ll*(x/g2)*g2;
            }
        }
    }

    long long ans=0;
    for(int g=k;g<=maxa;g++){
        if(best[g]>ans) ans=best[g];
    }
    printf("%lld\n",ans);
    free(a);
    return 0;
}
