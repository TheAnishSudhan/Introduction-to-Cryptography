#include <stdio.h>
char plainTxts[6][6]={"100111","000111","001100","011000","001000","011010"};
char cipherTxts[6][6]={"100100","110010","111001","011101","001101","101001"};
char sBoxInput[8][3]={"000","001","010","011","100","101","110","111"};
char sBoxOutput[8][3]={"110","101","001","000","011","010","111","100"};
char inverse[3];
int keyCount[8];

int expressionSummation(int index){

  int sum=0;
  for (int i = 0; i < 6; i++) {
    sum=(((((((plainTxts[index][0]+plainTxts[index][1])%2)+plainTxts[index][3])%2)+plainTxts[index][4])%2)+inverse[0])%2;
    //linear expression derived via manual calculation
  }
  return sum;
}

void inverseCalculator(char value[]){

  for (int i = 0; i < 8; i++) {
    int count=0,outputIndex=0;
    for (int index = 0; index < 3; index++) {
      // printf("Working, Value=%c, So=%c\n", value[0],sBoxOutput[i][index]);
      if (value[index]==sBoxOutput[i][index]) {
        count++;
        outputIndex=i;
        // printf("Running for i=%d\n", i);
      }
    }
    if (count==3) {
      // printf("\nInverse \n:");
      for (int i = 0; i < 3; i++) {
        inverse[i]=sBoxInput[outputIndex][i];
        // printf("%c",inverse[i] );
      }
    }
  }
}

int main(){

  int i=0,counter,sum;

  for (int a1 = 0; a1 <= 1; a1++) {
    for (int a2 = 0; a2 <= 1; a2++) {
      for (int a3 = 0; a3 <= 1; a3++) {

        char key[3]={a1,a2,a3};
        char value[3];
        counter=0,sum=0;
        for (int indexOuter = 0; indexOuter < 6; indexOuter++) {
          for (int indexInner = 0; indexInner < 3; indexInner++) {
            int temp_val=((key[indexInner]+cipherTxts[indexOuter][indexInner])%2);
            value[indexInner]=temp_val+'0';
          }
          inverseCalculator(value);
          sum=expressionSummation(indexOuter);
          if (sum==0) {
            counter++;
          }
        }
        keyCount[i]=counter;
        i++;

      }
    }
  }

  printf("The counter values of all keys: \n");
  for (int i = 0; i < 8; i++) {
    printf("Key %d: %d\n",i+1,keyCount[i]);
  }

  return 0;
}
