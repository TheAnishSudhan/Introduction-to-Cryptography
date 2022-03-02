#include <stdio.h>
int x1[8]={0,0,0,0,1,1,1,1};
int x2[8]={0,0,1,1,0,0,1,1};
int x3[8]={0,1,0,1,0,1,0,1};
int y1[8]={1,1,0,0,0,0,1,1};
int y2[8]={1,0,0,0,1,1,1,0};
int y3[8]={0,1,1,0,1,0,1,0};
int inputRows[8][3]={{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
int outputRows[8][3]={{1,1,0},{1,0,1},{0,0,1},{0,0,0},{0,1,1},{0,1,0},{1,1,1},{1,0,0}};
int inputModAdds[8];
int outputModAdds[8];

int modCalculator(int positions[3], int row[8][3], int rowNum){

  int value=0;

  for (int i = 0; i < 3; i++) {
    if (positions[i]>=0) {
      value=(value+row[rowNum][i])%2;
    }
  }

  return value;
}

int biasCalculator(int a1, int a2, int a3, int b1, int b2, int b3){

  int count=0;
  int positionsNumerator[3]={a1,a2,a3};
  int positionsDenominator[3]={b1,b2,b3};

  for (int i = 0; i < 3; i++) {
    if (positionsNumerator[i]==0) {
      positionsNumerator[i]=-1;
    }
    if (positionsDenominator[i]==0) {
       positionsDenominator[i]=-1;
    }
  }

  for (int i = 0; i < 8; i++) {
    inputModAdds[i]=modCalculator(positionsNumerator,inputRows, i); //i is row number
    outputModAdds[i]=modCalculator(positionsDenominator,outputRows, i); //i is row number
    if (inputModAdds[i]==outputModAdds[i]) {
      count++;
    }
  }

  int bias;
  bias = count-4;
  return bias;
}

int main() {

  int c1[8],c2[8],c3[8],c4[8],c5[8],c6[8],c7[8],c8[8];

  printf("Input and Output: \n");
  printf("----------------------------------------------------------\n" );
  printf("x1\tx2\tx3\ty1\ty2\ty3\n");
  printf("----------------------------------------------------------\n" );
  for (int i = 0; i < 8; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",x1[i],x2[i],x3[i],y1[i],y2[i],y3[i]);
  }
  printf("----------------------------------------------------------\n" );
  printf("LINEAR APPROXIMATION OF BIAS TABLE\n" );

  int i=0;
  printf("----------------------------------------------------------\n" );
  printf("|X|0\t1\t2\t3\t4\t5\t6\t7\n");
  printf("----------------------------------------------------------\n" );

  for (int a1 = 0; a1 <= 1; a1++) {
    for (int a2 = 0; a2 <= 1; a2++) {
      for (int a3 = 0; a3 <= 1; a3++) {
        c1[i]=biasCalculator(a1,a2,a3,0,0,0);
        c2[i]=biasCalculator(a1,a2,a3,0,0,1);
        c3[i]=biasCalculator(a1,a2,a3,0,1,0);
        c4[i]=biasCalculator(a1,a2,a3,0,1,1);
        c5[i]=biasCalculator(a1,a2,a3,1,0,0);
        c6[i]=biasCalculator(a1,a2,a3,1,0,1);
        c7[i]=biasCalculator(a1,a2,a3,1,1,0);
        c8[i]=biasCalculator(a1,a2,a3,1,1,1);

        printf("|%d|%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,c1[i],c2[i],c3[i],c4[i],c5[i],c6[i],c7[i],c8[i]);
        i++;

      }
    }
  }
  printf("----------------------------------------------------------\n" );


  return 0;
}
