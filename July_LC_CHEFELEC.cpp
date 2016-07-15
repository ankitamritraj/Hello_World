#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iterator>
#include <stack>
#include <queue>
#include <utility>
using namespace std;
 
#define lli long long int
#define mod 1e9+7
#define f(i,x,n) for(i=x;i<n;i++)
#define vlli vector<lli>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
 
int main()
{
	std::ios_base::sync_with_stdio(false);
	lli test;
	cin>>test;
	while(test--)
	{
		lli n;
		cin>>n;
		lli i;
		bool flag=true;
		string s;
		cin>>s;
		lli a[n+1];
		cin>>a[0];
		lli maxm=0;
		lli ans=0;
		f(i,1,n)
		{
			cin>>a[i];
			if(!(s[i]=='1' && s[i-1]=='1'))
			ans+=a[i]-a[i-1];
			if(s[i-1]=='1' && s[i]=='0' && flag==1)
			{
				maxm=0; flag=0;
			}
			if(flag==0)
			{
				maxm=max(maxm,a[i]-a[i-1]);
			}
			if(s[i-1]=='0' && s[i]=='1' && flag==0)
			{
				flag=1;
				ans-=maxm;
			}
 
			// cout<<"i "<<i<<"  max "<<maxm<<"  ans "<<ans<<endl;;
		}
		cout<<ans<<endl;
	}
	return 0;
} 