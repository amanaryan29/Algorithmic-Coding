/*Subham Sanghai*/
/*Problem:Given a Tree,to find the max of sum of node weight traversal starting from a particular given node
and also considering that any node can be visited only once*/
#include<bits/stdc++.h>
using namespace std;
int inans[100005];
int outans[10005];
int weight[10005];
vector<int> adj[100005];
/*dfsin function calculates the max of sum of node weight traversal
which are present below the Node(in its subtree) including its weight also*/
int dfsin(int node,int parent)
{
	int m=weight[node];
	for(int i=0;i<adj[node].size();i++)
	{
		int child=adj[node][i];
		if(child==parent)
			continue;
		m=max(m,weight[node]+dfsin(child,node));
	}
	return inans[node]=m;
}
/*dfsout function calculates the max of sum of node weight traversal
which are present above  the Node(not in its subtree) including its weight also*/
int dfsout(int node,int parent)
{
	int max1=0,max2=0;
	/*here we are calculating the outans for a child of the node*/
	for(int i=0;i<adj[node].size();i++)
	{

		int child=adj[node][i];
		if(child==parent)
			continue;
		if(inans[child]>max1)
		{
			max2=max1;
			max1=inans[child];
		}
		else if(inans[child]>max2)
			max2=inans[child];
	}
/* max1 and max2 are the 1st and 2nd max inans values from all the child's
of node*/
	int use=0LL;
	for(int i=0;i<adj[node].size();i++)
	{
		int child=adj[node][i];
		if(child==parent)
			continue;
		if(inans[child]==max1)/*if the 1st max value is that of the child for which we are
                                    calculating the outans then consider the 2nd max*/
			use=max2;
		else
			use=max1;

	outans[child]=weight[child]+max(use+weight[node],outans[node]);/* outans[child] can be built again from its parent*/
	/*node is the parent of child and we have added weight[child] bcz we want , outans to include the node weight of the
	child(particular node for which we are calculating the outans*/
	dfsout(child,node);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			adj[i].clear();
		fill(inans,inans+100005,0LL);
		fill(outans,outans+100005,0LL);
		for(int i=0;i<n;i++)
			cin>>weight[i];
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfsin(0,-1);
		dfsout(0,-1);
		for(int i=0;i<n;i++)
		{
		//printing respective max of both the in and out considering particular ith node as the root*/
			cout<<max(inans[i],outans[i])<<" ";
        }
		cout<<endl;
	}
}
