

SPOJ submission 16675747 (C++14) plaintext list. Status: AC, problem INVCNT, contest SPOJ. By bit_coder2k14 (codeblocks), 2016-04-05 16:37:52.

    /*SEGMENT TREE*/
    #include<bits/stdc++.h>
    using namespace std;
    long long tree[2000005];
    /*CODEBLOCKS*/
    /*SEGMENT TREE*/
    /*STORING THE NUMBER OF NUMBERS BETWEEN START TO END TILL NOW IN THE SEGMENT TREE*/
    long long build(long long node,long long start,long long ends)
    {
        if(start==ends)
        tree[node]=0;
        else
        {


        long long mid=(start+ends)/2;
        build((2*node),start,mid);
        build((2*node)+1,mid+1,ends);
        tree[node]=tree[(2*node)+1]+tree[(2*node)];
        }

    }
    void update(long long node,long long start,long long ends,long long idx,long long val)
    {
        if(start==ends)
        {


            tree[node]+=val;

        }
        else
        {
            long long mid=(start+ends)/2;
            if(idx>=start && idx<=mid)
                update((2*node),start,mid,idx,val);
                else
                    update((2*node)+1,mid+1,ends,idx,val);

        tree[node]=tree[(2*node)]+tree[(2*node)+1];
        }

    }
    long long query(long long node,long long start,long long ends,long long qlow,long long qhigh)
    {
        if(qlow>qhigh)
            return 0;
        if(qlow>ends || qhigh<start)
        return 0;
        if(qlow<=start && qhigh>=ends)
            return tree[node];
            long long mid=(start+ends)/2;
        long long p1=query((2*node),start,mid,qlow,qhigh);
        long long p2=query((2*node)+1,mid+1,ends,qlow,qhigh);
        return p1+p2;
    }
    int main()
    {
        long long t;
        cin>>t;
        while(t--)
        {
            long long n;
            cin>>n;
            vector<pair<long long,long long> > v,v2;
            long long arr[n+1];
            for(long long i=1;i<=n;i++)
            {
                cin>>arr[i];
                v.push_back(make_pair(arr[i],i));
            }
            sort(v.begin(),v.end());
            long long counts=1;
           v2.push_back(make_pair(v[0].second,1));
            for(long long i=0;i<v.size();i++)
            {
                if(i+1==v.size())
                    break;
                if(v[i].first==v[i+1].first)
                {
                    v2.push_back(make_pair(v[i+1].second,counts));
                }
                else
                {


                    counts++;
                     v2.push_back(make_pair(v[i+1].second,counts));
                }
            }

            long long ans=0;
            build(1,1,n);
            // cout<<v2.size();

           long long ma= v2[(v2.size()-1)].second;
           //cout<<ma;
            sort(v2.begin(),v2.end());
            for(long long i=0;i<v2.size();i++)
            {

                ans+=query(1,1,n,v2[i].second+1,ma); //CHECKING IF HOW MANY NUMBERS FROM (PRESENT NO.+1) TO MAX HAVE ALREADY ARRIVED .THEREFORE CONTRIBUTING TO ANS (INVERSIONS)


                update(1,1,n,v2[i].second,1);

            }
            cout<<ans<<"\n";
        }
    }
