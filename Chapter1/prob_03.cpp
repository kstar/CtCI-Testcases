/***************************************************************************
                              prob_03.cpp  -
                             -------------------
    begin                : Mon 10 Oct 2016 03:05:47 CDT
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
#include <iostream>

void urlify( char *str, const int N ) {
}

int main() {
    std::string s;
    std::getline( std::cin, s );
    char *str = new char[s.length() + 1024];
    std::copy( s.begin(), s.end(), str );
    str[ s.length() ] = '\0';

    urlify( str, s.length() );

    std::cout << str << std::endl;
    delete[] str;
}
