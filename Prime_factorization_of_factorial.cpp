vector<int> prime;
int primeFactor[SIZE]; ///Size should be as big as N

void factorize( int n ) {
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                primeFactor[ prime[i] ]++; ///Increment global primeFactor array
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 ) {
        primeFactor[n]++;
    }
}

void factFactorize ( int n ) {
    for ( int i = 2; i <= n; i++ ) {
        factorize( i );
    }

    ///Now We can print the factorization
    for ( int i = 0; i < prime.size(); i++ ) {
        printf ( "%d^%d\n", prime[i], primeFactor[ prime[i] ] );
    }
}
