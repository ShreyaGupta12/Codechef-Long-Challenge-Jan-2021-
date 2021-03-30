#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int count(string s)
{
    int ct=0;
    for (int i = 0; i < 4; i++)
    {
        if(s[i]=='1')
        {
            ct+=(1<<(3-i));
        }
    }
    return ct;
}
int main()
{
    int t;cin >>t;
    while(t--)
    {
        int n;cin >>n;
        string s1,s2;cin >>s1;
        for (int i = 0; i < n; i+=4)
        {
            string s3;s3+=s1[i];s3+=s1[i+1];s3+=s1[i+2];s3+=s1[i+3];
            int x=count(s3)+1;
            s2+=char(96+x);
        }
        cout<<s2<<endl;
    }
    return 0;
}
