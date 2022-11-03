#pragma once

#include <CommonInclude/CommonInclude.h>

// sa[i]: sa[i]-th suffix is the i-th lexigraphically smallest suffix. 
// rnk[i]: i-th suffix is the rnk[i]-th lexigraphically smallest suffix.
// hi[i]: longest common prefix of suffix sa[i] and suffix sa[i - 1].

class SA
{
    public:
        SA( const vector<int>& s );

        int GetSa( int idx ) const;
        int GetRnk( int idx ) const;
        int GetHi( int idx ) const;

    private:
        vector<int> sa;
        vector<int> rnk;
        vector<int> hi;
};

#include <String/SA/SA.ipp>
