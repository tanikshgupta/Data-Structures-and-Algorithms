#include <string>
using namespace std;
string alpha(int n){
  if(n==1||n==0){
    return "";
  }
else  if(n==2){
    return "abc";
  }
  else if(n==3){
    return "def";
  }
  else if(n==4){
    return "ghi";
  }
  else if(n==5){
    return "jkl";
  }
  else if(n==6){
    return "mno";
  }
  else if(n==7){
    return "pqrs";
  }
  else if(n==8){
    return "tuv";
  }else{
    return "wxyz";
  }
}
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
  string newoutput[100000];
  if(num==0){
    output[0]="";
    return 1;
  }
  int smalloutput=keypad(num/10,newoutput);
  int c=num%10;

  string s=alpha(c);
  int k=0;
  for(int i=0;i<smalloutput;i++){
    for(int j=0;j<s.size();j++){
      output[k]= newoutput[i]+s[j];
      k++;
    }

  }
  return k;
}
