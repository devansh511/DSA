#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],ans=INT_MAX,n;
inline int calc(int x,int y){
	if(x<y)swap(x,y);
	ri d=x-y;
	if(d<<1>x)return x+1>>1;
	else return d+(y-d+1<<1)/3;
}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<n;++i)ckmin(ans,calc(a[i],a[i+1]));
	for(ri i=1;i+2<=n;++i)ckmin(ans,a[i]+a[i+2]+1>>1);
	sort(a+1,a+n+1);
	ckmin(ans,(a[1]+1>>1)+(a[2]+1>>1));
	printf("%d",ans);
	return 0;
}