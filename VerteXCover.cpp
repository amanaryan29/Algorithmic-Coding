    #include<bits/stdc++.h>
    using namespace std;
    /*A minimal vertex cover for the whole tree either contains the root,
    or does not contain the root. In either case we of course want the
    minimal vertex cover that satisfies that condition. If we use the root,
    then we can either use or not use any of its children,
    but if we don't use the root, then we must use all of its children.
    So it's clear that to solve the problem for a given tree, we need
    to know for each subtree both the minimal vertex cover containing the
    root and the minimal vertex cover either containing or not containing the root.*/

    /*So we define A[n] to be the size of the minimal vertex cover of the subtree
    rooted at node n that contains n, and B[n] to be the size of the minimal vertex
    cover of the subtree rooted at node n, regardless of whether it contains n or not.
    We can compute A[n] and B[n] for a node once we know A[c] and B[c] for all its children c.
    That's why this is a DP over trees algorithm.*/


    int dp[100005][2];
    vector<int> adj[100005];
    int dfs(int node,int parent)
    {
    dp[node][0]=0;/*states of dp are node and choice*/
    dp[node][1]=1;/*if choice is 0,that means that node is not being selected ,so we store a 0 */
    /*if choice is 1,that means that node is not  selected ,so we store a 1 */
    for(int i=0;i<adj[node].size();i++)
    {
    if(adj[node][i]==parent)
    continue;
    dfs(adj[node][i],node);
    dp[node][0]+=dp[adj[node][i]][1];// if node is not selected ,it is a must that its childrens are selected
    dp[node][1]+=min(dp[adj[node][i]][1],dp[adj[node][i]][0]);// if node is selected,we can either select or not select the children
    }

    }
    int main()
    {
    	int n;
    	cin>>n;
    	//fill(degree,degree+n,0);
    	for(int i=1;i<n;i++)
    	{
    		int u,v;
    		cin>>u>>v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	dfs(1,-1);
    	cout<<min(dp[1][0],dp[1][1])<<endl;//min of not selecting the root node and of selecting the root node
    }
