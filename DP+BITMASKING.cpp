//DP+BITMASK
#include<bits/stdc++.h>
using namespace std;
int n,m,count1;
int dp[2000][25][25];
int visited[25][25];
string st[25];
vector<int> destx,desty;
int  ans[25][25][25][25];
int check(int i,int j)
{
	if(i<0 || j<0 || i>=n || j>=m || st[i][j]=='x')
		return 0;
	return 1;
}
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int  bfs(int starti,int startj)
{
    memset(ans[starti][startj],10000,sizeof(ans[starti][startj]));
	memset(visited,0,sizeof(visited));
	pair<int,int> p=make_pair(starti,startj);
	visited[starti][startj]=1;
	ans[starti][startj][starti][startj]=0;
	queue<pair<int,int> > q;
	q.push(p);
	while(!q.empty())
	{
		pair<int,int > x=q.front();
		q.pop();
		int x1=x.first;
		int y1=x.second;
		//cout<<x1<<" "<<y1<<"\n";

		for(int i=0;i<4;i++)
		{

				int i1=x1+dx[i];
				int j1=y1+dy[i];
				if(visited[i1][j1]==0 && (check(i1,j1)==1))
				{
					visited[i1][j1]=1;
					q.push(make_pair(i1,j1));
					ans[starti][startj][i1][j1]=ans[starti][startj][x1][y1]+1;
				}
		}

	}
}
int rec(int mask,int i1,int j1)
{
	if(mask==((1<<count1)-1))
	   return 0LL;
	if(dp[mask][i1][j1]!=-1)
	   return dp[mask][i1][j1];
	int s=10000;
	for (int i = 0; i < count1; ++i)
	{
		if((mask&(1<<i))==0)
		{
         s=min(s,(rec((mask|(1<<i)),destx[i],desty[i])+ans[i1][j1][destx[i]][desty[i]]));//Just like TSP used the dp of visiting a particular node(basically tring all possible combinations of visiting the nodes)
		}
	}
	return dp[mask][i1][j1]=s;
}
int main()
{


	cin>>m>>n;
	while(n>0 && m>0)
	{
		memset(dp,-1,sizeof(dp));
		destx.clear();
		desty.clear();
	for(int i=0;i<n;i++)
		cin>>st[i];
		count1=0;
		int sourcei,sourcej;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(st[i][j]=='o')
			{
				sourcei=i;
				sourcej=j;
			}
			if(st[i][j]=='*')
			{
				destx.push_back(i);
				desty.push_back(j);
				count1++;
			}
		}
	}
bfs(sourcei,sourcej);    //Dont Forget this,This BFS needs to be computed too
	for(int i=0;i<count1;i++)
	{
	bfs(destx[i],desty[i]); //LIKE Floywd Warshall precomputed all the bfs in the ans array



	}
	int ans=rec(0,sourcei,sourcej);
	//cout<<ans<<"\n";
	if(ans<10000)
    cout<<ans<<"\n";
    else
     cout<<-1<<"\n";
 cin>>m>>n;
}
}
