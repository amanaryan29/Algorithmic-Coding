#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001],adj1[100001];
int visited[100001],visited1[100001];
int gr[100005];
stack<int> s;
queue<int> q1;
int count1=0,count2=0;
int dfs(int start)
{
//cout<<start<<"\n";
visited[start]=1;
for(int i=0;i<adj[start].size();i++)
{
if(visited[adj[start][i]]==0)
{
dfs(adj[start][i]);
}

}
s.push(start);

}
int dfs2(int start,int group)
{
visited[start]=1;
gr[start]=group;
for(int i=0;i<adj1[start].size();i++)
{
if(visited[adj1[start][i]]==0)
{
dfs2(adj1[start][i],group);
}

}

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(false);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
adj[i].clear();
for(int i=1;i<=m;i++)
{
int u,v;
cin>>u>>v;
adj[u].push_back(v);
adj1[v].push_back(u);
}

fill(visited,visited+100001,0);
set<int> st;
for(int i=1;i<=n;i++)
{
if(visited[i]==0)
dfs(i);
//cout<<"\n";
}
int ans=0;
fill(visited,visited+100001,0);
int group=0;
while(!s.empty())
{
int a=s.top();
//cout<<a<<"\n";
if(visited[a]==0)
{
group++;  //grouping the SCC's together and forming a directed acyclic graph
dfs2(a, group);
}
s.pop();
}
int g1,g2;
int out[100005],in[100005];
fill(out,out+100005,0);
fill(in,in+100005,0);
for(int i=1;i<=n;i++)
{
g1=gr[i];
for(int j=0;j<adj[i].size();j++)
{
g2=gr[adj[i][j]];
if(g2==g1)
continue;
out[g1]++;
in[g2]++;
}

}
int ans1;
int count3=0;
for(int i=1;i<=group;i++)
{
if(in[i]!=0 && out[i]==0)
{
ans1=i;
count3++;

}

}
if(ans1!=0 && count3==1) //if more than one graph with outdegreee 0 is found then no such node possible bcz that both these are unaccessible from one another
{
for(int i=1;i<=n;i++)   //if that node is the desired node and the outdegree of that node is not zero then the node that node is pointing to will also be the desired node and in that case they will form a SCC and will be under same group,so outdegree of desired node can be >0
{
if(gr[i]==ans1)
st.insert(i);

}
}
cout<<st.size()<<"\n";
for(set<int>::iterator it=st.begin();it!=st.end();++it)
cout<<(*it)<<" ";
cout<<"\n";
}

