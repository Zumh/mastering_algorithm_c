// File parcels.c
//
#include <stdlib.h>
#include <stdio.h>

#include "parcel.h"
#include "parcels.h"
#include "pqueue.h"

// get parcel 
int get_parcel(PQueue *parcels, Parcel *parcel){
	Parcel *data;
	if (pqueue_size(parcels) == 0){
		// Return that there are no parcels
		return -1;
	 } else {
	 	if (pqueue_extract(parcels, (void **) &data) != 0){
			// Return that a parcel could not be retrieved
			return -1;
		} else {
			// Pass back the highest-priority parcel.
			memcpy(parcel, data, sizeof(Parcel));
			free(data);
		}
	 }

	return 0;
}

// put_parcel
int put_parcel(PQueue *parcels, const Parcel *parcel){
	Parcel *data = (Parcel *) malloc(sizeof(Parcel));
	
	// Allocate storage for the parcel
		
	if ( data == NULL){
		// Return that the parcel could not be stored
		return -1;
	}
	// Store the parcel
	memcpy(data, parcel, sizeof(Parcel));
	if (pqueue_insert(parcels, data) != 0){
		// Return that the parcel could not be stored
		return -1;
	}
	return 0;
}
