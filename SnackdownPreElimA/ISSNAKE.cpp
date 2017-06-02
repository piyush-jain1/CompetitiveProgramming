#include <bits/stdc++.h>
 
#define ll long long int
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()
 
using namespace std;
///////////////////////////////////////////////////////
 
int t,n;
int grid[5][510];
bool visited[3][510];
map<int,int> M;
 
int degree(int x,int y){
	return grid[x+1][y]+grid[x-1][y] + grid[x][y+1] + grid[x][y-1];
}
 
void flush(){
	FOR(i,0,3){
		FOR(j,0,n+1){
			visited[i][j] = false;
		}
	}
}
 
int traverse(int curr_x,int curr_y){
	
	int curr_cnt = 0;
 
	while(1){
		++curr_cnt;
		visited[curr_x][curr_y] = true;
 
		if(!visited[curr_x+1][curr_y] and grid[curr_x+1][curr_y]){
			curr_x +=1;
			continue;
		}
		if(!visited[curr_x-1][curr_y] and grid[curr_x-1][curr_y]){
			curr_x -=1;
			continue;
		}
 
		if(!visited[curr_x][curr_y+1] and grid[curr_x][curr_y+1]){
			curr_y +=1;
			continue;
		}
 
		if(!visited[curr_x][curr_y-1] and grid[curr_x][curr_y-1]){
			curr_y -=1;
			continue;
		}
		break;
	}
	return curr_cnt;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin>>t;
	while(t--){
		cin>>n;
 
		int cnt=0,col;
		bool second = false;
		bool done = false;
		FOR(i,1,2){
			FOR(j,1,n){
				char tempc; cin>>tempc;
 
				if(tempc=='.') grid[i][j] = 0;
				else grid[i][j] = 1,++cnt;
			
				visited[i][j] = false;
			}
		}
		
		flush();
		FOR(j,0,n+1){
			grid[0][j] = grid[3][j] = 0;
		}
		grid[1][0] = grid[2][0] = grid[1][n+1] = grid[2][n+1] = 0;
 
 
		col = 1;
		while(grid[1][col]==0 and grid[2][col]==0) ++col;
 
		// col;
 
		// DEBUG(col);
 
		if(grid[1][col] and grid[2][col]){
			int curr_cnt1 = traverse(1,col);
			flush();
			int curr_cnt2 = traverse(2,col);
		
			if(curr_cnt2==cnt or curr_cnt1==cnt){
				cout<<"yes"<<endl;
				continue;
			}
		}
		else if(grid[1][col]){
			int curr_cnt = traverse(1,col);
		
			if(curr_cnt==cnt){
				cout<<"yes"<<endl;
				continue;
			}
		}
		else{
			int curr_cnt = traverse(2,col);
		
			if(curr_cnt==cnt){
				cout<<"yes"<<endl;
				continue;
			}
		}
 
		col = n;
		while(grid[1][col]==0 and grid[2][col]==0) --col;
 
 
		// col;
 
		// DEBUG(col);
 
		if(grid[1][col] and grid[2][col]){
			int curr_cnt1 = traverse(1,col);
			flush();
			int curr_cnt2 = traverse(2,col);
		
			if(curr_cnt2==cnt or curr_cnt1==cnt){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}
		else if(grid[1][col]){
			int curr_cnt = traverse(1,col);
		
			if(curr_cnt==cnt){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}
		else{
			int curr_cnt = traverse(2,col);
		
			if(curr_cnt==cnt){
				cout<<"yes"<<endl;
			}
			else{
				cout<<"no"<<endl;
			}
		}
	}
}
 