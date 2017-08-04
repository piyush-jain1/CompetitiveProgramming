#include <iostream>
#include <math.h>
#include <string>
#include  <algorithm>
#include <vector>
#define ll long long
#define mod  1000000007
 
using namespace std;

int main()
{
 	cout<<"Yo"<<endl;

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
 
    cin>>t;
    
    while(t--){
 
 		
        int i,j,n,k,len[2510],count=0;
    
        std::vector<int> a[2510];
        cin>>n>>k;
 
        for(i=0;i<n;i++){
            cin>>len[i];
 
            for(j=0;j<len[i];j++){
            	int temp;
            	cin>>temp;
                a[i].push_back(temp);
            }
 
 
        }
        bool flag[2510];

        for(i=1;i<=k;i++){
            flag[i]=false;
        }
 
        int y=0,z=0,count1=0; 
 
         for(i=0;i<n-1;i++){

   
            for(j=i+1;j<n;j++){


                    if((len[i]+len[j])>=k){
                        

                        for(y=0;y<len[i];y++){
                            flag[a[i][y]]=true;
                        }

                        for(y=0;y<len[j];y++){
                            flag[a[j][y]]=true;
                        }

                        bool modi = true;
                        for(y=1;y<=k;y++){
                            if(flag[y]==false){
                                modi = false;
                                break;
                            }
                        }

                        if(modi){
                            count++;
                        }
                    
                        
                        for(y=1;y<=k;y++){
                            flag[y]=false;
                        }

 
                    }
                }

 
         }
 
        
         cout<<count<<endl;
 
 
    }
 
    return 0;
}
 
