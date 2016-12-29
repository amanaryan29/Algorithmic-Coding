    #include<bits/stdc++.h>
        using namespace std;
        long long parent[20005];
        long long n;
        long long dist[20005];
        long long ini()
        {
        for(long long i=1;i<=n;i++)
        {
            parent[i]=i;
            dist[i]=0;
        }
    }
        long long finds(long long a)
        {
        if(parent[a]!=a)
        {
            int x=parent[a];
            parent[a]=finds(parent[a]); //Recursively call the function with the parent of â��aâ�� till you reach a terminal node. Then update the distances of each of the nodes on the return path and also their parent to point to that terminal node.
            dist[a]+=dist[x];// a is the node for that iteration and x is its parent
        }
        return parent[a]; //returning parent[a] bcz we are doing parent[a]=parent[parent[a]]
        }
        long long uni(long long a,long long b)
        {

    //    b=finds(b);
    	parent[a]=b;
        dist[a]=abs(a-b)%1000;
        }
        int  main()
        {
        ios_base::sync_with_stdio(false);
        cin.tie(false);
            long long t;
            cin>>t;
            while(t--)
            {
        //    ini();
                cin>>n;
                ini();
                char s;
                cin>>s;
                while(s!='O')
                {

                    if(s=='E')
                    {

                        long long numb;
                        cin>>numb;
                        int x=finds(numb);
                        cout<<dist[numb]<<"\n";
                    }
                    else
                    {

                        long long a,b;
                        cin>>a>>b;
                        if(finds(a)!=finds(b))
                        uni(a,b);
                    }
               cin>>s;
                }

            }
        }
