#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",_LINE,FUNCTION_)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=100005;
const int MOD=1000000007;
ll KSM(ll a,ll b){ll res=1;while(b){if(b&1)res=res*a%MOD;a=a*a%MOD,b>>=1;}return res;}
int mod;
struct FastMod{
	typedef __uint128_t LLL;
	ull b,m;
	void init(ull b){this->b=b,m=ull((LLL(1)<<64)/b);}
	inline ull operator()(ull a){
		ull r=a-(ull)((LLL(m)*a)>>64)*b;
		return r>=b?r-b:r;
	}
}M;
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=M(res*a);a=M(a*a),b>>=1;}return res;}
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
int fa[N],d[N];
pi find(int x)
{
	int val=1;
	while(x!=fa[x]) val=M(1LL*val*d[x]),x=fa[x];
	return {x,val};
}
int id[N],_[N],cnt,siz[N];
bool flag=true;
std::vector<std::pair<int*,int>> st;
bool merge(int x,int y,int v)
{
	pi a=find(x),b=find(y);
	if(a.first==b.first) return flag&=(int)M(1LL*a.second*ksm(b.second))==v,false;
	if(siz[a.first]>siz[b.first]) v=ksm(v),std::swap(a,b);
	st.pb({fa+a.first,fa[a.first]}),st.pb({siz+b.first,siz[b.first]});
	fa[a.first]=b.first,siz[b.first]+=siz[a.first],d[a.first]=M(M(1LL*v*b.second)*ksm(a.second));
	return true;
}
int vis[N];
int FA[N],SIZ[N];
int FIND(int x){while(x!=FA[x])x=FA[x];return x;}
bool MERGE(int x,int y)
{
	x=FIND(x),y=FIND(y);
	if(x==y) return false;
	if(SIZ[x]>SIZ[y]) std::swap(x,y);
	st.pb({FA+x,FA[x]}),st.pb({SIZ+y,SIZ[y]});
	FA[x]=y,SIZ[y]+=SIZ[x];
	return true;
}
void add(int x,int y,int v)
{
	bool tag=false;
	if(!id[x]) id[x]=y,_[x]=ksm(v),tag=1,st.pb({id+x,0});
	else if(merge(id[x],y,M(1LL*v*_[x]))) tag=1;
	
	if(!vis[y]) tag=1,vis[y]=x,tag=1,st.pb({vis+y,0});
	else if(MERGE(vis[y],x)) tag=1;
	if(tag) --cnt;
}
inline void reset()
{
	*st.back().first=st.back().second;
	st.pop_back();
}
struct node{
	int x,y,v;
	inline bool operator < (const node &o)const
	{
		return x==o.x?y<o.y:x<o.x;
	}
};
std::vector<node> v[N<<2];
void upd(int L,int R,int l,int r,int cur,const node &o)
{
	if(L<=l&&r<=R) return v[cur].pb(o),void();
	int mid=(l+r)>>1;
	if(L<=mid) upd(L,R,l,mid,ls(cur),o);
	if(R>mid) upd(L,R,mid+1,r,rs(cur),o);
}
int ans[N];
void ask(int l,int r,int cur)
{
	int last_flag=flag,SIZ=SZ(st),LC=cnt;
	for(auto it:v[cur]) add(it.x,it.y,it.v);
	if(l==r)
	{
		if(flag) ans[l]=KSM(mod-1,cnt);
		else ans[l]=0;
		flag=last_flag,cnt=LC;
		while(SZ(st)>SIZ) reset();
		return;
	}
	int mid=(l+r)>>1;
	ask(l,mid,ls(cur)),ask(mid+1,r,rs(cur));
	flag=last_flag,cnt=LC;
	while(SZ(st)>SIZ) reset();
}
std::map<node,int> mp;
int main()
{
	int n,q;read(n,q,mod);cnt=n+n-1;M.init(mod);
	int x,y,v;
	for(int i=1;i<=n;++i) fa[i]=FA[i]=i,siz[i]=SIZ[i]=1;
	for(int i=1;i<=q;++i)
	{
		read(x,y,v);
		auto it=mp.find({x,y,v});
		if(it==mp.end()) mp[{x,y,v}]=i;
		else upd(it->second,i-1,1,q,1,it->first),mp.erase(it);
	}
	for(auto it:mp) upd(it.second,q,1,q,1,it.first);
	ask(1,q,1);
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}
