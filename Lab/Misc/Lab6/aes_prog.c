#include <stdio.h>
#include <aes.h>

int main() {

  int prime_number_1, prime_number_2, n;
  char plainTxt[100];
  char keyTxt[100];
  int cipherTxt[100];

    // do {
    //   printf("Enter prime number 1: ");
    //   scanf("%d",&prime_number_1);
    //
    //   if (!ifPrime(prime_number_1)) {
    //     printf("\nNot a prime number!\n");
    //   }
    // } while(!ifPrime(prime_number_1));
    //
    // do {
    //   printf("Enter prime number 2: ");
    //   scanf("%d",&prime_number_2);
    //
    //   if (!ifPrime(prime_number_2)) {
    //     printf("\nNot a prime number!\n");
    //   }
    // } while(!ifPrime(prime_number_2));

  // int eulerNumber=eulerFunction(prime_number_1, prime_number_2);
  //
  // int e=relativePrime(eulerNumber);
  //
  // int d = dGenerator(e, eulerNumber);
  //
  // n=(prime_number_1)*(prime_number_2);

  // printf("Public Key: (%d,%d)\n",e,n );
  // fflush(stdin);

  printf("Enter plain text for encryption: ");
  fgets(plainTxt, sizeof(plainTxt), stdin);
  while ((getchar())!='\n');

  fflush(stdin);

  printf("Enter key for encryption: ");
  fgets(keyTxt, sizeof(keyTxt), stdin);
  while ((getchar())!='\n');

  fflush(stdin);

  aes_encrypt_cbc(plainTxt,128,)

  //
  // int number=0;
  //
  // printf("\nEnter no of letters of cipher text for decryption: \n");
  // scanf("%d", &number );
  //
  // printf("\nEnter each of the cipher text numbers on new lines\n");
  // for (int i = 0; i < number; i++) {
  //   scanf("%d",&cipherTxt[i] );
  // }

  return 0;
}
