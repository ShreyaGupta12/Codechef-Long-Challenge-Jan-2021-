#include<bits/stdc++.h>
using namespace std;
int main(){
    long long T;
    cin>>T;
    while(T--){
    long long hit,k,d;
    cin>>hit>>k>>d;
    int arr[hit],sum=0;
    for(int i=0;i<hit;i++){
        cin>>arr[i];
          sum=sum+arr[i];
    }
    int noC;
    noC=sum/k;
   if(noC>d)
   cout<<d<<endl;
   else
   cout<<noC<<endl;
    }
    return 0;
}
