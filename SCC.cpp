#include<bits/stdc++.h>
using namespace std;
int visited[1001],visited1[1001],count1=0,n;
stack<int> q;
vector<int> adj[1001],adj1[1001];
int dfs2(int temp)
{


    count1++;
    visited1[temp]=1;
        for(int i=0;i<adj1[temp].size();i++)
        {
            if(visited1[adj1[temp][i]]==0)
            {

                dfs2(adj1[temp][i]);

            }
        }

    return count1;
}
int dfs(int temp)
{



    visited[temp]=1;
        for(int i=0;i<adj[temp].size();i++)
        {
            if(visited[adj[temp][i]]==0)
            {

                dfs(adj[temp][i]);

            }
        }
        q.push(temp);

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
count1=0;
        cin>>n;
int v;
fill(visited,visited+n+1,0);
fill(visited1,visited1+n+1,0);
      for(int i=0;i<=n;i++)
      {
          adj[i].clear();
          adj1[i].clear();
      }
        for(int u=1;u<=n;u++)
        {
            int num;
            cin>>num;
            for(int j=0;j<num;j++)
            {
                cin>>v;
                adj[v].push_back(u);
                adj1[u].push_back(v);
            }
        }
       /* for(int i=1;i<=n;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }*/

        int ans=0;
        for(int i=1;i<=n;i++)
        {
if(visited[i]==0)
           dfs(i);

         //  cout<<count1<<"\n";


        }
        int x=q.top();
while(!q.empty())
{
    cout<<q.top()<<endl;
    q.pop();
}
        cout<<dfs2(x)<<"\n";
    }
}
