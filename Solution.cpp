#include<bits/stdc++.h>
using namespace std;

//Solution class contains solution to given problem
class Solution{
    
private:

    //string of sequence of brackets
    string sequence;
    
	//private method of class for checking if given bracket is opening bracket
	bool isOpeningBracket(char bracket){
		if(bracket=='(' || bracket=='[' || bracket=='{'){
			return true;
		}
		else{
			return false;
		}
	}
 	
	//private method of class for checking if given bracket is closing bracket
	bool isClosingBracket(char bracket){
		if(bracket==')' || bracket==']' || bracket=='}'){
			return true;
		}
		else{
			return false;
		}
	}
 
 	//private method of class for checking if given two brackets are pair 
 	//of opening-closing bracket of same type
	bool isPair(char bracket1, char bracket2){
		if(bracket1=='(' && bracket2==')'){
			return true;
		}
		else if(bracket1=='[' && bracket2==']'){
			return true;
		}
		else if(bracket1=='{' && bracket2=='}'){
			return true;
		}
		else{
			return false;
		}
	}
	
public:

	//public constructor of class
	Solution(string seq){
	    sequence=seq;
	}

	//public method of class for checking if given sequence of brackets is balanced 
	bool isBalancedSequence(){
		//use stack data structure to solve this problem
		stack<char>stk;
		for(int i=0; i<sequence.length(); i++){
			//insert all brackets into the stack if its opening bracket
			if(isOpeningBracket(sequence[i])){
				stk.push(sequence[i]);
			}
			else if(isClosingBracket(sequence[i])){
				/** if its a closing bracket then check top of stack
					if it forms pair with closing bracket then pop it
					otherwise insert the bracket into the stack
					**/
				if(!stk.empty()){
					if(isPair(stk.top(),sequence[i])){
						stk.pop();
					}
					else{
						stk.push(sequence[i]);
					}
				}
				else{
					stk.push(sequence[i]);
				}
			}
			else{
				stk.push(sequence[i]);
			}
		}
		/** check if at the end all opened brackets are closed 
		    and stack is empty then sequence was balanced
		    **/
		return stk.empty();
	}
};

//main method contains input output processing in problem
int main(){
	//read testcases
	int testCases;
	cin>>testCases;
	while(testCases--){
		//read sequence of brackets as string
		string sequence;
		cin>>sequence;
		//solve the problem and give output
		Solution sol=Solution(sequence);
		bool ans=sol.isBalancedSequence();
		if(ans){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}