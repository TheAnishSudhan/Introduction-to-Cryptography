#include <stdio.h>

int main()
{

  int x[]={94,95,96,93,87,79,73,69,68,67};
  int f[]={78,82,83,89,95,103,108,117,130,97};

  int sum1=0, sum2=0;

  for (int i = 0; i < 10; i++) {
    sum1+=(x[i]*f[i]);
    sum2+=f[i];

    /* code */
  }

  printf("fx: %d, f; %d, ans: %f", sum1, sum2, ((float)sum1/(float)sum2));
  return 0;
}
