#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char cipher_text[]="XCIUIHTVOQVRLHJEYJXAVICEJFWXRVRUAAEPVPNEQLFZGFQEBXOIUXGIVJXVGLBRBXYIDBFZVKCSGHNITYJBXTSWXZHWZAYSEPINIIZWBRMITIFMQJRKLKASRIMIJPICEMIGGEIINWUTPZWVIFFEDRJXJXEHTISVNGOWRRVLIMZZGWLHZWZKFXHDRRASRXCEKKAOINYJIJLWJPVGGGXMSCSNXVVGTIKLXJXYIAKHVXREKTVZWLPLEERIEJGKGZQVRLBWNSDILBQZWLRSUPZXFVWVSQIIXZXGJRKIFMSAICIUMVJRZGUHQHYEMUTXDSEWXKSHXYILXGCRFPGZCKVFZAWIMIMIFBRMIJTGGWZXFEUHYMXFVVXVJVUYDREPXYSJBDZHNEJKEIXZWKNIYFPEXXHZVRPBNHBIWSJXBVQGPWFEICTSEFYIMTELBSIWJIJOMXIJRGPIIGICHMGZVKEAGGJQDYFBGVXZSFLFTHVJSNPOAZXZMLZOVCFXGZWJEJRXJHVGJRTOXYIUHQHYEMUTXDSEWKHPZPPMFMLZLRRVLSAXYIWGHPWVVLAMNEGTDBINFFXZPLZRKLWWEOEZWAGQJXZSFHZZVVPWVXMSEMUGIOAFVCLSMEKVWLXJRRRWEIXXISFBGYIMMUXMAXYIUHQHYEMUTXDSEWHKSQMUIJBWNIIZWWADXYEOTVMEEXKXIFMEKLASNITSEFYIMTELBSIWKLWIVJZZHWKGVRESLIVJZZHWMLZHRXSUIXELWWBXCEJHWLMBRVHLAIOITLFHPJKPWMVLOLRXAMGVRESLUIVGTIKLIYFPEFRXCMIHHTVOCNIVHRJXYENXEICJMDOIMFLPDXXNEEHLAIYMJGMLWDSEWOBXCMEXZXISITYLBZZFIEFVLVVVWLBPGSEKGBRBAYMDXXCIIIZTWISKCWMFZIEEVXGDWZSFPLZXYIJMSNIVODXKDWCELBSIAVQMLXRSIOOBXCGFRYKINWZRVNWOVPEUTHZQZGKIVDZRGQZVJYGWSGHJXYIJLXJGIEXMEIEGTJHEXLKLSMEYHIIKLINECPGYXCIDYDMMKPVGGFTZXZRYVSIGVVFLXCEKLSOIWIVRLAIASTYKHJNSDYUAHZFRXWUYOAVGSGEGPRKJXIOLRXOXADPCRWXHJRXSAGKCSEIKMEIHZRXHVHIUTMUPDGUITTXZESSMMLJASIKMXJTISLXGOPZFWKXTEEHKXGPVZXQBRWSKLGNVGENWSGHJYIXWVLISCSYR";
// char cipher_text[]="DBMOKWWODJPAOPEPHGQAHWVUJNXDZAIAQMRPNEMHGPERZOVKRVLWUGAEOPXEHMXDVBXDDVKOYQHJJBLWKXIJDVUQDBIPCMAWTBLATKSIZJEYFBSIZBSZVG";
float p[]={0.082,0.015,0.028,0.043,0.127,0.022,0.020,0.061,0.070,0.002,0.008,0.040,0.024,0.067,0.075,0.019,0.001,0.060,0.063,0.091,0.028,0.010,0.023,0.001,0.020,0.001};
char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
float* q[26];
float* Vg[26];
char* stringY[36];
float ioc[100];
float ioc_diff[100];
int keyword[10];

int findIndex(char n){
  for (int i = 0; i < 26; i++) {
    if(n==alphabet[i])
      return i;
  }
  return 0;
}

