#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long int n,k,x,y;
	    cin>>n>>k>>x>>y;
	    if(x==y)
	    {
	        x=n;
	        y=n;
	        //cout<<"if";
	    }
	    else
	    {
	        if(y<x)
	        {
	            long int a=x-y;
	            if(k%4==1)
	            {
	                y=y+(n-x);
	                x=n;
	            }
	            else if(k%4==2)
	            {
	                y=y+(n-x);
	                x=n;
	                long int temp=x;
	                x=y;
	                y=temp;
	            }
	            else if(k%4==3)
	            {
	                x=0;
	                y=a;
	            }
	            else if(k%4==0)
	            {
	                x=a;
	                y=0;
	            }
	        }
	        else
	        {
	            long int a=y-x;
	            if(k%4==1)
	            {
	                x=x+(n-y);
	                y=n;
	            }
	            else if(k%4==2)
	            {
	                x=x+(n-y);
	                y=n;
	                long int temp=x;
	                x=y;
	                y=temp;
	            }
	            else if(k%4==3)
	            {
	                y=0;
	                x=a;
	            }
	            else if(k%4==0)
	            {
	                y=a;
	                x=0;
	            }
	        }
	    }
	    cout<<x<<" "<<y<<endl;
	}
	return 0;
}
