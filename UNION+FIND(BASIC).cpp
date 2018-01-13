    /*Subham Sanghai*/
    #include<bits/stdc++.h>
    using namespace std;
    long long parent[401];
    long long sizes[401];
    long long init()
    {
      for(long long i=0;i<=400;i++)
      {
        parent[i]=i;
        sizes[i]=1;
      }
    }
    long long finds(long long a)
    {
      while(parent[a]!=a)
        {
      parent[a]=parent[parent[a]];
      a=parent[a];
        }
      return a;
    }
    void unions(long long a,long long b)
    {
      long long c=finds(a);
      long long d=finds(b);
      if(c!=d)
        {
            parent[d]=c;
            sizes[c]+=sizes[d];
        }


    }
    int  main()
    {
      long long t;
      cin>>t;
      while(t--)
      {
      vector<pair<long long,long long> > v;
        long long n,k;
        cin>>n>>k;
        init();
        for(long long i=0;i<n;i++)
        {
          long long a,b;
          cin>>a>>b;
          v.push_back(make_pair(a,b));
        }
        long long ans=0;
        for(long long i=0;i<k;i++)
        {
          long long a,b;
          cin>>a>>b;
          unions(a,b);

        }
        map<pair<int,int>,bool > m;
        set<pair<int,int> > s;
        for(int i=0;i<n;i++)
        {
        long long a=finds(v[i].first);
        long long b=finds(v[i].second);
        if(m[make_pair(a,b)]==true)
        continue;
        s.insert(make_pair(a,b));
        m[make_pair(a,b)]=true;
        m[make_pair(b,a)]=true;
        }
        for(set<pair<int,int> >:: iterator it=s.begin();it!=s.end();++it)
        {
        int a=(*it).first;
        int b=(*it).second;
        if(a==b)
            continue;
          else
            ans+=(sizes[a]*sizes[b]);
        }
        cout<<ans<<endl;
      }
    }

