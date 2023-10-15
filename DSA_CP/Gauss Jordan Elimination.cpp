/*
The Gauss-Jordan method, also known as Gauss-Jordan elimination method is used to solve a system of linear equations and is a modified version of Gauss Elimination Method.

It is similar and simpler than Gauss Elimination Method as we have to perform 2 different process in Gauss Elimination Method i.e. 

    Formation of upper triangular matrix, and 
    Back substitution

But in case of Gauss-Jordan Elimination Method, we only have to form a reduced row echelon form (diagonal matrix)
*/
int gauss (vector < bitset<N> > a, int n, int m, bitset<N> & ans) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
        // The rest of implementation is the same as above
}
