#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

bool hasPalindrome1(char *s, bool ignore_space)
{
    if (strlen(s) == 0) {
        return false;
    }
    
    int cc[128]; // ascii, case sensitive
    for (int i=0;i<128;i++) { //init
        cc[i]=0;
    }
    for (int i=0;i<strlen(s);i++){ //count
        cc[s[i]]++;
    }
    bool flag=false;
    for (int i=0; i<128; i++) {
        if (cc[i]==0 || cc[i]%2==0 || (i==32 && ignore_space)) {
            // you can have abscence of character, or even number.
            continue;
        } else if (flag) {
            // flag has already been set, we have an odd number of something already.
            return false;
        } else {
            flag=true;
        }
    }
    return true;
}

void test(char *s) 
{
  if (hasPalindrome1(s, true)) {
      printf("\"%s\" has a palindrome\n", s);
      
  } else {
      printf("\"%s\" has not a palindrome\n", s);
  }    
}

int main() {
  // given  string is there anyway to re-order it so that it
  // is a palindrome - so it has the same read left to right as
  // right to left
  // tact coa => "taco cat", "atco cta", etc
  
  // what about spaces? (added a flag to manage)
  // even number of  each character (except 1)
  char tests[3][100];

  strcpy(tests[0],"tactc oa" );
  strcpy(tests[1],"");
  strcpy(tests[2],"avcdefghijklmnop");

  for (int i=0;i<3; i++)
  {
      test(tests[i]);
  }

  printf("\nPress Return to continue\n");
  getchar();
}
