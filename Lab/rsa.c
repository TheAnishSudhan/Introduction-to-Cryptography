#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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

int eulerFunction(int p, int q){

  int eulerNumber = (p-1)*(q-1);
  return eulerNumber;
}

int gcd(int a, int b){

  int gcdNumber=0;

  for(int i=1; i <= a && i <= b ; i++)
    {
      if(a%i==0 && b%i==0)
        gcdNumber = i;
    }
  // printf("gcd value: %d\n",gcdNumber );
  return gcdNumber;
}

int gcdOne(int a, int b){

  for (int i = 2; i < b; i++) {
    if (gcd(i,b)==1) {
      return i;
    }
  }

  return -1;
}

int relativePrime(int eulerNumber){

  // for (int i = 1; i < eulerNumber; i++) {
  //   if (gcdOne(i, eulerNumber)) {
  //     printf("Value of e: %d\n",i );
  //     return i;
  //   }
  // }

  int value=gcdOne(1,eulerNumber);

  return value;
}

int dGenerator(int e, int eulerNumber){

  for (int i = 0; i < eulerNumber; i++) {
    if ((e*i)%eulerNumber==1) {
      printf("Value of d: %d\n",i );
      return i;
    }
  }

  return -1;
}

int modRecurse(int e, int index, int n){

  if(e%2==0){
    return (modRecurse(e/2,index,n)*modRecurse(e/2, index, n))%n;
  }
  if ((e%2!=0)&&(e!=1)) {
    return (modRecurse(e-1, index,n)*modRecurse(1,index,n))%n;
  }
  if (e==1) {
    int value=pow(index,e);
    value=value%n;
    return value;
  }

  return -1;
}

// int modGenerator(int e, int index, int n){
//
//   int times=e/2;
//   int overflow=e%2;
//
//   //make a recursive function
//
//   int value=modRecurse();
//
//   return -1;
// }

int alphabetIndex(char letter){

  char alphabet[]=("abcdefghijklmnopqrstuvwxyz");
  for (int index = 0; index < 26; index++) {
    if (letter==alphabet[index]) {
      return index;
    }
  }

  return 0;
}

char toAlphabet(int index){

  char alphabet[]=("abcdefghijklmnopqrstuvwxyz");

  char letter = alphabet[index];

  return letter;
}

void encryption(char plainTxt[100], int e, int n){

  int plainTxtIndex[100];


  // printf("Working?2\n");

  for (int i = 0; i < strlen(plainTxt)-1; i++) {
    int index=alphabetIndex(plainTxt[i]);
    printf("Index; %d\n",index );
    plainTxtIndex[i]=modRecurse(e,index,n);
    // plainTxtIndex[i]=(pow(index,e));
    // printf("Power: %d\n", plainTxtIndex[i]);
    // plainTxtIndex[i]=(plainTxtIndex[i])%n;
    printf("%d\t",plainTxtIndex[i]);
  }

  // printf("%s\n", plainTxtIndex);
}

void decryption(int cipherTxt[100], int d, int n, int num){

  int cipherTxtIndex[100];
  char cipherTxtOutput[100];

  for (int i = 0; i < num; i++) {
    // printf("Working?5\n" );
    cipherTxtIndex[i]=modRecurse(d,cipherTxt[i],n);
    // printf("Working?4\n" );
    // cipherTxtIndex[i]=(cipherTxtIndex[i])%n;
    printf("Index: %d\t",cipherTxtIndex[i]);
    char letter=toAlphabet(cipherTxtIndex[i]);
    printf("%c\n", letter);
    cipherTxtOutput[i]=letter;
  }

  cipherTxtOutput[num]='\0';

  printf("%s",cipherTxtOutput);
}

int main() {

  int prime_number_1, prime_number_2, n;
  char plainTxt[100];
  int cipherTxt[100];

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

  int eulerNumber=eulerFunction(prime_number_1, prime_number_2);

  int e=relativePrime(eulerNumber);
  // e=17;

  int d = dGenerator(e, eulerNumber);

  n=(prime_number_1)*(prime_number_2);

  printf("Public Key: (%d,%d)\n",e,n );
  fflush(stdin);

  printf("Enter plain text for encryption: ");
  fgets(plainTxt, sizeof(plainTxt), stdin);
  while ((getchar())!='\n');
  // scanf("%s", &plainTxt[30]);

  fflush(stdin);

  printf("Working?1\n" );

  encryption(plainTxt,e,n);

  // printf("Working?2\n" );

  int number=0;

  printf("Enter no of letters of cipher text for decryption: \n");
  scanf("%d", &number );

  printf("\nEnter cipher text numbers on a new line\n");
  for (int i = 0; i < number; i++) {
    scanf("%d",&cipherTxt[i] );
    printf("\n" );
  }
  // scanf("%d", &cipherTxt[30]);

  decryption(cipherTxt,d,n, number);

  return 0;
}
