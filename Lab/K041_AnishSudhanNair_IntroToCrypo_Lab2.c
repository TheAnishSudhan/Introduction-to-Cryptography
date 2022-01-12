//Vigenere Cipher
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int findIndex(char n){
  char alphabet[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  for (int i = 0; i < 26; i++) {
    if(n==alphabet[i])
      return i;
  }
  return 0;
}

void encrypt(char pln_txt[1300], char key[10], char alphabet[27])
{
  int key_len=strlen(key)-1; //removing the additional line feed character
    int temp;
    int ab=5;
    char new_txt[1300]="";
    char ch, temp2;

    for (int i=0, j=0;pln_txt[i]!='\n';i++,j++)
    {
      if(j==key_len)
          j=0;
      ch = tolower(pln_txt[i]);
      int posn = findIndex(ch);
      int key_posn = findIndex(key[j]);
      temp = (posn + key_posn)%26;
      if (pln_txt[i]==' ')
        {
          new_txt[i]= ' ';
          continue;
        }
      temp+='a';
      new_txt[i]= temp;
    }
    fflush(stdin);
    printf("The encrypted text is: ");
    printf("%s", new_txt);
}

void decrypt(char enc_txt[1300], char key[10], char alphabet[27])
{
    int key_len=strlen(key)-1; //removing the additional line feed character
    int temp;
    char new_txt[1300]="";
    char ch, temp2;

    for (int i=0,j=0;enc_txt[i]!='\n';i++,j++)
    {
        if(j==key_len)
          j=0;
        ch = tolower(enc_txt[i]);
        int posn = findIndex(ch);
        int key_posn = findIndex(key[j]);
        temp = (posn - key_posn)%26;
        if (temp<0)
          temp= (26 - key_posn + posn);
        if (enc_txt[i]==' ')
        {
            new_txt[i]= ' ';
            continue;
        }
        temp+='a';
        new_txt[i]= temp;
    }
    printf("%c\n", temp);
    printf("\nThe plain text is: ");
    printf("%s", new_txt);
}

int main()
{
    char alphabet[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int n;
    char key[100];
    char pln_txt[1300], enc_txt[1300];

    do{
        printf("\n\nWelcome to lab 2 of intro to crypto, Anish");
        printf("\nChoose one option - \n1. Encryption \n2. Decryption\n");
        scanf("%d", &n);
        while ((getchar()) != '\n');

        switch(n)
        {

            case 1:
            fflush(stdin);
            printf("\nEnter your plaintext: ");
            fgets(pln_txt, sizeof(pln_txt), stdin);
            while ((getchar()) != '\n');
            printf("\nEnter the key: ");
            fgets(key, sizeof(key), stdin);
            while ((getchar()) != '\n');
            encrypt(pln_txt, key, alphabet);
            break;

            case 2:
            printf("\nEnter your cipher text: ");
            fgets(enc_txt, sizeof(enc_txt), stdin);
            while ((getchar()) != '\n');
            printf("\nEnter the key: ");
            fgets(key, sizeof(key), stdin);
            while ((getchar()) != '\n');
            decrypt(enc_txt, key, alphabet);
            break;

            default:
            n=4;
        }
    }while(n!=4);

    return 0;
}
