#include "Password.h"
#include <string>
#include <cctype>
using std::string;


/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

  /*
  returns whether the phrase has both at least one upper-case letter and
  at least one lower-case letter
  */
  
  bool Password::has_mixed_case(string phrase){
    if (phrase.length() >= 2){
      int index = 0;
      while( index < phrase.length()-1){
        if ((isupper(phrase[index]) && islower(phrase[index + 1])) 
          || 
          (isupper(phrase[index + 1]) && islower(phrase[index])) ){
          return true;
        }
        index++;
      }
    }
    return false;
  }

  /*
  constructor sets the default password to "ChicoCA-95929"
  */
  Password::Password(){
    set("ChicoCA-95929");
    return;
  }

  /*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
  void Password::set(string phrase){
    if (phrase.length() >= 8 && 
        count_leading_characters(phrase) < 3 &&
        has_mixed_case(phrase)){
        for(int i = 0; i < Password::pass_history.size(); i++){
          if (Password::pass_history[i] == phrase){
            return;
          }
        }
        Password::pass_history.push_back(phrase);
    }
  }

  /*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
  bool Password::authenticate(string phrase){
    if (phrase == Password::pass_history.back()){
      return true;
    }
    else{
      return false;
    }
  }