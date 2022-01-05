//Vigenere Cipher
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int key_check(int key)
{
    return key%26;
}

int findIndex(char n){
  char alphabet[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  for (int i = 0; i < 26; i++) {
    if(n==alphabet[i])
      return i;
  }

}
void encrypt(char pln_txt[100], char key[10], char alphabet[27])
{
  int key_len=strlen(key)-1; //removing the additional line feed character
  printf("%c key len\n", key[6] );
    int temp;
    int ab=5;
    char new_txt[100]="";
    char ch, temp2;

    for (int i=0, j=0;pln_txt[i]!='\n';i++,j++)
    {
      printf("J length %d  ", j );
      if(j==key_len)
          j=0;
      ch = tolower(pln_txt[i]);
      int posn = findIndex(ch);
      //strchr(alphabet, ch);
      int key_posn = findIndex(key[j]);
      //strchr(alphabet, key[j]);
      printf(" posn %d  ", posn);
      printf("key %d  ", key_posn);
      temp = (posn + key_posn)%26;
      // if (temp>122)
      //     temp-=26;
      printf("%d \n ", temp);
      if (pln_txt[i]==' ')
        {
          new_txt[i]= ' ';
          continue;
        }
      temp+='a';
      printf("%c\n", temp);
      new_txt[i]= temp;
    }
    fflush(stdin);
    printf("The encrypted text is: ");
    printf("%s", new_txt);
}

void decrypt(char enc_txt[100], char key[10], char alphabet[27])
{
    int key_len=strlen(key)-1; //removing the additional line feed character
    int temp;
    char new_txt[100]="";
    char ch, temp2;

    for (int i=0,j=0;enc_txt[i]!='\n';i++,j++)
    {
        if(j==key_len)
          j=0;
        ch = tolower(enc_txt[i]);
        int posn = findIndex(ch);
        int key_posn = findIndex(key[j]);
        printf(" posn %d  ", posn);
        printf("key %d  ", key_posn);
        temp = (posn - key_posn)%26;
        if (temp<0)
          temp= (26 - key_posn + posn);
        // if (temp<97)
        //     temp+=26;
        if (enc_txt[i]==' ')
        {
            new_txt[i]= ' ';
            continue;
        }
        printf("%d\n", temp);
        temp+='a';
        new_txt[i]= temp;
    }
    printf("%c\n", temp);
  //  fflush(stdin);
    printf("\nThe plain text is: ");
    printf("%s", new_txt);
}

void main()
{
    char alphabet[27] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char n;
    char key[100];
    char pln_txt[100], enc_txt[100];

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
}
