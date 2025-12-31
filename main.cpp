#include<bits/stdc++.h>
#include<windows.h>
#pragma GCC optimize(2)
#define LL long long
using namespace std;
const int maxn=1005;
int n;
LL a[maxn],p[maxn];
LL calc(){
	LL ret=p[1]*a[p[n]]*a[p[1]]*a[p[2]]+p[n]*a[p[n-1]]*a[p[n]]*a[p[1]];
	for(int i=2;i<n;i++){
		ret+=p[i]*a[p[i-1]]*a[p[i]]*a[p[i+1]];
	}
	return ret;
}
LL del(int x){
	LL ret=0;
	int l=x-1,r=x+1;
	ret+=p[x]*a[p[l]]*a[p[x]]*a[p[r]];
	ret+=p[l]*a[p[l-1]]*a[p[l]]*a[p[x]];
	ret+=p[r]*a[p[x]]*a[p[r]]*a[p[r+1]];
	return ret;
}
int id[maxn];
LL ans,now;
int P[maxn];
void cpy(){
	cerr<<ans<<endl;
	for(int i=1;i<=n;i++) P[i]=p[i];
	if(ans>145302138855600ll){
		freopen("10.txt","w",stdout);
		for(int k=1;k<=n;k++) printf("%d ",P[k]);
		exit(0);
	}
}
void work(){
	bool flg;
	do{
		flg=0;
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			int x=id[i],y=id[j];
			LL nxt;
			if(abs(x-y)<=3||abs(x-y)>=n-2){
				swap(p[x],p[y]);
				nxt=calc();
			}else{
				nxt=now-del(x)-del(y);
				swap(p[x],p[y]);
				nxt+=del(x)+del(y);
			}
			if(nxt>ans){
				ans=now=nxt;
				cpy();
				flg=1;
			}else if(nxt>now) now=nxt,flg=1;
			else swap(p[x],p[y]);
		}
	}while(flg);
}
int main(){
	freopen("10.in","r",stdin);
	srand(GetTickCount());
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),p[i]=id[i]=i;
	random_shuffle(p+1,p+1+n);
	while(1){
		for(int i=1;i<=20;i++){
			int x=rand()%n+1,y=rand()%n+1;
			swap(p[x],p[y]);
		}
		now=calc();
		if(now>ans){
			ans=now;
			cpy();
		}
		random_shuffle(id+1,id+1+n);
		work();
	}
	return 0;
}
