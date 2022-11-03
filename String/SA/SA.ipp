void SA::Build( const vector<int>& s, int kSigma )
{
    const int n = int( s.size() );

}

SA::SA( const vector<int>& s )
{
    int n = int( s.size() );

    int mnElement = min( s );
    int mxElement = max( s );
    int kSigma = mxElement - mnElement + 1;

    vector<int> _s( n + 1 );

    for( int i = 0; i < n; i++ ) _s[i] = s[i] - mnElement + 1;
    _s[n] = 0;

    Build( _s, kSigma + 1 /* 1 is for 0 */ );
}
