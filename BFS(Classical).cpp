#include<bits/stdc++.h>
using namespace std;
char ch[105][105];
int states[105][105];
int ans[105][105];
int n,m;
int  visited[105][105];

int bfs(int starti,int startj)
{
    int newi,newj;
    queue<pair<int,pair<int,int> > >q;
    visited[starti][startj]=1;
    q.push(make_pair(0,make_pair(starti,startj)));
    states[starti][startj]=0;
    while(!q.empty())
    {

        pair<int,pair<int,int> > p=q.front();
        q.pop();
        int i=(p.second).first;
        int j=(p.second).second;
        int state=p.first;
      //cout<<i<<" "<<j<<" "<<state<<"\n";
        if(i==(n-1) || j==(m-1) || i==0 || j==0)
            return (1+ans[i][j]);

        newi=i+1;
        newj=j;
        if(newi<n &&  newj<m)
    {
//cout<<"step1 ";
        if (visited[newi][newj]==0 && ch[newi][newj]=='.')
        {
           visited[newi][newj]=1;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]=1 && ch[newi][newj]=='.' && states[newi][newj]!=state)
        {
           visited[newi][newj]=2;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
         if (visited[newi][newj]==0 && ch[newi][newj]=='H')
        {
           visited[newi][newj]=1;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='H' && states[newi][newj]!=state)
        {
           visited[newi][newj]=2;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='O')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(1,make_pair(newi,newj)));
            states[newi][newj]=1;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='O' && states[newi][newj]!=1)
        {
            visited[newi][newj]=2;
            q.push(make_pair(1,make_pair(newi,newj)));
            states[newi][newj]=1;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='C')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(0,make_pair(newi,newj)));
            states[newi][newj]=0;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='C' && states[newi][newj]!=0)
        {
            visited[newi][newj]=2;
            q.push(make_pair(0,make_pair(newi,newj)));
            states[newi][newj]=0;
            ans[newi][newj]=ans[i][j]+1;
        }
         if(visited[newi][newj]==0 && ch[newi][newj]=='D' && state==1)
        {
           visited[newi][newj]=1;;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }

    }
     newi=i-1;
        newj=j;
        if(newi<n &&  newj<m)
    {
 if (visited[newi][newj]==0 && ch[newi][newj]=='H')
        {
           visited[newi][newj]=1;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='H' && states[newi][newj]!=state)
        {
           visited[newi][newj]=2;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='.')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='.' && states[newi][newj]!=state)
        {
            visited[newi][newj]=2;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='O')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(1,make_pair(newi,newj)));
            states[newi][newj]=1;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='O' && states[newi][newj]!=1)
        {
            visited[newi][newj]=2;
            q.push(make_pair(1,make_pair(newi,newj)));
            states[newi][newj]=1;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='C')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(0,make_pair(newi,newj)));
            states[newi][newj]=0;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='C' && states[newi][newj]!=0)
        {
            visited[newi][newj]=2;
            q.push(make_pair(0,make_pair(newi,newj)));
            states[newi][newj]=0;
            ans[newi][newj]=ans[i][j]+1;
        }
         if(visited[newi][newj]==0 && ch[newi][newj]=='D' && state==1)
        {
           visited[newi][newj]=1;;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }

    }
    newi=i;
        newj=j+1;
        if(newi<n &&  newj<m)
    {
   if (visited[newi][newj]==0 && ch[newi][newj]=='H')
        {
           visited[newi][newj]=1;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='H' && states[newi][newj]!=state)
        {
           visited[newi][newj]=2;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='.')
        {
           visited[newi][newj]=1;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='.' && states[newi][newj]!=state)
        {
            visited[newi][newj]=2;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='O')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(1,make_pair(newi,newj)));
            states[newi][newj]=1;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='O' && states[newi][newj]!=1)
        {
            visited[newi][newj]=2;
            q.push(make_pair(1,make_pair(newi,newj)));
            states[newi][newj]=1;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='C')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(0,make_pair(newi,newj)));
            states[newi][newj]=0;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='C' && states[newi][newj]!=0)
        {
            visited[newi][newj]=2;
            q.push(make_pair(0,make_pair(newi,newj)));
            states[newi][newj]=0;
            ans[newi][newj]=ans[i][j]+1;
        }
         if(visited[newi][newj]==0 && ch[newi][newj]=='D' && state==1)
        {
           visited[newi][newj]=1;;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }

    }
    newi=i;
        newj=j-1;
        if(newi<n &&  newj<m)
    {
 if (visited[newi][newj]==0 && ch[newi][newj]=='H')
        {
           visited[newi][newj]=1;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='H' && states[newi][newj]!=state)
        {
           visited[newi][newj]=2;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='.')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='.' && states[newi][newj]!=state)
        {
            visited[newi][newj]=2;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='O')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(1,make_pair(newi,newj)));
            states[newi][newj]=1;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='O' && states[newi][newj]!=1)
        {
            visited[newi][newj]=2;
            q.push(make_pair(1,make_pair(newi,newj)));
            states[newi][newj]=1;
            ans[newi][newj]=ans[i][j]+1;
        }
        if(visited[newi][newj]==0 && ch[newi][newj]=='C')
        {
           visited[newi][newj]=1;;
            q.push(make_pair(0,make_pair(newi,newj)));
            states[newi][newj]=0;
            ans[newi][newj]=ans[i][j]+1;
        }
        else if(visited[newi][newj]==1 && ch[newi][newj]=='C' && states[newi][newj]!=0)
        {
            visited[newi][newj]=2;
            q.push(make_pair(0,make_pair(newi,newj)));
            states[newi][newj]=0;
            ans[newi][newj]=ans[i][j]+1;
        }
         if(visited[newi][newj]==0 && ch[newi][newj]=='D' && state==1)
        {
           visited[newi][newj]=1;;
            q.push(make_pair(state,make_pair(newi,newj)));
            states[newi][newj]=state;
            ans[newi][newj]=ans[i][j]+1;
        }

    }


    }
    return -1;
}
int main()
{

ios_base::sync_with_stdio(false);
cin.tie(false);
    cin>>n>>m;
    while(n!=-1 || m!=-1)
    {
        int starti,startj;
      //  fill(visited,visited+105,0);
       memset(ans,0,sizeof(ans));
       memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {


    cin>>ch[i][j];
    if(ch[i][j]=='H')
    {
        starti=i;
        startj=j;
    }
    }
    }
    cout<<bfs(starti,startj)<<"\n";
    cin>>n>>m;
}
}
