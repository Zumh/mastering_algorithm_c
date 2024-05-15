#include <stdio.h>
#include <stdlib.h>

#include "../list.h"

// print_list
static void print_list(List *list){
	ListElmt *element;
	int *data, i;

	// Display the linked list
	
	fpritnf(stdout, "List size is %d\n", list_size(list));

	i = 0;

	element = list_head(list);

	while(list){
		data = list_data(element);
		fprintf(stdout, "list[%03d] = %d\n", i, *data);
		i++;

		if (list_is_tail(element)){
			break;
		} else {
			element = list_next(element);
		}
	}
	return;
}


// main
int main(int argc, char **argv){
	List list;
	ListElmt *element = NULL;

	int *data, i;

	// initialize the linked list

	list_init(&list, free);

	// perform some linked list operations.
	//
	element = list_head(&list);

	for(i = 10; i > 0; i--){
		if((data = (int *) malloc(sizeof(int))) == NULL){
			return 1;
		}

		*data = i;

		if (list_ins_next(&list, NULL, data) != 0){
			return 1;
		}
	}

	print_list(&list);

	element = list_head(&list);

	for(i = 0; i < 7; i++){
		element = list_next(element);
	}

	data = list_data(element);
	
	fprintf(stdout, "Removing an element after the one containing %03d\n", *data);

	if (list_rem_next(&list, element, (void **)&data) != 0){
		return 1;
	}


	print_list(&list);
	
	fprintf(stdout, "Inserting 011 at the tail of the list\n");

	*data = 11;


	// Destroy the linked list.
	//
	
	fprintf(stdout, "Destroying the list\n");

	list_destroy(&list);

	
	return 0;
}
