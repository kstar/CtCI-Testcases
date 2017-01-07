/***************************************************************************
                              prob_02.cpp  -
                             -------------------
    begin                : Mon 10 Oct 2016 01:11:49 CDT
    copyright            : (c) 2016 by Akarsh Simha
    email                : akarsh.simha@kdemail.net
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


/* STL Includes */

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <assert.h>


bool isPermutation( std::string s1, std::string s2 ) {
    // Your code goes here
}

bool isPermutation_nonInPlace( const std::string &s1, const std::string &s2 ) {
    // Your code goes here
}

std::string randomString( int length ) {
    std::string s;
    for ( int i = 0; i < length; ++i )
        s.push_back( rand()%( 'z' - 'a' + 1 ) + 'a' );
    return s;
}

std::string permuteString( std::string s ) {
    // Generate a perfect shuffle, just for fun
    std::string p;
    p.reserve( s.length() );
    while ( !s.empty() ) {
        int x = rand()%( s.length() );
        p.push_back( s[x] );
        std::iter_swap( s.begin() + x, s.end() - 1 );
        s.pop_back();
    }
    return p;
}
int main() {
    const int maxLength = 4096;
    const int testCases = 4096;
    std::srand( std::time( 0 ) );
    for ( int k = 0; k < testCases; ++k ) {
        std::string s1 = randomString( rand()%maxLength + 1 );
        std::string s2;
        bool permute = ( rand()%5 > 4 );
        if ( !permute )
            s2 = randomString( s1.length() - 1 + rand()%3 );
        else
            s2 = permuteString( s1 );

        assert( permute == isPermutation( s1, s2 ) );
        assert( permute == isPermutation_nonInPlace( s1, s2 ) );
    }
    return 0;
}
