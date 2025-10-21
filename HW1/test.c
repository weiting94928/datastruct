#include <stdio.h>

#define MAXA 1000000
static int cnt[MAXA+5];
static int pref[MAXA+5];

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int maxa=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
        if(x>maxa) maxa=x;
    }
    for(int v=1;v<=maxa;v++){
        pref[v]=pref[v-1]+cnt[v];
    }
    long long ans=0;
    for(int g=k;g<=maxa;g++){
        long long sum=0;
        int tmax=maxa/g;
        for(int t=1;t<=tmax;t++){
            int L=t*g;
            int R=L+g-1;
            if(R>maxa) R=maxa;
            int c=pref[R]-pref[L-1];
            if(c) sum+=1ll*c*t*g;
        }
        if(sum>ans) ans=sum;
    }
    printf("%lld\n",ans);
    return 0;
}
