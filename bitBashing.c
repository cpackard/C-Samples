#include <stdio.h>
#include <stdlib.h>

int numbah1 = 4;

int isPalindrome (int);

int countBits (int);

int isHighOrderBitSet (char);

void printPrimitiveDataSizes ();

int main (int argc, char* argv[]) {
  if( argc < 2 ) {
    printf( "lolz add more argv's\n" );
  }

  printf( "Arg 0: %s\n", argv[0] );
  printf( "Arg 1: %s\n", argv[1] );

  int inputNum = atoi( argv[1] );

  int result = numbah1<<inputNum;

  printf( "Result of %i<<%i: %i\n\n", numbah1, inputNum, result );

  // Test for isPalindrome:
  int validPal = -1; // all 1's for a 4-byte int
  printf( "Palindrome test for %i:\n", validPal );

  result = isPalindrome( validPal );
  if( result ) printf( "\t%i is a valid palindrome\n\n", validPal );
  else printf( "\t%i is not a valid palindrome\n\n", validPal );

  int bitCount = countBits( validPal );
  // print the number of bits in the result number
  printf( "Number of bits in %i: %i\n\n", validPal, bitCount );

  unsigned char byte = 246;
  printf( "input byte: %i\n", byte );
  result = isHighOrderBitSet( byte );

  if( result ) printf( "High order bit is set for %i\n\n", (int) byte );
  else printf( "High order bit is not set for %i\n\n", byte );
  
  return 0;
}

// Given an input int, determine whether its bit pattern is a palindrome
int isPalindrome (int x) {
  int highBit = 1<<31;
  int lowBit = 1;

  int inputIsPalindrome = 1; // return value
  int leftMost = 0;
  int rightMost = 0;

  int i;

  leftMost = x & highBit;
  rightMost = x & lowBit;

  for( i = 1; i < 16; i++ ) {
    leftMost = x & highBit;
    rightMost = x & lowBit;

    if(   ( leftMost > 0 && rightMost > 0 ) ||
        ( leftMost == 0 && rightMost == 0 ) ||
        ( leftMost < 0 && rightMost > 0 ) ) {
      // move each end towards the middle
      highBit = highBit>>1;
      lowBit = lowBit<<1;
    } else {
      printf( "pair %i didn't match :/\n", i );
      inputIsPalindrome = 0;
      break;
    }
  }

  return inputIsPalindrome;
}


// Given an input int, determine the number of bits in that int
int countBits (int input) {
  // Test: count the number of bits in the result!
  int bitCount = 0;

  if( input > 0 ) {
    // shift the bits left until we discover the first non-zero bit
    while( input > 0 ) {
      bitCount++;
      input = input>>1;
    }
  } else {
    // if the number is negative, all the bits will be used!
    bitCount = sizeof( int ) * 8;
  }

  return bitCount;
}

// Given an input byte( as a char), determine whether the high-order bit is set
// return 1 if high-order bit is set, return 0 otherwise.
int isHighOrderBitSet (char byte) {
  int result = byte & 255; // 255 in binary is 1000 0000
  int hobIsSet = 0;
  
  if( result > 0 ) hobIsSet = 1;

  return hobIsSet;
}

void printPrimitiveDataSizes () {
  // Testing the sizes of primitive data types
  printf( "\n\nPrimitive Data Type Sizes:\n" );
  printf( "\tsize of int: \t%lu\n", sizeof( int ) );
  printf( "\tsize of unsigned int: \t%lu\n", sizeof( unsigned int ) );
  printf( "\tsize of signed int: \t%lu\n", sizeof( signed int ) );
  printf( "\tsize of short int: \t%lu\n", sizeof( short int ) );
  printf( "\tsize of char: \t%lu\n", sizeof( char ) );
  printf( "\tsize of long: \t%lu\n", sizeof( long ) );
  printf( "\tsize of long long: \t%lu\n", sizeof( long long ) );
  
  printf( "\tsize of float: \t%lu\n", sizeof( float ) );
  printf( "\tsize of double: \t%lu\n", sizeof( double ) );
  printf( "\tsize of long double: \t%lu\n", sizeof( long double ) );

  printf( "\tsize of void pointer: \t%lu\n", sizeof( void* ) );
  printf( "\tsize of int pointer: \t%lu\n", sizeof( int* ) );
}
