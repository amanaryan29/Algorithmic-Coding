/*Subham Sanghai*/
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int power(int a,int b)
{

    if(b==0)
        return 1;
    if(b%2==0)
    {

        int s=power(a,b/2)%mod;
        return (s*s)%mod;
    }
    return (a*power(a,b-1))%mod;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;

}
