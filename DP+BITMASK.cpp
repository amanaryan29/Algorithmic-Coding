#include<bits/stdc++.h>
using namespace std;
int count1=0;
int dp1[5000][105];
int dp[505][505];
int c;
vector<int> start,dest;
int rec(int mask,int prev)
{
//cout<<mask<<" "<<prev<<" "<<count1<<"\n";
if(mask==((1<<count1)-1))
return dp[prev][c];
if(dp1[mask][prev]!=-1)
return dp1[mask][prev];
int s=INT_MAX;
for(int i=0;i<count1;i++)
{
if((mask&(1<<i))==0)
{
s=min(s,(rec(mask|(1<<i),dest[i])+dp[prev][start[i]]+dp[start[i]][dest[i]]));
}

}
//return s;
return dp1[mask][prev]=s;
}
int main()
{
int t;
cin>>t;
while(t--)
{
start.clear();
dest.clear();
  int n,m;
  cin>>n>>m>>c;
  memset(dp,10005,sizeof(dp));
  memset(dp1,-1,sizeof(dp1));
    for(int i=0;i<m;i++)
    {
    int u,v,cost;
    cin>>u>>v>>cost;
    dp[u][v]=min(dp[u][v],cost);
    dp[v][u]=min(dp[v][u],cost);
    }
     for(int k=1;k<=n;k++)
 {
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        if(i==j)
        dp[i][j]=0;
        //if(dp[i][k]<10005 && dp[k][j]<10005)
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        }
     }

 }
 /*for(int i=1;i<=n;i++)
 {
 for(int j=1;j<=n;j++)
 {
 cout<<dp[i][j]<<" ";
 }
 cout<<"\n";

 }*/
    int numb;
    cin>>numb;
    count1=0;
    for(int i=0;i<numb;i++)
    {
    int st,en,no;
    cin>>st>>en>>no;
    //cout<<st<<" "<<en<<" "<<no<<" "<<numb<<"\n";
    count1+=no;
    for(int j=0;j<no;j++)
    {
    start.push_back(st);
    dest.push_back(en);
    }
    }
//cout<<"HELLO";
cout<<rec(0,c)<<"\n";
}

}
