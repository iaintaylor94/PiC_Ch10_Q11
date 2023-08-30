// Program to convert a string to its integer equivalent

#include <stdio.h>
#include <stdbool.h>

// Declare Functions
bool isMinus (char);
int positiveStringToInt (char []);
int stringToInt (const char []);

int main(void) {

  // Testing positive numbers
  printf ("Positive numbers\n");
  printf ("%d\n", positiveStringToInt("245"));
  printf ("%d\n", stringToInt("100") + 25);
  printf ("%d\n", stringToInt("13x5"));

  // Testing negative numbers
  printf ("Negative numbers\n");
  printf ("%d\n", stringToInt("-245"));
  printf ("%d\n", stringToInt("-100") + 25);
  printf ("%d\n", stringToInt("-13x5"));
  
  return 0;
}

// Define Functions
bool isMinus (char c) {
  if (c == '-')
    return true;
  else
    return false;
}

int positiveStringToInt (char string[]) {
  int i, intValue, result = 0;

  for (i = 0; string[i] >= '0' && string[i] <= '9'; i++) {
    intValue = string[i] - '0';
    result = result * 10 + intValue;
  }

  return result;
}

int stringToInt (const char string[]) {
  int result = 0;
  int minus = isMinus(string[0]);
  char localString [strlen(string)];
  strcpy (localString, string);

  if (minus)
    localString[0] = '0';

  result = positiveStringToInt (localString);

  if (minus)
    result *= -1;

  return result;
}