int eulerPhi ( int n ) {
    int res = n;
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
            }
            sqrtn = sqrt ( n );
            res /= prime[i];
            res *= prime[i] - 1;
        }
    }
    if ( n != 1 ) {
        res /= n;
        res *= n - 1;
    }
    return res;
}
