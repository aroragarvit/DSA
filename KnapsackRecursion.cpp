
#include <iostream>
using namespace std;
  

int Knapsack( int W[] ,int Val[] , int n , int w )
{
    if (n==0 || w==0)
        {return 0;}

    if (W[n-1] > w){
        return Knapsack(W,Val,n-1,w);
    }
    else{
        return max(Val[n-1]+Knapsack(W,Val,n-1,w-W[n-1]),Knapsack(W,Val,n-1,w));    // if weight is greater then are we not ignoring it and we are taking it or not taking  that case
    }
}


  
int main()
{
    
  
    int n,w;
    cin>>n>>w;
    int W[n],Val[n];
    for(int i=0;i<n;i++){
        cin>>W[i]>>Val[i];
    }
    cout<<Knapsack(W,Val,n,w);
    return 0;
}