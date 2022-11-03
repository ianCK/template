#pragma once

#include <CommonInclude/CommonInclude.h>

template <typename T>
class BIT
{
    public:

        BIT();
        BIT( int n );

        int  Size() const;
        T    Sum() const;

        void Init( int n );
        // void Init( int n, T* a );

        void Add( int pos, T x );
        T    Ask( int pos ) const;
        T    Ask( int l, int r ) const;

        int  LowerBound( T x ) const;
        int  UpperBound( T x ) const;

        void Clear();

    private:

        int       m_size;
        T         m_sum;
        vector<T> m_val;
};

#include <DS/BIT/BIT.ipp>
