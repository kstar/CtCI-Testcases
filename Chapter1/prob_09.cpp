/***************************************************************************
                              prob_09.cpp  -
                             -------------------
    begin                : Tue 11 Oct 2016 01:36:29 CDT
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


/* Project Includes */

/* STL Includes */
#include <string>
#include <cstdlib>
#include <ctime>
#include <assert.h>
#include <iostream>

bool isRotation( const std::string &s1, const std::string &s2 ) {
    // Your code goes here
}

// Poor man's Karp-Rabin for isSubstring
bool isSubstring( const std::string &needle, const std::string &haystack ) {
    unsigned short needleHash = 0;

    if ( needle.length() > haystack.length() )
        return false;

    if ( needle.empty() )
        return true; // null string is a subset of every string, including a null string

    for ( char ch : needle )
        needleHash += ch; // Stupid hash that produces collisions for permutations (and a lot more such things), but trivial to implement and roll

    unsigned short haystackHash = 0;
    for ( int i = 0; i < needle.length(); ++i )
        haystackHash += haystack[i];

    for ( int shift = 0; shift <= ( haystack.length() - needle.length() ); ++shift ) {
        if ( haystackHash == needleHash ) {
            // confirm that it is not a collision
            bool match = true;
            for ( int i = 0; i < needle.length(); ++i )
                if ( needle[i] != haystack[ i + shift ] ) {
                    match = false;
                    break;
                }
            if ( match )
                return true;
        }
        if ( shift < haystack.length() - needle.length() )
            haystackHash = haystackHash - haystack[ shift ] + haystack[ shift + needle.length() ];
    }

    return false;
}


std::string randomString( int length ) {
    std::string ret;
    ret.reserve( length );
    for ( int i = 0; i < length; ++i )
        ret.push_back( rand()%( '~' - ' ' + 1 ) + ' ' ); // stick to printable chars
    return ret;
}

std::string randomRotation( const std::string &s ) {
    int rotation = rand()%( s.length() );
    std::string ret( s );
    if ( rotation > 0 ) {
        for ( int i = 0; i < s.length(); ++i )
            ret[( i + rotation )%( s.length() )] = s[i];
    }
    return ret;
}

int main() {
    const int testCases = 4096;
    const int maxLength = 16384;

    std::srand( std::time( 0 ) );

    for ( int k = 0; k < testCases; ++k ) {
        bool rotate = ( rand()%10 > 4 );
        int length = rand()%maxLength + 1;
        std::string s1 = randomString( length );
        std::string s2 = ( rotate ? randomRotation( s1 ) : randomString( length ) );

        /* Human readable tests */
        /*
        std::cout << "String1: " << s1 << "; String2: " << s2 << std::endl;
        std::cout << "Rotated: " << rotate << std::endl;
        */

        /* Machine test */
        assert( rotate == isRotation( s1, s2 ) );

    }
}
