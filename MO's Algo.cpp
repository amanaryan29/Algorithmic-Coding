    #include<bits/stdc++.h>
    using namespace std;
    int counts[1000005];
    int comp(pair<int,pair<int,int > > a,pair<int,pair<int,int> >b)
    {
    if(b.second.first!=a.second.first)
    return a.second.first<b.second.first;
    else
    return a.first<b.first;

    }
    int main()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    fill(counts,counts+1000005,0);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    int sq=sqrt(n);
    int q;
    vector<pair<int,pair<int,int > > >block[sq+1];
    int count1=1;
    cin>>q;
    int q1=q;
    int maa=0;
    while(q1--)
    {
    int u1,v1;
    cin>>u1>>v1;
    int ans2=ceil((double)u1/(double)sq);
    //cout<<ans2<<"\n";
    maa=max(maa,ans2);
    block[ans2-1].push_back(make_pair(u1,make_pair(v1,count1++)));
    }
    for(int i=0;i<maa;i++)
    sort(block[i].begin(),block[i].end(),comp);
    int left=1;
    int right=0;
    int ans1=0;
    int ans[q+1];
    for(int i=0;i<maa;i++)
    {
    for(int j=0;j<block[i].size();j++)
    {
    int u1=block[i][j].first;
    int v1=block[i][j].second.first;;
    int co=block[i][j].second.second;
    //cout<<"HELLO :"<<u1<<" "<<v1<<" "<<co<<"\n";
    while(right<v1)
    {
    right++;
    counts[a[right]]++;
    if(counts[a[right]]==1)
    ans1++;
    }
    //cout<<counts[1]<<"\n";
    //cout<<right<<"\n";
    //cout<<"\n";
    while(left>u1)
    {
    left--;
    counts[a[left]]++;
    if(counts[a[left]]==1)
    ans1++;
    }

    while(right>v1)
    {
    counts[a[right]]--;
    if(counts[a[right]]==0)
    ans1--;
    right--;
    }
    while(left<u1)
    {
    counts[a[left]]--;
    if(counts[a[left]]==0)
    ans1--;
    left++;
    }
    /*for(int i=1;i<=3;i++)
    cout<<counts[i]<<" ";
    cout<<"\n";*/
    ans[co]=ans1;
    }
    }
    for(int i=1;i<=q;i++)
    cout<<ans[i]<<"\n";
    }
