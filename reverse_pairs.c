void merge(long *array, int p, int q, int r, int *cont)
{
    int i, j, k, n1, n2;
    n1 = q-p+1;
    n2 = r-q;
    int L[n1], R[n2];

    j=q+1;
    for (i = p; i <= q; i++)
    {
        while(j<=r && array[i] > (array[j] * 2))
        {
            j++;
        }
        (*cont) = (*cont) + (j-(q+1));
    }

    for (i = 0; i < n1; i++)
    {
        L[i] = array[p + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = array[q + 1 + j];
    }

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(long *array, int p, int r, int *cont)
{
    if (p < r)
    {
        int q = (p + r)/2;
        merge_sort(array, p, q, cont);
        merge_sort(array, q+1, r, cont);
        merge(array, p, q, r, cont);
    }
}

int reversePairs(int* nums, int numsSize){
    long arr_l[numsSize];
    for(int i = 0; i<numsSize; i++)
    {
        arr_l[i] = (long)nums[i];
    }
    int cont = 0;
    merge_sort(arr_l, 0, numsSize-1, &cont);
    return cont;
}

