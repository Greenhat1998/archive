#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
std::ifstream correct_in, correct_out, contestant_out;
vector<pii> S;
int n, m, res, ans, d[200005];
vector<int> a[200005];
set<int> b[200005];
void DFS(int s)
{
	for(int i=0;i<a[s].size();i++)
		if (d[a[s][i]]==0)
		{
			d[a[s][i]]=1;
			DFS(a[s][i]);
		}
}

int main(int argc, char *argv[]) {
    correct_in.open(argv[1]);
    correct_out.open(argv[2]);
    contestant_out.open(argv[3]);
	correct_in>>n>>m;
	float score=1.0;
	for(int i=1;i<=m;i++)
	{
		int u, v;
		correct_in>>u>>v;
		b[u].insert(v);
		b[v].insert(u);
	}
	correct_out>>res;
	contestant_out>>ans;
	if (ans!=res)	
	{
		std::cout << 0;
    	std::cerr << "translate:wrong";
		return 0;
	}
	int x, y;
	vector<pair<int,int> > V;
	while (contestant_out>>x>>y)
	{
		if (b[x].find(y)==b[x].end() && b[y].find(x)==b[y].end())
		{
			std::cout << 0;
    		std::cerr << "translate:wrong";
			return 0;
		}
		else V.push_back({x,y});
	}
	if (V.size()!=n-1)
	{
		std::cout <<0;
    	std::cerr << "translate:wrong";
		return 0;
	}
	for(int i=0;i<V.size();i++)
	{
		x=V[i].first;
		y=V[i].second;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	d[1]=1;
	DFS(1);
	for(int i=1;i<=n;i++)
		if (d[i]==0)
		{
			std::cout <<0;
    		std::cerr << "translate:wrong";
			return 0;
		}
	std::cout << score;
    std::cerr << "translate:success";
    return 0;
}
