#include <stdio.h>
#include <stdlib.h>
#include "events.h"

// Function to dispatch the event (for demonstration purposes)
int dispatch_event(Event *event) {
	printf("Event received with type: %d\n", event->type);
	return 0;
}

int main() {
	// Create a queue to hold events
	Queue events;

	queue_init(&events, free);
	
	// Create some sample events
	Event event1 = {1};

	if (receive_event(&events, &event1) == -1){
		fprintf(stderr, "Error recieving event\n");
	}

	// Process events from the queue
	while (queue_size(&events) > 0){
		if(process_event(&events, dispatch_event) == -1){
			fprintf(stderr, "Error processing event\n");
			return 1;
		}
	}
	// Destroy the queue
	fprintf(stdout, "Queue destroyed\n");
	queue_destroy(&events);
	return 0;
}