float IoC(char y_string[1300]){
  int temp[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int b = strlen(y_string);
  int sum=0;

  for (int i = 0; i<b; i++) {
    for (int j = 0; j < 27; j++) {
      if (y_string[i]==alphabet[j]) {
        temp[j]+=1;
      }
    }
  }
  for (int a = 0; a <26; a++) {
  }

  for (int i = 0; i < 26; i++) {
    if (temp[i]>0) {
      sum+=(temp[i]*(temp[i]-1));
    }
  }

  float ioc = (float) sum/(b*(b-1));
  printf("Index of coincidence: %f\n",ioc );
  return ioc;
}


int stringGenerator(int m){
  int key, k=0;
  char string_Y[1300];
  int w=0,z,p,count=0, l;
  for (int a = 1; a <= m; a++) {
    for (int i = 0; i < a; i++) {
      for (int j = i, k = 0; j < strlen(cipher_text); ) {
        string_Y[k]=cipher_text[j];
        j+=a,k++;
        l=k;
      }
      string_Y[l]='\0';
      printf("m=%d String %d \n",a, i+1);
      printf("%s\n",stringY[k]);
      k++;
      ioc[w]=IoC(string_Y);
      w++;
      count++;
    }
  }

  printf("\n\nEnter correct length of keyword to continue : ");
  scanf("%d", &key);
  return key;
}

int main() {
  int m;
  printf("Enter value of m: ");
  scanf("%d",&m);
  printf("\n" );

  int counter=0;
  int num=m;
  while (num!=0) {
    counter=counter+num;
    num--;
  }

  for (int i = 0; i < 36; i++) {
    stringY[i] = malloc(sizeof(char)*1300);
  }

    int z=0;
    for (int a = 1; a <= m; a++) {
      for (int i = 0; i < a; i++) {
        char* p=stringY[z];
        for (int j = i; j < strlen(cipher_text); ) {
          *p=cipher_text[j];
          j+=a,p++;
        }
        *p='\0';
      z++;
      }

    }

  int key=stringGenerator(m);

  counter=0;
  num=key;
  while (num!=0) {
    counter=counter+num;
    num--;
  }

  for (int i = 0; i < key; i++) {
    q[i] = malloc(sizeof(float)*26);
  }

  int string_counter=(counter-key);

  z=0;
  for (int a = 1; a <= key; a++) {
    int temp[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int b = strlen(stringY[string_counter]);
    float* arr=q[z];

    for (int i = 0; i < b; i++) {
      for (int j = 0; j < 27; j++) {
        if(stringY[string_counter][i]==alphabet[j]) {
          temp[j]+=1;
        continue;
      }
    }
  }
  for (int k = 0; k < 26; k++) {
    *arr=(float)temp[k]/b;
    arr++;
  }
    z++;
    string_counter++;
  }

  for (int i = 0; i < key; i++) {
    Vg[i] = malloc(sizeof(float)*26);
  }

  /*
vg  0   1   2   3
g=0 x   y   z   w   -> x = Sum of 26 vals use v_shift, sum it, input in vg
g=1 x   y   z   w
g=2 x   y   z   w
  */

  //creating the table

  z=0;
  int ind=0;
  for (int a = 1; a <= key; a++) {
    float* v=Vg[z];

    for (int g = 0; g < 26; g++) {
      float v_shift[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
      float v_sum=0;
      for (int i = 0; i < 26; i++) {
        v_shift[i]=q[ind][(i+g)%26];
        v_shift[i]=v_shift[i]*p[i];
        // printf("The q index : %d \t", ind );
        // printf("The i val: %d \t",i );
        // printf("The g val: %d \n", g);
        // printf("The index val: %d \t",(i+g) );
        // printf("The q array val: %f \t", q[ind][(i+g)%26]);
        // printf("The prod val: %f\n", v_shift[i]);
      }
      for (int i = 0; i < 26; i++) {
        v_sum+=v_shift[i];
      }
      *v=v_sum;
      v++;
    }
    z++;
    ind++;
  }

  //finding keyword

  for (int i = 0; i < key; i++) {
    // printf("\n\nVg for String %d V\n",i+1);
    float max=Vg[i][0];
    int max_i=0;
    for (int j = 0; j < 26; j++) {
      // printf("%f\n",Vg[i][j]);
      if (Vg[i][j]>max) {
        max=Vg[i][j];
        max_i=j;
      }
    }
    keyword[i]=max_i;
  }

  //print table

  printf("\nTable: \n");

  int index=0;

  printf("g \t Vg1 \t\t Vg2 \t\t Vg3 \t\t Vg4 \t\t Vg5 \t\t Vg6 \t\t Vg7\n" );
  for (int g = 0; g < 26; g++) {
    printf("%d \t %.4f \t %.4f \t %.4f \t %.4f \t %.4f \t %.4f \t %.4f\t\n",g, Vg[index][g],Vg[index+1][g],Vg[index+2][g],Vg[index+3][g],Vg[index+4][g],Vg[index+5][g],Vg[index+6][g]);
  }

  printf("\n\nKeyword: \n" );
  for (int i = 0; i < key; i++) {
    printf("%c", alphabet[keyword[i]]);
  }

  //decryption

      int temp;
      char new_txt[1300]="";
      char ch;

      for (int i=0,j=0;cipher_text[i]!='\0';i++,j++)
      {
          if(j==key)
            j=0;
          ch = cipher_text[i];
          int posn = findIndex(ch);
          int key_posn = keyword[j];
          temp = (posn - key_posn)%26;
          if (temp<0)
            temp= (26 - key_posn + posn);
          temp+='a';
          new_txt[i]= temp;
      }
      printf("\n\nThe plain text is: ");
      printf("%s", new_txt);

  return 0;
}

//strstr
//strchr
//strcspn
