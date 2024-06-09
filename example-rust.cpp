// Minimization test for Hougen-Watson model for reaction kinetics.
// Non-linear least squares problem.

#include <stdio.h>
#include "biteopt.h"

const int N = 5;
double lb[ N ] = { 0.01, 0.01, 0.01, 0.01, 0.01 };
double ub[ N ] = { 2.0, 2.0, 2.0, 2.0, 2.0 };

extern "C" double cost_function( int ND, const double* x, void* data );

int main() {
	double x[ N ];
	double minf;
	int c = biteopt_minimize( N, cost_function, NULL, lb, ub, x, &minf, 20000, 1, 1, 1 );

	printf( "evals_done = %i\n", c );
	printf( "minf = %.10g\n", minf );

	int i;

	for( i = 0; i < N; i++ )
	{
		printf( "x[%i] = %.8g\n", i, x[ i ]);
	}
}
