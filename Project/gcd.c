#include <stdio.h>

void main()
{
    int arr1[7],u,v, temp_u1,temp_u2,temp_u3;

    printf("Enter the greater number: ");
    scanf("%d", &u);

    printf("Enter the lesser number: ");
    scanf("%d", &v);

    arr1[0]=1;
    arr1[1]=0;
    arr1[2]=0;
    arr1[3]=1;
    arr1[4]=u;
    arr1[5]=v;
    arr1[6]=0;

    for (int i=0;i<7;i++)
            printf("%d\t", arr1[i]);
        printf("\n");

    while (arr1[5]!=0)
    {
        arr1[6]=arr1[4]/arr1[5];
        temp_u1=arr1[1];
        temp_u2=arr1[3];
        temp_u3=arr1[5];
        arr1[1]=arr1[0]-(arr1[6]*arr1[1]);
        arr1[3]=arr1[2]-(arr1[6]*arr1[3]);
        arr1[5]=arr1[4]-(arr1[6]*arr1[5]);
        arr1[0]=temp_u1;
        arr1[2]=temp_u2;
        arr1[4]=temp_u3;
        for (int i=0;i<7;i++)
            printf("%d\t", arr1[i]);
        printf("\n");
    }



}
