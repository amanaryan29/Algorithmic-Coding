#include<bits/stdc++.h>
#define mod 100000

using namespace std;
long long f[2000005];
long long mat(long long a[2][2],long long b[2][2])
{
long long c=((((a[0][0])*(b[0][0])))+(((a[0][1])*(b[1][0]))))%mod;
long long d=((((a[0][0])*(b[0][1])))+(((a[0][1])*(b[1][1]))))%mod;
long long e=((((a[1][0])*(b[0][0])))+(((a[1][1])*(b[1][0]))))%mod;
long long f=((((a[1][0])*(b[0][1])))+(((a[1][1])*(b[1][1]))))%mod;
a[0][0]=c;
a[0][1]=d;
a[1][0]=e;
a[1][1]=f;
}
void rec(long long n,long long a[2][2])
{
long long b[2][2]={{1,1},{1,0}};
if(n==0 || n==1)
return;
rec(n/2,a);
mat(a,a);
if((n%2)!=0)
mat(a,b);
}
int  main()
{
ios_base::sync_with_stdio(false);
cin.tie(false);
long long t;
cin>>t;
long long k=1;
while(t--)
{
priority_queue<long ,vector<long > , greater<long> > q;
long long a1,b1;
cin>>a1>>b1;
map<long long,long long> m;
cout<<"Case "<<k<<": ";
k++;

long long a[2][2]={{1,1},{1,0}};
if(a1==1)
{
f[1]=0;
f[2]=1;
q.push(0);
q.push(1);
for(long long i=3;i<=(1+b1);i++)
{
f[i]=(f[i-1]+f[i-2])%mod;
q.push(f[i]);
}

long long count1=0;
while(1)
{

count1++;
cout<<q.top()<<" ";
q.pop();
if(count1==100 || q.empty())
break;
}

}
else if(a1==2)
{
f[1]=1;
f[2]=1;
q.push(1);
q.push(1);
for(long long i=3;i<=(1+b1);i++)
{
f[i]=(f[i-1]+f[i-2])%mod;
q.push(f[i]);

}
//cout<<"\n";
long long count1=0;
while(1)
{

count1++;
cout<<q.top()<<" ";
q.pop();
if(count1==100 || q.empty())
break;
}

}
else
{
rec(a1-1,a);
f[2]=(a[0][0])%mod;
f[1]=(a[1][0])%mod;
//cout<<f[1]<<endl;
q.push(f[1]);
q.push(f[2]);
for(long long i=3;i<=b1+1;i++)
{
f[i]=(f[i-1]+f[i-2])%mod;
q.push(f[i]);
//cout<<f[i]<<" ";
}
//cout<<"\n";
long long count1=0;
while(1)
{

count1++;
cout<<q.top()<<" ";
q.pop();
if(count1==100 || q.empty())
break;
}

}
cout<<"\n";
}

}

