#include <stdio.h>

#define MAXA 1000000
#define MAXK 1000
static int cnt[MAXA+5];

int main(){
    int n,k;
    long long sum=0;
    scanf("%d %d",&n,&k);
    int maxa=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        sum+=x;
        cnt[x]++;
        if(x>maxa) maxa=x;
    }

    long long ans=0;
    for(int g=k;g<=MAXK;g++){
        long long modsum=0;
        for(int v=1;v<=maxa;v++){
            if(cnt[v]) modsum+=1ll*cnt[v]*(v%g);
        }
        long long usable=sum-modsum;
        if(usable>ans) ans=usable;
    }
    printf("%lld\n",ans);
    return 0;
}
