    /*BIT MASKING*/
    #include<bits/stdc++.h>
    using namespace std;
    long long n;
    long long dp[20][20][4][1001];
    long long rec(long long current,long long next,long long r,long long c)
    {
    if(c==n)
    return 1;
    if(r==4 && current==15)
    {
    return rec(next,0,0,c+1);
    }
    if(r==4 && current!=15)
    return 0;
    if(r>4)
    return 0;
    long long s=0;
    if(dp[current][next][r][c]!=-1)
    return dp[current][next][r][c];
    if(((c+1)<n)&& (((current&(1<<r))==0)&&((next&(1<<r))==0)) && (((current&(1<<r))==0)&&((current&(1<<(r+1)))==0))) //Case when we can either select vertically or horizontally
    {

    s+=rec((current|(1<<r)),(next|(1<<r)),r+1,c)+rec((current|(1<<r)|(1<<(r+1))),next,r+2,c);
    }
    else if((c+1)<n)   //when it is not last column
    {
    if(((current&(1<<r))==0)&&((next&(1<<r))==0))
    s+=rec((current|(1<<r)),(next|(1<<r)),r+1,c);
    else if(((current&(1<<r))==0)&&((current&(1<<(r+1)))==0))
    {
    s+=rec((current|(1<<r)|(1<<(r+1))),next,r+2,c);
    }
    else
    s+=rec(current,next,r+1,c);
    }
    else //when it is the last column and we can only place it horizontally only
    {
    if(((current&(1<<r))==0)&&((current&(1<<(r+1)))==0))
    {
    s+=rec((current|(1<<r)|(1<<(r+1))),next,r+2,c);
    }
    else
    s+=rec(current,next,r+1,c);

    }
    return dp[current][next][r][c]=s;
    }
    int main()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    long long t;
    cin>>t;
    long long l=0;
    while(t--)
    {
    memset(dp,-1,sizeof(dp));
    l++;
    cin>>n;
    cout<<l<<" "<< rec(0,0,0,0)<<"\n";

    }


    }
