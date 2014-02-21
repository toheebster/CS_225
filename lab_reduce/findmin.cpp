/**
 * @file findmin.cpp
 * Implementation of the findmin namespace.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#include "findmin.h"

/**
 * Finds the minimum element in a sequence of type T.
 * Assumes a well defined operator< exists for the type T.
 * If the parameter list is empty, it should return a default T.
 *
 * You will need to modify this function to use OpenMP to parallelize the
 * search.
 *
 * @param list The list of type T to find the minimum element in.
 * @return The minimum element in the sequence.
 */
template <class T>
T findmin::minimum( const vector<T> & list ) {
	
	if (list.empty()) return T();
	
	T curMin = list[0];
	#pragma omp parallel
	{	
		T min_local = list[0];
		#pragma omp for
		for (unsigned int i = 0; i < list.size(); i++) {
	
			if (list[i] < curMin) {
			
				min_local = list[i];
		
			}
		}
		
		#pragma omp critical
		if (min_local < curMin) {
			curMin = min_local;
			
		}
	}
	return curMin;
}
