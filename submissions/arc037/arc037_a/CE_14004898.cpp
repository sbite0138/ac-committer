#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  	cin>>n;
  	int ans=0;
  	for (int i=0;i<n;i++){
    	int x;
      	cin>>x;
      	if (x<80){
        	ans+=x-80;
        }
    }
  	cout<<ans<<endl;
  	return 0;
}