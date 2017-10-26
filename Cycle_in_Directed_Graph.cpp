#include<bits/stdc++.h>
using namespace std;
int visited[10005],visited1[10005];
vector<int> directed[10005];
int dfs2(int node)
{
//cout<<node<<endl;
	visited[node]=1;//universal stack
	visited1[node]=1;// this visited array is for the dfs( to mark ,the recursion stack in one dfs)
	for(int i=0;i<directed[node].size();i++)
	{
		if(visited1[directed[node][i]]==0 && dfs2(directed[node][i]))
		{
			return 1;
		}
		else if(visited[directed[node][i]]==1)
           return 1;

	}
	visited[node]=0;
	return 0;
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(false);
	int t;
	cin>>t;
	while(t--)
	{

		int n,m;
		cin>>n>>m;
		for(int i=0;i<=n;i++)
		{
			directed[i].clear();
		}
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			directed[u].push_back(v);
		}
		fill(visited,visited+10005,0);
		fill(visited1,visited1+10005,0);
		bool ans=0;
		for(int i=1;i<=n;i++)
		{

			if(visited1[i]==0)
			{
				ans=dfs2(i);
				//cout<<"i "<<ans<<endl;
			}
			if(ans==1)
				break;
		}
		if(ans==1)
		{
			cout<<"Cycle Present in Graph\n";

		}
		else
		{
		cout<<"Cycle Not present\n";
		}
    }
}
