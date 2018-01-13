/*Subham Sanghai*/
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n;
long long currency[25][25];
void mult(double  logA[25][25],double logB[25][25],long long modA[25][25],long long modB[25][25])
{
	double logC[n][n];
	long long modC[n][n];
	for(long long i=0;i<n;i++)
	{

		for(long long j=0;j<n;j++)
		{
			double sum=0.0;
			long long pos;
			for(long long k=0;k<n;k++)
			{
				if((logA[i][k]+logB[k][j])>sum)
				{
					sum=(logA[i][k]+logB[k][j]);
					pos=k;
				}
			}
			logC[i][j]=sum;
			modC[i][j]=(modA[i][pos]*modB[pos][j])%mod;
		}
	}
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			logA[i][j]=logC[i][j];
			modA[i][j]=modC[i][j];
			//cout<<modA[i][j]<<" ";
		}
		//cout<<endl;
	}
}
void multiply(double logA[25][25],long long modA[25][25],long long k)
{
	double logB[25][25];
	long long modB[25][25];
	for(long long i=0;i<25;i++)
    {

        for(long long j=0;j<25;j++)
        {

            modB[i][j]=0;
            logB[i][j]=0.0;
        }
    }
	//memset(logB,0.00,sizeof(logB));
	//memset(modA,0,sizeof(modA));
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			if(currency[i][j]!=0)
			{
			logB[i][j]=log(currency[i][j]);
			}
			else
                logB[i][j]=0;
			modB[i][j]=currency[i][j];
		}
	}
	if(k==0 || k==1)
		return ;
	multiply(logA,modA,k/2);
	mult(logA,logA,modA,modA);
	if(k%2!=0)
	mult(logA,logB,modA,modB);

}
int  main()
{

	cin>>n;
	long long x,s,f,m;
	cin>>x>>s>>f>>m;

	double logA[25][25];
	long long modA[25][25];
	for(long long i=0;i<25;i++)
    {

        for(long long j=0;j<25;j++)
        {

            modA[i][j]=0;
            logA[i][j]=0.0;
        }
    }
	for(long long i=0;i<n;i++)
	{
		for(long long j=0;j<n;j++)
		{
			cin>>currency[i][j];
			if(currency[i][j]!=0)
			{
			logA[i][j]=log(currency[i][j]);
			}
			else
                logA[i][j]=0;
			modA[i][j]=currency[i][j];

		}
	}

	multiply(logA,modA,m);
	/*for(long long i=0;i<n;i++)
    {

        for(long long j=0;j<n;j++)
        {

            cout<<modA[i][j]<<" ";
        }
        cout<<endl;
    }*/
	cout<<(x*modA[s][f])%mod<<"\n";

}
