#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool ifPrime(int n){

  int count=0;

  for (int i = 1; i < n; i++) {
    if (n%i==0) {
      count++;
    }
  }

  if (count>1) {
    return false;
  }

  return true;
}

int modValue(int n, int g, int x){

  int value;

  value = pow(g,x);
  value=value%n;

  return value;
}

int keyGenerator(int x, int b, int n){

  int keyValue;

  keyValue = pow(b,x);
  keyValue=keyValue%n;

  return keyValue;
}

int main() {

  int prime_number_1, prime_number_2, bob_number, alice_number, valueA, valueB, keyAlice, keyBob;

    do {
      printf("Enter prime number 1: ");
      scanf("%d",&prime_number_1);

      if (!ifPrime(prime_number_1)) {
        printf("\nNot a prime number!\n");
      }
    } while(!ifPrime(prime_number_1));


    do {
      printf("Enter prime number 2: ");
      scanf("%d",&prime_number_2);

      if (!ifPrime(prime_number_2)) {
        printf("\nNot a prime number!\n");
      }
    } while(!ifPrime(prime_number_2));

  printf("Enter Bob's number: ");
  scanf("%d",&bob_number);

  printf("Enter Alice's number: ");
  scanf("%d",&alice_number);

  valueA=modValue(prime_number_1, prime_number_2, alice_number);
  valueB=modValue(prime_number_1, prime_number_2, bob_number);

  keyAlice=keyGenerator(alice_number, valueB, prime_number_1);
  keyBob=keyGenerator(bob_number, valueA, prime_number_1);

  printf("Alice's Key: %d\n",keyAlice );
  printf("Bob's Key: %d\n",keyBob );

  return 0;
}
