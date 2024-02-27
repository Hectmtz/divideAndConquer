int mySqrt(int x)
{
    int p = 1;
    int q;
    if (x <= 1)
    {
        q = x;
    }
    else
    {
        q = x/2;
    }
    return recursiveSQRT(x, p, q);
}

int recursiveSQRT(int x, int p, int q)
{
    int ans;
    if (p > q)
    {
        return q;
    }

    long m = (p + q)/2;

    if (m * m == x)
    {
        ans = m;
    }
    if (m * m > x)
    {
        return recursiveSQRT(x, p, m-1);
    }
    if (m * m < x)
    {
        return recursiveSQRT(x, m+1, q);
    }
    return ans;
}
