#include <iostream>
using namespace std;

void rabbit(int x,int y,int a,int b){

    int count=0;
    //int ans=0;
    for(int i=x,j=y;i<=y && j>=x;i+a,j-b){
        cout<<i;
        // if(i==j){
        //     ans=count;
        // }
        count++;
   
        
    }
    //  if(ans==0){
    //      return -1;
    //  } 
    //  else{
    //      return ans;
    //  }  
    
    
    
}
int main() {
    int x,y,a,b;
    cin>>x>>y>>a>>b;
    rabbit(x,y,a,b);
}
