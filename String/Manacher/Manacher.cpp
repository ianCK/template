pair<vector<int>, vector<int>> Manacher( const string& s )
{
    const string delimiter = "\0";

    int sLen = int( s.length() );

    string t = delimiter;
    for( char c : s ) t += c; t += delimiter;

    int tLen = int( t.length() );

    vector<int> lpsT( tLen ), lpsSOdd( sLen ), lpsSEven( sLen - 1 );

    int l = 0, r = 0;
    for( int i = 1; i < tLen; i++ )
    {
        lpsT[i] = ( r > i ? min( lpsT[2 * l - i], r - i ) : 1 );
        while( i >= lpsT[i] and i + lpsT[i] < tLen and t[i - lpsT[i]] == t[i + lpsT[i]] ) ++lpsT[i];
        if( i + lpsT[i] > r ) r = i + lpsT[i], l = i;
    }

    for( int i = 0; i < sLen; i++ )
    {
        // TODO
        lpsSOdd[i] = lpsT[i * 2 + 1] / 2;
        lpsSEven[i] = lpsT[i * 2] / 2;
    }

    return make_pair( lpsSOdd, lpsSEven );
}
