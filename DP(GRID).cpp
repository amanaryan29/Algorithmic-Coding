    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    int t;
    cin>>t;
    while(t--)
    {
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<m;j++)
    {
    cin>>a[i][j];
    }
    }
    int dp[n][m];
    dp[n-1][m-1]=1;
    for(int i=n-2;i>=0;i--)
    {
    dp[i][m-1]=max(1,dp[i+1][m-1]-a[i][m-1]);
    }
    for(int i=m-2;i>=0;i--)
    {
    dp[n-1][i]=max(1,dp[n-1][i+1]-a[n-1][i]);
    }
    for(int i=n-2;i>=0;i--)
    {
    for(int j=m-2;j>=0;j--)
    {
    dp[i][j]=max(1,(min(dp[i][j+1],dp[i+1][j])-a[i][j])); //dp[i][j] suggests the min value of power reqired so that power at no pos is <=0
    }
    }

    cout<<max(1,dp[0][0])<<"\n";
    }
    }
