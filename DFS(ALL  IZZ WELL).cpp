#include<bits/stdc++.h>
using namespace std;
string s[100];
string word="ALLIZZWELL";
int visited[100][100];
int check(int n,int m,int i,int j)
{
if(i<0 || j<0 || i>=n || j>=m)
return 0;
return 1;

}
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
int dfs(int xx,int yy,int c,int n,int m)
{
visited[xx][yy]=1;
if(c>=10)
return 1;
int ans=0;
for(int i=0;i<8;i++)
{
int x1=xx+dx[i];
int y1=yy+dy[i];
//cout<<x1<<" "<<y1<<" "<<c<<"\n";
if(check(n,m,x1,y1)==1)
{
//cout<<x1<<" "<<y1<<" "<<c<<"\n";
//cout<<word[c]<<" "<<s[x1][y1]<<"\n";
if(word[c]==s[x1][y1] && visited[x1][y1]==0)
{

ans|=dfs(x1,y1,c+1,n,m);
visited[x1][y1]=0;       //so that in next recursion that paricular index is not visited
                           //all the char in the particular rec stack must be visited
}

}

}
return ans;
}
int main()
{
int t;
cin>>t;
while(t--)
{
int n,m;
cin>>n>>m;

for(int i=0;i<n;i++)
cin>>s[i];

int flag=0;
for(int i=0;i<n;i++)
{

for(int j=0;j<m;j++)
{
if(s[i][j]=='A')
{
memset(visited,0,sizeof(visited));
int ans=dfs(i, j,1,n,m);
if(ans==1)
{
flag=1;
break;
}
}

}
if(flag==1)
break;
}
if(flag==1)
cout<<"YES\n";
else
cout<<"NO\n";
}
}
