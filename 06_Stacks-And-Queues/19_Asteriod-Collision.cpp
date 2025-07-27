// Question: Given an array of asteroids. 
//           The value represents the size of asteroid.
//           The sign represents the direction of asteroid.
//           The index represents the position of asteroid.
//           Assuming, each asteroid has same constant speed.
//           If two asteroids collide, only the larger one remains.
//           Unless both are of same size, then both get destroid.
//           Answer: Find the remaining array of asteroids.
// https://leetcode.com/problems/asteroid-collision/description/


// Optimal: Don't use a stack, use a vector. So you dont have to reverse the items in the stack to return the answer.
// Example Cases :-
// [10, 2, -5, -2, 7, -8, 15] -> [10, 15]
// [-2, -2, 1, 1]             -> [-2, -2, 1, 1]
// [8, -8]                    -> []

#include <bits/stdc++.h>
using namespace std;

bool isColliding(int num1, int num2){
    return (num1 > 0 && num2 < 0);
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    int n = asteroids.size();

    for(int i=0; i<n; ++i){
        while(!st.empty() && isColliding(st.top(), asteroids[i]) && st.top() < abs(asteroids[i])){
            st.pop();
        }
        if(!st.empty() && isColliding(st.top(), asteroids[i]) && st.top() == abs(asteroids[i])){
            st.pop();
        } else if(st.empty() || !isColliding(st.top(), asteroids[i])) {
            st.push(asteroids[i]);
        }
    }

    vector<int> ans(st.size());
    int i=st.size()-1;
    while(!st.empty()){
        ans[i] = st.top();
        st.pop();
        --i;
    }
    
    return ans;
}

int main(){
    
    return 0;
}