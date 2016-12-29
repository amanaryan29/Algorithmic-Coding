    //LCS+KNAPSACK

    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    int t;
    cin>>t;
    while(t--)
    {
    string a,b;
    int k1;
    cin>>a>>b>>k1;
    int DP[105][105][105];
    memset(DP,0,sizeof(DP));
    for(int i=1;i<=a.length();i++)
    {
    for(int j=1;j<=b.length();j++)
    {
    for(int k=1;k<=k1;k++)
    {
    if(a[i-1] == b[j-1]){
    DP[i][j][k] = max(DP[i][j][k],DP[i-1][j-1][k]);   // not selecting it
    if(k==1 ||(k>1 && DP[i-1][j-1][k-1]!=0))
    DP[i][j][k] = max(DP[i][j][k], DP[i-1][j-1][k-1]+(int)a[i-1]);//selecting it

    }
    else
    {
    DP[i][j][k] = DP[i - 1][j][k];
    DP[i][j][k] = max(DP[i][j][k], DP[i][j-1][k]);

    }
    //cout<<"k "<<k<<":"<<DP[i][j][k]<<"\n";

    }
    //cout<<"\n";
    }
    }
    cout<<DP[a.length()][b.length()][k1]<<"\n";
    }
    }
