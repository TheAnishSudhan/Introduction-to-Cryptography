#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool ifPrime(){

  return true; //Ideally false
}

int modValue(int n, int g, int x){

  int value;

  value = pow(g,x);
  value=value%n;
  printf("%d",value );
  printf("GAPPPs\n" );
  printf("%d",27%7 );

  return value;
}

int main() {

  int prime_number_1, prime_number_2, bob_number, alice_number, valueA, valueB;


  // while (ifPrime) {
  //   printf("Enter prime number 1: ");
  //   scanf("%d",&prime_number_1);
  //
  //   printf("Enter prime number 2: ");
  //   scanf("%d",&prime_number_2);
  // }

    printf("%d",27%2 );

  printf("Enter prime number 1: ");
  scanf("%d",&prime_number_1);

  printf("Enter prime number 2: ");
  scanf("%d",&prime_number_2);

  printf("Enter Bob's number: ");
  scanf("%d",&bob_number);

  printf("Enter Alice's number: ");
  scanf("%d",&alice_number);

  valueA=modValue(prime_number_1, prime_number_2, bob_number);
  valueB=modValue(prime_number_1, prime_number_2, alice_number);

  return 0;
}
