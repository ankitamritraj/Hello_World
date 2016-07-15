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
typedef pair<int, int> Pint ;

void Make_Diamond(int index_left, int index_right, int robo[][101], Pint index[][101], int dist[][101], int k, int n, int m)
{
	queue<Pint> Q;
	Pint temp;
	int p=index_left;
	int q=index_right;
	Q.push(index[p][q]);
	int i,j,l,s;
	while(!Q.empty())
	{
		temp=Q.front();
		p=temp.first;
		q=temp.second;
		Q.pop();
		l=0;
		s=k-1;
		for(i=p-k;i<=p+k;i++)
		{
			if(i<=p)
			{
				for(j=q-l;j<=q+l;j++)
				{
					if(i>=1 && i<=n && j>=1 && j<=m && dist[i][j]>dist[p][q]+1 && robo[i][j]==0)   //
					{
						dist[i][j]=dist[p][q]+1;
						Q.push(index[i][j]); 
					}
				}
				l++;
			}
			else
			{
				for(j=q-s;j<=q+s;j++)
				{
					if(i>=1 && i<=n && j>=1 && j<=m && dist[i][j]>dist[p][q]+1 && robo[i][j]==0)  //
					{
						dist[i][j]=dist[p][q]+1;
						Q.push(index[i][j]);
					}					
				}
				s--;
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	lli test;
	cin>>test;
	while(test--)
	{
		int n,m,k1,k2;
		cin>>n>>m>>k1>>k2;
		int robo[101][101];
		int i,j;
		int dist_left[101][101];
		int dist_right[101][101];
		Pint index[101][101];
		f(i,1,n+1)
		{
			f(j,1,m+1)
			{
				cin>>robo[i][j];
				dist_left[i][j]=dist_right[i][j]=INF;
				index[i][j]=mp(i,j);
			}		
		}	
		dist_left[1][1]=dist_right[1][m]=0;
		Make_Diamond(1,1,robo, index, dist_left,k1,n,m);
		Make_Diamond(1,m,robo, index, dist_right,k2,n,m);
		int ans=INF;
		f(i,1,n+1)
			f(j,1,m+1)
				if(robo[i][j]==0)
					ans=min(ans,max(dist_left[i][j],dist_right[i][j]));
			
		if(ans>100000)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}