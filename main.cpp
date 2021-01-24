#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;

string CodelandUsernameValidation(string str) {

  bool cond1, cond2, cond3, cond4;
  int strLength = str.length();

  //changes everything to lowercase
  for_each(str.begin(), str.end(), [](char & c) {
    c = ::tolower(c);
  });

  //checks conditions
  if(strLength >= 4 && strLength <= 25) {
    cond1 = true;
  }
  for(char c = 'a'; c <= 'z'; c++) {
    if(str[0] == c)
      cond2 = true;
  }
  for(int i = 0; i < str.length(); i++) {
    for(char c = 'a'; c <= 'z'; c++) {
      if(str[0] == c) {
        if((str[0] <= 0 && str[0] >= 9) && (str[strLength-1] != '_')) {
          cond3 = true;
        }
      }
    }
  }
  
  if(cond1 && cond2 && cond3 && cond4) {
    str = "true";
  }
  else {
    str = "false";
  }

  return str;
}

string BracketMatcher(string str) {
  int countOpen = 0;
  int countClose = 0;
  for(int i = 0; i < str.length(); i++) {
    if(str[i] == '(') {
      countOpen++;
    }
    else if(str[i] == ')') {
      countClose++;
    }
  }

  if(countOpen == countClose) {
    str = '1';
  }
  else {
    str = '0';
  }
  return str;
}

string TreeConstructor(string strArr[], int arrLength) {

  bool validParent, validChild;
  string result;

  string parentArray[arrLength];
  for(int i = 0; i < arrLength; i++) {
    for(int j = 0; j < strArr[i].length(); j++) {
      parentArray[i] = strArr[i][3];
    }
  }
  map<string, int> parentDict;
  for(int i = 0; i < arrLength; i++) {
    parentDict.insert({parentArray[i], 0});
  }
  for(auto itr = parentDict.begin(); itr != parentDict.end(); itr++) {
    for(int i = 0; i < arrLength; i++) {
      if(itr->first == parentArray[i]) {
        itr->second++;
      }
    }
  }

  for(auto itr = parentDict.begin(); itr != parentDict.end(); itr++) {
    if(itr->second <= 2) {
      validParent = true;
    }
    else {
      validParent = false;
    }
  }

  string childrenArray[arrLength];
  for(int i = 0; i < arrLength; i++) {
    for(int j = 0; j < strArr[i].length(); j++) {
      childrenArray[i] = strArr[i][1];
    }
  }
  map<string, int> childDict;
  for(int i = 0; i < arrLength; i++) {
    childDict.insert({childrenArray[i], 0});
  }
  for(auto itr = childDict.begin(); itr != childDict.end(); itr++) {
    for(int i = 0; i < arrLength; i++) {
      if(itr->first == childrenArray[i]) {
        itr->second++;
      }
    }
  }
  for(auto itr = childDict.begin(); itr != childDict.end(); itr++) {
    if(itr->second == 1) {
      validChild = true;
    }
    else {
      validChild = false;
    }
  }

  if(validParent && validChild) {
    result = "true";
  }
  else {
    result = "false";
  }

  return result;
}

string FirstReverse(string str) {
  
  //have to use a string since that is the return type
  string res = "";
  for(int i = str.length()-1; i >= 0; i--) {
    res = res+ str[i];
  }
  return res;
}

int main(void) {


  cout << FirstReverse("Argument goes here");
  cout << endl;

  /*
  int size = 5;
  string ex1[] = {"(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"};
  int arrLength1 = sizeof(ex1) / sizeof(*ex1);
  cout << "Output: " << TreeConstructor(ex1, arrLength1);
  cout << endl;
  string ex2[] = {"(1,2)", "(3,2)", "(2,12)", "(5,2)"};
  int arrLength2 = sizeof(ex2) / sizeof(*ex2);
  cout << "Output: " << TreeConstructor(ex2, arrLength2);
  */

  /*
  cout << BracketMatcher("(coder)(byte)");
  cout << endl;
  cout << BracketMatcher("(c(oder)) b(yte)");
  cout << endl;
  */
   
  /*
  // keep this function call here
  cout << CodelandUsernameValidation("Argument goes here");
  cout << endl;
  cout << CodelandUsernameValidation("u__hello_world123");
  cout << endl;
  cout << CodelandUsernameValidation("aa_");
  return 0;
  */
    
}
