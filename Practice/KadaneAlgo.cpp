#include <iostream>

using namespace std;

int main() {
	//code
	int t;  cin>>t;
	while(t--)
	{
	    int n;  cin>>n;
	    int max_so_far, max_ending_here;
	    max_so_far = -200; max_ending_here = 0;
	    for(int i = 0; i < n ; i ++)
	    {
	        int temp;
	        cin>>temp;
	        max_ending_here += temp;
	        
	        if(max_ending_here > max_so_far)
	        {
	            max_so_far = max_ending_here;
	        }
	        if(max_ending_here < 0 )    max_ending_here = 0;
	    }
	    cout<<max_so_far<<endl;
	}
	return 0;
}