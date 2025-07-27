// Question: Whenever next is called, a new insertion of stock price made to the input array. 
//           And in response we need to return the span of current input price.
//           Span is the no of time in the input array the price was <= current price (starting from currect price and going continuously back)
//           Example : [1,4,2,1,1] and current price is 3 => Span len([2,1,1]) => 3

// https://leetcode.com/problems/online-stock-span/description/

// Time: O(n) [No of times next is called and input is ingested] + O(n) [Emptying the stack] => O(2n)
// Space: O(2n) [Stack of pairs space]

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 1;
        while(!st.empty() && st.top().first <= price){
            count += st.top().second;
            st.pop();
        }

        st.push({price, count});
        return count;
    }
};

int main(){
    
    return 0;
}