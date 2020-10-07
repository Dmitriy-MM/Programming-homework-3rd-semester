#include "sorts.h"

static void merge (Student arrA[], int nA, Student arrB[], int nB, Student arrC[])
{
    int i, j, k;
   
    i = j = k = 0;
    while ((i < nA) && (j < nB))
    {
        if(arrA[i] < arrB[j])
        {
            arrC[k] = arrA[i];
            i++;
        }
        else
        {
            arrC[k] = arrB[j];
            j++;
        }
        k = i + j;
    }
    while(i < nA)
    {
        arrC[k] = arrA[i];
        k++;
        i++;
    }
    while(j < nB)
    {
        arrC[k] = arrB[j];
        k++;
        j++;
    }
}

void sort08 (Student arrA[], Student arrB[], int n)
{
    int i, parity; //Parity - с англ. "четность".
    int offset;
    
    i = 1;
    parity = 1;
    while (i < n)
    {
        if (parity)
        {
            for (offset = 0; offset <= n-2*i; offset += 2*i)
            {
                merge(arrA+offset, i, arrA+i+offset, i, arrB+offset);
            }
            if (offset + i <= n)
            {
				merge(arrA+offset, i, arrA+i+offset, (n-offset-i), arrB+offset);
            }
            parity = 0;
        }
        else
        {
            for (offset = 0; offset <= n-2*i; offset += 2*i)
                merge(arrB+offset, i, arrB+i+offset, i, arrA+offset);
            if (offset + i <= n)
            {
				merge(arrB+offset, i, arrB+i+offset, (n-offset-i), arrA+offset);
            }
            parity = 1;
        }
        i *= 2;
    }
    
    if(!parity)
    {
        for (i = 0; i < n; i++)
        {
            arrA[i] = arrB[i];
        }
    }
}