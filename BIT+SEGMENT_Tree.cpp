    #include<bits/stdc++.h>
    using namespace std;
    int BITtree[1000005],tree[1000005],a[1000005];
    int updateBIT(int n,int index,int val)
    {
    while(index<=n)
    {
    BITtree[index]+=val;
    index+=((index)&(-index));

    }
    }
    int getSum(int n,int index)
    {
    int sum=0;
    while(index>0)
    {
    sum+=BITtree[index];
    index-=((index)&(-index));
    }
    return sum;
    }
    void build(int  start,int ends,int node)
    {

    if(ends==start)
    {
    tree[node]=a[start];
    }
    else
    {
    int mid=(start+ends)/2;
    build(start,mid,(2*node));
    build(mid+1,ends,(2*node)+1);
    tree[node]=max(tree[(2*node)],tree[(2*node)+1]);

    }
    }
    int query(int start,int ends,int left,int right,int node)
    {
    if(left>ends || right<start || ends<start)
    return INT_MIN;
    else if(left<=start && right>=ends)
    return tree[node];
    int mid=(start+ends)/2;
    int leftval=query(start,mid,left,right,(2*node));
    int rightval=query(mid+1,ends,left,right,(2*node)+1);
    return max(leftval,rightval);
    }
    int main()
    {
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    int  n;
    cin>>n;
    int count1=1;
    vector<pair<int,int> >q1,q2;
    map<int,bool> m1;
    map<int,int> m2;
    while(n--)
    {
    int u,v;
    cin>>u>>v;
    q1.push_back(make_pair(u,v));
    m1[u]=true;
    m1[v]=true;
    }
    int q;
    cin>>q;
    while(q--)
    {
    int u,v;
    cin>>u>>v;
    q2.push_back(make_pair(u,v));
    m1[u]=true;
    m1[v]=true;
    }
    for(map<int,bool> ::iterator it=m1.begin();it!=m1.end();++it)
    {
    m2[it->first]=count1++;
    }
    count1--;
    fill(BITtree,BITtree+1000005,0);
    fill(tree,tree+1000005,0);
    for(int i=0;i<q1.size();i++)
    {
    int u1=m2[q1[i].first];
    int v1=m2[q1[i].second];
    //cout<<u1<<" "<<v1<<endl;
    updateBIT(count1,u1,1);
    updateBIT(count1,v1+1,-1);

    }
    for(int i=1;i<=count1;i++)
    {
    a[i]=getSum(n,i);
    //cout<<a[i]<<"  ";
    }

    build(1,count1,1);
    /*for(int i=1;i<=15;i++)
    cout<<tree[i]<<" ";
    cout<<"\n";*/
    for(int i=0;i<q2.size();i++)
    {
    int u1=m2[q2[i].first];
    int v1=m2[q2[i].second];
    //cout<<u1<<" "<<v1<<endl;
    //cout<<count1<<"\n";
    cout<<query(1,count1,u1,v1,1)<<"\n";

    }
    }
