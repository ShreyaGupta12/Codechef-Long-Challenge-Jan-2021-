#include <bits/stdc++.h>
using namespace std;
#define sfor(i,azz,bzz) for (long long i = (azz); i <= (bzz); ++i)
#define input(azz,szz,ezz) sfor(pzz,szz,ezz) cin>>azz[pzz]

bool ans(long long c){
	    long long n, q, k;
	    cin>>n>>q>>k;
	    long long ans[n][n];
	long long r;
	memset(ans,-1,sizeof(ans));
	cout<<1<<" "<<1<<" "<<1<<endl;
	cout.flush();
	cin>>r;
	if(r==-1) return false;
	if(r<k)
	{
		ans[0][0]=1;
		ans[0][1]=1;
		ans[1][0]=1;
		ans[1][1]=0;
	}
	else if(r>k)
	{
		ans[0][0]=0;
		ans[0][1]=1;
		ans[1][0]=1;
		ans[1][1]=0;
	}
	else
	{
		bool flag=false;
		long long ri=0,ci=1;
		sfor(i,0,3)
		{
			long long rj=0,cj=2;
			vector<int> v1;
		
			sfor(j,0,2)
			{
				k=r;
				cout<<1<<" "<<(rj%2)+1<<" "<<cj<<endl;
				cout.flush();
				cin>>r;
				if(r==-1) return false;
				if(r>k)
				{
					if(n==2)
					{
						flag=true;
						ans[0][0]=0;
						ans[0][1]=1;
						ans[1][0]=1;
						ans[1][1]=0;
						break;
					}
					k=r;
					cout<<1<<" "<<1<<" "<<1<<endl;
					cout.flush();
					cin>>r;
					if(r==-1) return false;
					if(r<k)
					{
						flag=true;
						ans[0][0]=1;
						ans[0][1]=1;
						ans[1][0]=1;
						ans[1][1]=0;
						break;
					}
					k=r;
					cout<<1<<" "<<1<<" "<<1<<endl;
					cout.flush();
					cin>>r;
					if(r==-1) return false;
				}
				rj++;
			}
				if(flag) break;
				ri++;
				k=r;
				cout<<1<<" "<<(ri%2)+1<<" "<<ci<<endl;
				cout.flush();
				cin>>r;
				if(r==-1) return false;
				if(r>k)
				{
					if(n==2)
					{
						flag=true;
						ans[0][0]=0;
						ans[0][1]=1;
						ans[1][0]=1;
						ans[1][1]=0;
						break;
					}
					k=r;
					cout<<1<<" "<<1<<" "<<1<<endl;
					cout.flush();
					cin>>r;
					if(r==-1) return false;
					if(r<k)
					{
						flag=true;
						ans[0][0]=1;
						ans[0][1]=1;
						ans[1][0]=1;
						ans[1][1]=0;
						break;
					}
					k=r;
					cout<<1<<" "<<1<<" "<<1<<endl;
					cout.flush();
					cin>>r;
					if(r==-1) return false;
				}
		}
	}
	set<int>s1;
	sfor(i,2,n-1)
	{
	    if(ans[i-1][0]!=0)
       {
			k=r;
			cout<<1<<" "<<i<<" "<<1<<endl;
			cout.flush();
			cin>>r;
			if(r==-1) return false;
			ans[i-1][0]^=1;
			if(r>k)
			{
				ans[i][0]=1;
				ans[i][1]=0;
			}
       }
       if(ans[i-1][1]!=1)
       {
           k=r;
			cout<<1<<" "<<i<<" "<<2<<endl;
			cout.flush();
			cin>>r;
			if(r==-1) return false;
			ans[i-1][1]^=1;
			if(r>k)
			{
				ans[i][0]=1;
				ans[i][1]=0;
			}
       }
       if(ans[i][0]!=-1) continue;
			long long cj=0;
			sfor(j,0,3)
			{
				k=r;
				cout<<1<<" "<<i+1<<" "<<(cj%2)+1<<endl;
				cout.flush();
				cin>>r;
				if(r==-1) return false;
				if(r>k)
				{
					k=r;
					cout<<1<<" "<<i<<" "<<1<<endl;
					cout.flush();
					cin>>r;
					ans[i-1][0]^=1;
					if(r==-1) return false;
					if(r<k)
					{
						ans[i][0]=1;
						ans[i][1]=0;
						break;
					}
					k=r;
					cout<<1<<" "<<i<<" "<<1<<endl;
					cout.flush();
					cin>>r;
					ans[i-1][0]^=1;
					if(r==-1) return false;
				}
				cj++;
			}
	}
	map<int, int> mp1;
	sfor(i,2,n-1)
	{
        if(ans[0][i-1]!=0)
        {
			k=r;
			cout<<1<<" "<<1<<" "<<i<<endl;
			cout.flush();
			cin>>r;
			if(r==-1) return false;
			ans[0][i-1]^=1;
			if(r>k)
			{
				ans[0][i]=1;
				ans[1][i]=0;
			}
        }
        if(ans[1][i-1]!=1)
        {
            k=r;
			cout<<1<<" "<<2<<" "<<i<<endl;
			cout.flush();
			cin>>r;
			if(r==-1) return false;
			ans[1][i-1]^=1;
			if(r>k)
			{
				ans[0][i]=1;
				ans[1][i]=0;
			}			
        }
        if(ans[0][i]!=-1) continue;
			long long rj=0;
			sfor(j,0,3)
			{
				k=r;
				cout<<1<<" "<<(rj%2)+1<<" "<<i+1<<endl;
				cout.flush();
				cin>>r;
				if(r==-1) return false;
				if(r>k)
				{
				    k=r;
					cout<<1<<" "<<1<<" "<<i<<endl;
					cout.flush();
					cin>>r;
					ans[0][i-1]^=1;
					if(r==-1) return false;
					if(r<k)
					{
						ans[0][i]=1;
						ans[1][i]=0;
						break;
					}
					k=r;
					cout<<1<<" "<<1<<" "<<i<<endl;
					cout.flush();
					cin>>r;
					if(r==-1) return false;
					ans[0][i-1]^=1;
				}
				rj++;
			}
	}
	vector<int> v25;
	sfor(i,2,n-1)
	{
		sfor(j,2,n-1)
		{
			if(ans[i-1][j-1]!=0)
			{
				k=r;
					cout<<1<<" "<<i<<" "<<j<<endl;
					cout.flush();
					cin>>r;
					if(r==-1) return false;
					ans[i-1][j-1]^=1;
			}
			if(ans[i-1][j]!=1)
			{
				k=r;
				cout<<1<<" "<<i<<" "<<j+1<<endl;
					cout.flush();
					cin>>r;
					if(r==-1) return false;
					ans[i-1][j]^=1;
			}
			if(ans[i][j-1]!=1)
			{
				k=r;
				cout<<1<<" "<<i+1<<" "<<j<<endl;
					cout.flush();
					cin>>r;
					if(r==-1) return false;
					ans[i][j-1]^=1;
			}
			
			k=r;
			cout<<1<<" "<<i+1<<" "<<j+1<<endl;
			cout.flush();
			cin>>r;
			if(r==-1) return false;
			if(r>k)
			{
				ans[i][j]=0;
			}
			else
			{
				ans[i][j]=1;
			}
		}
	}
	cout<<2<<endl;
	sfor(i,0,n-1)
	{
		sfor(j,0,n-1)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	cout.flush();
	cin>>r;
	if(r==-1) return false;
	return true;
}

int main() {
	long long t;
	cin>>t;
	sfor(i,1,t)
        if(!ans(i)) break;
	return 0;
}
