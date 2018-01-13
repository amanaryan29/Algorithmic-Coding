#include<bits/stdc++.h>
using namespace std;
stack<int> s;
vector<int> v1;
int parent[9005];
int dp[9005];
vector<int> newgraph[9005],g[9005],g1[9005];
int visited1[9005],visited2[9005],visitedd[9005];
map<int,int> mp;
/*depth function calculates the number of nodes that can be reached from every node in A DAG*/
int  depth(int node)
{

visitedd[node]=1;
int result=mp[node];
/* if we uncomment this ,then we will get a WA because that time the stored dp will directly return the number of nodes
that can be visited from it, without marking the childs visited ..which can lead to the problem of same child being visited
once from the parent and once from the node whose dp was stored*/
//if(dp[node]!=-1)
//return dp[node];
for(int i=0;i<newgraph[node].size();i++)
{
if(visitedd[newgraph[node][i]]==0)
result+=depth(newgraph[node][i]);

}
/*visited is not made false again because we dont want any node to visited more than once,i.e one child should not contribute
for the ans more than once for a single parent */

/*1->2->3
  |     / (1 ->3)
  -------
Here 3 should not contribute to 1 , twice ,once for 1 and the other time for 2 .So to remove this ambiguity
we dont make the visited false*/
return dp[node]=result;
}
void dfs(int node)
{
	visited1[node]=true;
	for(int i=0;i<g[node].size();i++)
	{
		int node1=g[node][i];
		if(!visited1[node1])
			dfs(node1);
	}
	s.push(node);
}
void dfs2(int node)
{
	v1.push_back(node);
	visited2[node]=1;
	for(int i=0;i<g1[node].size();i++)
	{
		if(!visited2[g1[node][i]])
			dfs2(g1[node][i]);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		/*initialising the vectors*/
		for(int i=0;i<=n;i++)
		{
		g[i].clear();
		g1[i].clear();
		newgraph[i].clear();
		}
		/*g is the initial graph*/
		/* g1 is the transpose if the original graph*/
		for(int i=0;i<m;i++)
		{
            int u,v;
			cin>>u>>v;
			g[v].push_back(u);
			g1[u].push_back(v);
		}
		mp.clear();
		fill(visited1,visited1+9005,0);
		fill(visited2,visited2+9005,0);
		fill(parent,parent+9005,0);
		fill(visitedd,visitedd+9005,0);
		/* dfs function => Create an empty stack ‘S’ and do DFS traversal of a graph.
		In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex,
		push the vertex to stack(push the vertex,only after all its children are pushed)*/
		for(int i=1;i<=n;i++)
		{

			if(!visited1[i])
				dfs(i);
		}
		/*One by one pop a vertex from S while S is not empty.
		 Let the popped vertex be ‘v’.
        Take v as source and do DFS (call dfs2(v)).
        The DFS starting from v prints strongly connected component of v. */
        vector<int> scc[90005];
		while(!s.empty())
		{
			if(!visited2[s.top()])
			{
				dfs2(s.top());
				int mi=INT_MAX;
				/*v1 vector contains the nodes in the same SCC*/
				/*mi is the minimum indexed node among all the vertices of the SCC*/
				/*parent[vertex] is the parent of the vertex
				(i.e . the vertex index(minimum one) by which that particular SCC group is represented*/

				for(int i=0;i<v1.size();i++)
				{
					mi=min(mi,v1[i]);
				}
				for(int i=0;i<v1.size();i++)
				{
					scc[mi].push_back(v1[i]);
					parent[v1[i]]=mi;
				}
				/* mp stores the size of the SCC(i.e the number of vertices in the SCC)*/
				mp[mi]=v1.size();
				v1.clear();
			}
			else
				s.pop();
		}
		//for(int i=1;i<=n;i++)
		//cout<<i<<" "<<parent[i]<<endl;
		/*Creating the new graph after converting the graph into a Directed Acylic Graph using SCC */
		for(int i=1;i<=n;i++)
		{
		map<int,int> mvisited;
			for(int j=0;j<g[i].size();j++)
			{

			//cout<<parent[i]<<" "<<parent[g[i][j]]<<"hello "<<endl;
			/*if parent[u] == parent[v] then that means both are part of the same SCC*/
				if(parent[i]!=parent[g[i][j]] && mvisited[parent[g[i][j]]]==0)
				{
				 mvisited[parent[g[i][j]]]=1;
				newgraph[parent[i]].push_back(parent[g[i][j]]);
				}
			}
		}
		/*for(int i=1;i<=n;i++)
		{
		cout<<i<<"  ";
		for(int j=0;j<newgraph[i].size();j++)
		{
		cout<<newgraph[i][j]<<" ";
		}
		cout<<endl;

		}*/
		int max1=0;
		for(int i=1;i<=n;i++)
		dp[i]=-1;
		/*depth funations calculates the number of vertices that can be visited from that particular vertex*/
		for(int i=1;i<=n;i++)
		{
		dp[i]=depth(i);
		/* here we reinitialise visitedd with false so that if a particular node can be visted from two diff nodes(2 diff SCC's) ,
		we are able to do that*/
		memset(visitedd,0,sizeof(visitedd));
		}
		for(int i=1;i<=n;i++)
		{
		max1=max(max1,dp[i]);
        }
		//cout<<max1<<endl;

		vector<int> finalans;


		for(int i=1;i<=n;i++)
		{
			if(dp[i]==max1)
			{
				for(int j=0;j<scc[i].size();j++)
					finalans.push_back(scc[i][j]);
			}
		}
		sort(finalans.begin(),finalans.end());
		for(int i=0;i<finalans.size();i++)
		cout<<finalans[i]<<" ";
		cout<<endl;
		/*for(int i=1;i<=n;i++)
		cout<<"dp "<<i<<" "<<dp[i]<<endl;
		for(int i=1;i<=n;i++)
		{
		cout<<i<<"     ";
            for(int j=0;j<newgraph[i].size();j++)
            {
                cout<<newgraph[i][j]<<" ";
            }
            cout<<endl;
		}*/
	}
}
