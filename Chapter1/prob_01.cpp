/***************************************************************************
                              prob_01.cpp  -
                             -------------------
    begin                : Sat 07 Jan 2017 01:13:53 PST
    copyright            : (c) 2017 by Akarsh Simha
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
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <assert.h>
#include <utility>
#include <algorithm>

bool isUnique( const std::string &s ) {
    // Your code goes here
}

bool isUnique_inplace( std::string s ) {
    // Your code goes here
}

std::string makeTestCase( const bool unique, const int length ) {
    assert( length > 0 );
    std::string testCase( length, ' ' );
    const int numPrintableChars = 96;
    if ( length == 1 ) {
        assert( unique );
        testCase[0] = rand()%numPrintableChars + ' ';
        return testCase;
    }
    if ( unique ) {
        // Make a unique string using Knuth shuffle of a bank of printable ascii characters
        std::vector<char> bank( numPrintableChars );
        std::iota( bank.begin(), bank.end(), ' ' ); // 32 = ' ' is the first printable ASCII character

        assert( length <= numPrintableChars );
        for ( int k = 0; k < length; ++k ) {
            std::swap( bank[ k + rand()%( numPrintableChars - k ) ],  bank[k] );
            testCase[k] = bank[k];
        }
    }
    else {
        // Make a non-unique string by creating at least one non-uniqueness and then randomly assigning the remaining
        char ch = rand()%numPrintableChars + ' ';
        int i = rand()%length, j = rand()%length;
        while ( j == i )
            j = rand()%length;
        testCase[i] = testCase[j] = ch;
        for ( int k = 0; k < length; ++k ) {
            if ( k == i || k == j )
                continue;
            testCase[k] = rand()%numPrintableChars + ' ';
        }
    }
    return testCase;
}

int main() {
    const int testCases = 4096;
    const int maxLength = 96;

    std::srand( std::time( 0 ) );

    isUnique( std::string() );
    isUnique_inplace( std::string() );

    for ( int k = 0; k < testCases; ++k ) {
        int N = rand()%maxLength + 1;
        bool unique =  rand()%2 || N == 1;
        const std::string testCase = makeTestCase( unique, N );
        assert( isUnique_inplace( testCase ) == unique );
        assert( isUnique( testCase ) == unique );
    }
}
