template <typename T>
BIT<T>::BIT() : m_size( 0 ), m_sum( 0 ) {}

template <typename T>
BIT<T>::BIT( int n ) : m_size( n ), m_sum( 0 ), m_val( vector<T>( n + 1 ) ) {}

template <typename T>
int  BIT<T>::Size() const { return m_size; }

template <typename T>
T    BIT<T>::Sum() const { return m_sum; }

template <typename T>
void BIT<T>::Init( int n )
{
    m_size = n;
    m_sum = 0;
    m_val = vector<T>( n + 1 );

    return ;
}

template <typename T>
void BIT<T>::Add( int pos, T x )
{
    for( int i = pos; i <= m_size; i += i & -i ) m_val[i] += x;

    return ;
}

template <typename T>
T    BIT<T>::Ask( int pos ) const
{
    T ans = 0;
    for( int i = pos; i; i ^= i & -i ) ans += m_val[i];
    return ans;
}

template <typename T>
T    BIT<T>::Ask( int l, int r ) const { return Ask( r ) - Ask( l - 1 ); }

// TODO
// LowerBound
// UpperBound
// Clear
