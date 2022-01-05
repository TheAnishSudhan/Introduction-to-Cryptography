#include <stdio.h>
#include <ctype.h>

int key_check(int key)
{
    return key%26;
}
void encrypt(char pln_txt[100], int key)
{
    if (key>25)
    key_check(key);
    int temp;
    int ab=5;
    char new_txt[100]="";
    char ch, temp2;

    for (int i=0;pln_txt[i]!='\n';i++)
    {
        ch = tolower(pln_txt[i]);
        temp = (ch + key);
        if (temp>122)
            temp-=26;
        if (pln_txt[i]==' ')
        {
            new_txt[i]= ' ';
            continue;
        }
        temp2 = temp;
        new_txt[i]= temp2;
    }
    fflush(stdin);
    printf("The encrypted text is: ");
    printf("%s", new_txt);
}

void decrypt(char enc_txt[100], int key)
{
    if (key>25)
    key_check(key);
    int temp;
    char new_txt[100]="";
    char ch, temp2;

    for (int i=0;enc_txt[i]!='\n';i++)
    {
        ch = tolower(enc_txt[i]);
        temp = (ch - key);
        if (temp<97)
            temp+=26;
        if (enc_txt[i]==' ')
        {
            new_txt[i]= ' ';
            continue;
        }
        temp2 = temp;
        new_txt[i]= temp2;
    }
    fflush(stdin);
    printf("\nThe plain text is: ");
    printf("%s", new_txt);
}

void bruteforce(char enc_txt[100])
{
    for(int i=0;i<26;i++)
    decrypt(enc_txt, i);
}

void main()
{
    char n;
    int key;
    char pln_txt[100], enc_txt[100];

    do{
        printf("\n\nWelcome to lab 1 of intro to crypto, Anish");
        printf("\nPick one of three options - \n1. Encryption \n2. Decryption \n3. Brute force\n");
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
            scanf("%d", &key);
            encrypt(pln_txt, key);
            break;

            case 2:
            printf("\nEnter your encrypted text: ");
            fgets(enc_txt, sizeof(enc_txt), stdin);
            while ((getchar()) != '\n');
            printf("\nEnter the key: ");
            scanf("%d", &key);
            decrypt(enc_txt, key);
            break;

            case 3:
            printf("\nEnter your encrypted text: ");
            fgets(enc_txt, sizeof(enc_txt), stdin);
            bruteforce(enc_txt);
            break;
        }
    }while(n!=4);
}
