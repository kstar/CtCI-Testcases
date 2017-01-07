/***************************************************************************
                              prob_08.cpp  -
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
#include <vector>
#include <cstdlib>
#include <ctime>
#include <assert.h>

void zero( int **mat, int M, int N ) {
    // Your code goes here
}

int main() {
    const int maxSize = 256;
    const int maxEntry = 1024;
    const int testCases = 1024;

    std::srand( std::time( 0 ) );

    for ( int k = 0; k < testCases; ++k ) {
        int M = rand()%maxSize + 1;
        int N = rand()%maxSize + 1;
        int **mat = new int*[M];
        int **mat2 = new int*[M];
        for ( int j = 0; j < M; ++j ) {
            mat[j] = new int[N];
            mat2[j] = new int[N];
        }
        for ( int i = 0; i < M; ++i ) {
            for ( int j = 0; j < N; ++j ) {
                mat2[i][j] = mat[i][j] = rand()%( maxEntry + 1 );
            }
        }
        zero( mat2, M, N );

        auto printMatrix = [ M, N ]( int32_t **mat ) {
            for( int i = 0; i < M; ++i ) {
                for ( int j = 0; j < N; ++j ) {
                    std::cout << mat[i][j] << " ";
                }
                std::cout << std::endl;
            }
        };

        // Verify the result
        for ( int i = 0; i < M; ++i )
            for ( int j = 0; j < N; ++j )
                if ( mat[i][j] == 0 ) {
                    for ( int k = 0; k < N; ++k )
                        assert( mat2[i][k] == 0 );
                    for ( int k = 0; k < M; ++k )
                        assert( mat2[k][j] == 0 );
                }

        for ( int j = 0; j < M; ++j ) {
            delete[] mat2[j];
            delete[] mat[j];
        }
        delete[] mat2;
        delete[] mat;
    }
}
