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
