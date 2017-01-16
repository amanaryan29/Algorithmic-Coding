/*Subham Sanghai*/
#include<bits/stdc++.h>
#define MAX1 (1<<15)
using namespace std;
int bar[20];
int count1=0;
pair<int,int>  dp[16][16][MAX1];
int n;
int ans1;
pair<int,int> rec(int i,int prev,int mask)
{
	if(i==(n+1))
		return make_pair(bar[prev],1);
	if(dp[i][prev][mask].first!=-1)
		return dp[i][prev][mask];
	int ans=0;
	int ct=0;
	for(int j=1;j<=n;j++)
	{
		if((mask&(1<<(j-1)))==0)
		{
			pair<int,int> p=(rec(i+1,j,(mask|(1<<(j-1)))));
			if((p.first+abs(bar[j]-bar[prev]))>ans)   // If the value is larger in one branch, then update the ans as the new value and the count as the new count
			{
			   ans=p.first+abs(bar[j]-bar[prev]); //if value of both the branches are same then just update the count as the sum of counts of the two branches
			   ct=p.second;
			}
			else if((p.first+abs(bar[j]-bar[prev]))==ans)
			{
			   ct+=p.second;
			}
		}
	}
	//cout<<ans<<"\n";
	return dp[i][prev][mask]=make_pair(ans,ct);
}
/*int rec1(int i,int prev,int mask)
{
	if(i==n)
		return prev;
	if(dp1[i][prev][mask]!=-1)
		return dp1[i][prev][mask];
	int ans=0;
	for(int j=0;j<n;j++)
	{
	//cout<<"BEFORE "<<i<<" "<<j<<" "<<prev<<" "<<mask<<" "<<ans<<"\n";

		if((mask&(1<<j))==0)
		{
			ans=max(ans,(rec1(i+1,bar[j],(mask|(1<<j))))+abs(bar[j]-prev));
			if(ans==ans1)
		count1++;
		}
		//cout<<"AFTER "<<i<<" "<<j<<" "<<prev<<" "<<mask<<" "<<ans<<"\n";
		//if(ans==ans1)
		//count1++;
	}
	//cout<<"AFTER AFTER"<<i<<" "<<j<<" "<<prev<<" "<<mask<<" "<<ans<<"\n";
	//if(ans==ans1)
		//count1++;
	return dp1[i][prev][mask]=ans;

}*/
int main()
{
cin>>n;
	while(n)
	{
		count1=0;
		for(int i=0;i<=n;i++)
		{
		for(int j=0;j<=n;j++)
		{
		for(int l=0;l<(1<<n);l++)
		{
		dp[i][j][l]=make_pair(-1,0);
		}
		}
		}
//		memset(dp1,-1,sizeof(dp1));
bar[0]=0;
		for(int i=1;i<=n;i++)
			cin>>bar[i];
			pair<int,int> val1=rec(1,0,0);
			//cout<<(val1.first)<<endl;
		cout<<(val1.first+(2*n))<<" "<<(val1.second)<<"\n";
		//cout<<ans1<<" "<<"\n";
		//cout<<(ans1+(2*n))<<" "<<count1<<"\n";
		cin>>n;
	}
}
