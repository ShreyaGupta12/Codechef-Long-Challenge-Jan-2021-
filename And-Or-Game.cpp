#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n,m,rda[(1<<20)+10],rdb[(1<<20)+10],a[1<<20],b[1<<20];
int mx,lg,ans;
ll f[1<<20],g[1<<20],A[1<<20],B[1<<20];
void FWT_or(ll *a,int op) {
	for (int i=1;i<(1<<lg);i<<=1)
	for (int j=0;j<(1<<lg);j+=(i<<1))
	for (int k=0;k<i;k++)
		a[i+j+k]+=op*a[j+k];
}
void FWT_and(ll *a,int op) {
	for (int i=1;i<(1<<lg);i<<=1)
	for (int j=0;j<(1<<lg);j+=(i<<1))
	for (int k=0;k<i;k++)
		a[j+k]+=op*a[i+j+k];
}
int con;
int main() {
	//freopen("1.txt","r",stdin);
	int T; read(T);
	while (T--) {
		read(n),read(m); int x,y; mx=0;
		for (int i=1;i<=n;i++) read(x),rda[i]=x,mx=max(mx,x),a[x]++;
		for (int i=1;i<=m;i++) read(x),rdb[i]=x,mx=max(mx,x),b[x]++;
		a[0]=b[0]=0;
		while ((1<<lg)-1<mx) lg++;
		for (int i=0;i<lg;i++)
		for (int j=(1<<i);j<(1<<lg);j++)
			if (j>>i&1) a[j]+=a[j^(1<<i)];
		for (int i=0;i<lg;i++)
		for (int j=(1<<lg)-1;j>=(1<<i);j--)
			if (j>>i&1) b[j^(1<<i)]+=b[j];
		//for (int i=0;i<(1<<lg);i++) printf("%d %d %d\n",i,a[i],b[i]);
		for (int i=0;i<(1<<lg);i++) {
			if (b[i]>0) {
				B[i]=1;
				for (int j=0;j<lg;j++)
					if (!(i>>j&1)) {
						if (b[i^(1<<j)]==b[i]) B[i]=0;
					}
			}
			if (a[i]>0) {
				A[i]=1;
				for (int j=0;j<lg;j++)
					if (i>>j&1) {
						if (a[i^(1<<j)]==a[i]) A[i]=0;
					}
			}
			A[0]=1,B[(1<<lg)-1]=1;
			//if (A[i]) printf("OR %d\n",i);
			//if (B[i]) printf("AND %d\n",i);
			f[i]=A[i];
		}
		FWT_or(A,1);
		FWT_and(B,1);
		int lst=0; con=0;
		for (int op=0;op<=lg*2;op++) {
			ans=0;
			if (op&1^1) {
				FWT_and(f,1);
				for (int i=0;i<(1<<lg);i++) f[i]*=B[i];
				FWT_and(f,-1);
				for (int i=0;i<(1<<lg);i++) f[i]=(f[i]>0),ans+=f[i];
			} else {
				FWT_or(f,1);
				for (int i=0;i<(1<<lg);i++) f[i]*=A[i];
				FWT_or(f,-1);
				for (int i=0;i<(1<<lg);i++) f[i]=(f[i]>0),ans+=f[i];
			}
			//for (int i=0;i<(1<<lg);i++) if (f[i]) printf("%d ",i); printf("\n");
			if (ans==lst) con++;
			lst=ans;
			if (con>2) break;
		}
		printf("%d\n",ans);
		
		for (int i=0;i<(1<<lg);i++) a[i]=b[i]=A[i]=B[i]=0;
		//exit(0);
	}
	return 0;
}
