// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int minO=0,maxO=0;
        for(char c:s){
            if(c=='('){
                minO++;
                maxO++;
            }
            else if(c==')'){
                minO--;
                maxO--;
            }
            else{
                minO--;
                maxO++;
            }

            if(minO<0)minO=0;
            if(maxO<0)return false;
        }
        return minO==0;
    }
};