/***************************************************************************
                              prob_07.cpp  -
                             -------------------
    begin                : Mon 10 Oct 2016 23:27:02 CDT
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
#include <cstdlib>
#include <ctime>
#include <assert.h>

void rotate90( int32_t **mat, int N ) {
}

int main() {
    const int maxSize = 1048;
    const int maxEntry = 1048;
    const int testCases = 1048;

    std::srand( std::time( 0 ) );

    for ( int k = 0; k < testCases; ++k ) {
        int N = rand()%maxSize + 1;
        int32_t **mat = new int32_t*[N];
        int32_t **mat2 = new int32_t*[N];
        for ( int32_t j = 0; j < N; ++j ) {
            mat[j] = new int32_t[N];
            mat2[j] = new int32_t[N];
        }
        for ( int i = 0; i < N; ++i ) {
            for ( int j = 0; j < N; ++j ) {
                mat2[i][j] = mat[i][j] = rand()%( maxEntry + 1 );
            }
        }
        rotate90( mat2, N );

        auto printMatrix = [ N ]( int32_t **mat ) {
            for( int i = 0; i < N; ++i ) {
                for ( int j = 0; j < N; ++j ) {
                    std::cout << mat[i][j] << " ";
                }
                std::cout << std::endl;
            }
        };

        /*
        std::cout << "Original: " << std::endl;
        printMatrix( mat );

        std::cout << "Rotated: " << std::endl;
        printMatrix( mat2 );
        */

        // Verify the result
        for ( int i = 0; i < N; ++i )
            for ( int j = 0; j < N/2; ++j ) {
                assert( mat[i][j] == mat2[j][N - 1 - i] );
                assert( mat[j][N - 1 - i] == mat2[N - 1 - i][N - 1 - j] );
                assert( mat[N - 1 - i][N - 1 - j] == mat2[N - 1 - j][i] );
                assert( mat[N - 1 - j][i] == mat2[i][j] );
            }

        for ( int j = 0; j < N; ++j ) {
            delete[] mat2[j];
            delete[] mat[j];
        }
        delete[] mat2;
        delete[] mat;
    }
}
