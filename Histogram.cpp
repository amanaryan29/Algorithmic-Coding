#include<bits/stdc++.h>
using namespace std;
int  main()
{
    long long n;

    cin>>n;

    while(n!=0)
    {
        long long height[n];
        stack<long long>st;
        long long ans=0,m=0,t,i;

        for( i=0;i<n;i++)
        {


            cin>>height[i];
        }
        for( i=0;i<n;i++)
        {
            if(st.empty())
                st.push(i);
            else  if(height[i]>=height[st.top()])
                st.push(i);
            else
            {
                while(!st.empty() && height[st.top()]>height[i])
                {
                    t=height[st.top()];

                    st.pop();
                    if(!st.empty())
                    {


                        m=t*(i-st.top()-1);
                       //  cout<<t<<" i "<<i<<" "<<st.top()<<" "<<m<<endl;
                    }
                    else
                    {


                        m=t*i;
                         //cout<<t<<" i "<<i<<" "<<m<<endl;
                    }
                      //  if(!st.empty())
                        //cout<<m<<" "<<height[st.top()]<<" "<<i<<endl;;
                    ans=max(m,ans);
                }
                st.push(i);

            }
        }
        while(!st.empty())
                {
                    t=height[st.top()];
                    st.pop();
                    if(!st.empty())
                    {


                        m=t*(i-st.top()-1);
                    //     cout<<t<<" i "<<i<<" "<<st.top()<<" "<<m<<endl;

                    }
                    else
                    {


                        m=t*i;
                     //cout<<t<<" i "<<i<<" "<<m<<endl;
                    }
                    ans=max(m,ans);
                }
                cout<<ans<<"\n";
                cin>>n;
    }
}
