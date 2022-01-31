string hexSum(string hexNum){
  int sz = hexNum.length(); // 2
  int carry = 0;
    if(hexNum[sz-1] == 'F'){
      carry = 1;
      hexNum[sz-1] = '0';
    }
    else{
      hexNum[sz-1] += 1;
    }
  for(int i= sz-2; i >=0 && carry; --i){
    if(hexNum[i] == 'F'){
      carry = 1;
      hexNum[i] = '0';
    }
    else{
      hexNum[i] += carry;
      carry = 0;
    }
  }
  if(carry){
    hexNum = "1" + hexNum;
    carry = 0;
  }
  return hexNum;
}


int main(){
  string testNum1 = "FFFF";
  cout << testNum1 +" + 1 = " << hexSum(testNum1) << "\n";
  return 0;
}


======================================Varun's implementation========================================================================
/* Given a hex string, you have to add 1 to the string and return the result */
// 0xAB -> 0xAC

// Brute Force 
1) Convert the string into decimal, add 1 and convert it back to hex and return.

char* addOneToHexVal(char* input)
{
		int len = strlen(input);
    
    // Define your output string. 
    char* output = (char *)malloc(sizeof(output) * (len + 2));
    
    int carry = 1;		
    int in_index = len - 1;
    int out_index = len;
    
    while(in_index >= 0)
    {
    		if(input[in_index] == '9')
        {
        		if(carry == 1)
            {
            		output[out_index] = 'A';
                carry = 0;
            }
            else
            		output[out_index] = input[in_index];
        }
        else if(input[in_index] == 'F')
        {
        		if(carry == 1)
            {
            		output[out_index] = '0'
                carry = 1;
            }
            else
            		output[out_index] = input[in_index];
        }
        else
        {
        		if(carry == 1)
            {
             		output[out_index] = input[in_index] + 1;
                carry = 0;
            }
            else
            		output[out_index] = input[in_index];        
        }
        in_index--;
        out_index--;
    }   
    output[len+2] = '\0';
    
    if(carry == 0)
    	return ouput+1;
    else
    {
    	output[0] = '1';
    	return output;    
    }
}

/*=========================================My another implementation======================================================*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addPlusOne(string s){
    string res;
    if(s.empty()){
        return res;
    }
    int add = 1;
    int carry = 0;
    for(int i= s.length()-1; i >= 0; --i){
        char ch = s[i];
        if(ch == 'f' || ch == 'F'){
            if(carry || add){
                res += 'O';
                carry = 1;
            }
            else{
                res += ch;
            }
        }
        else{
            res += ch + carry + add;
            carry = 0;
        }
        add = 0;
    }
    if(carry){
        res += (carry + '0');
    }
    reverse(begin(res), end(res));
    return res;
}

int main()
{
    string str("ABF");
    cout << addPlusOne(str) << " " << endl;
    return 0;
}


