    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
    int t;
    cin>>t;
    int k=0;
    while(t--)
    {
    k++;
    int n;
    cin>>n;
    int sum=0;
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    sum+=arr[i];

    }
    cout<<"Case "<<k<<": ";
    if(sum%2==0 && n%2==0)
    {
    vector< bitset<41> > dp(sum+1); //(sum+1 tells the size of vector ,if we dont mention size we cant acccess dp[j] directly)
    dp[0][0]=1;
    for(int i=0;i<n;i++)
    {
    for(int j=sum;j>=arr[i];j--)
    {
    dp[j]=(dp[j]|((dp[j-arr[i]])<<1));//dp[j] counts no of bits set (no of elements required to make j)
    //cout<<dp[j]<<"\n";
    }

    }
    if(dp[sum/2][n/2]==1)//if that bit is set that means it is possible to make (sum/2) with (n/2 ) elements
    cout<<"Yes\n";
    else
    cout<<"No\n";
    }
    else
    cout<<"No\n";
    }

    }
