#include<iostream>

using namespace std;

int main(){
    int capacity ;
    cout<<"Enter capacity of sack";
    cin>>capacity;
    int items;
    cout<<"Enetr number of items:";
    cin>>items;
    int profit[items];
    int wt[items];
    for(int i=0;i<items;i++){
        cout<<"Enter the profit and weight of "<<i+1<<": ";
        cin>>profit[i]>>wt[i];
    }
    
    int dp[items + 1][capacity + 1];
    
    for(int i = 0; i <= items; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                //There's nothing to add to Knapsack
                dp[i][j] = 0;
            }
            else if(wt[i] <= j){
                //Choose previously maximum or value of current item + value of remaining weight
                dp[i][j] = max(dp[i - 1][j], profit[i] + dp[i - 1][j - wt[i]]);
            }
            else{
                //Add previously added item to knapsack
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
	

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";


    cout<<"selected weights are: ";
    int res = dp[items][capacity];
   
     
    int w = capacity;
    for (int i = items; i > 0 && res > 0; i--) {
         
        // either the result comes from the top
        // (K[i-1][w]) or from (val[i-1] + K[i-1]
        // [w-wt[i-1]]) as in Knapsack table. If
        // it comes from the latter one/ it means
        // the item is included.
        if (res == dp[i - 1][w])
            continue;    
        else {
 
            // This item is included.
            cout<<" "<<wt[i - 1] ;
             
            // Since this weight is included its
            // value is deducted
            res = res - profit[i - 1];
            w = w - wt[i - 1];
        }
    }
    return 0;
}

/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/