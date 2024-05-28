// cover_main.c
// Description: Illustrates set covering (chapter 7)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cover.h"
#include "list.h"
#include "set.h"

// Define the number of members in the skills and player sets.

#define SKILLS_COUNT 12
#define PLAYER_COUNT 8

// print_skills

static void print_skills(const Set *skills){
	ListNode *member;
	char *data;
	int size, i;

	// Display the set of skills.
	//
	
	fprintf(stdout, "Set size is %d\n", size = set_size(skills));

	i = 0;

	member = list_head(skills);

	while(i < size) {
	
		data = list_data(member); 
		fprintf(stdout, "skills[%03]=%c\n", i, *data);

		member = list_next(member);
		i++;
	
	}
	return;
}

// print_palyers
static void print_players(const Set *players) {
	ListNode *member;
	// Display the skills for each player in the set of players.
	//
	for(member = list_head(players); member != NULL; member = list_next(member)){
		fprintf(stdout, "Palyer %c\n", *(char *) ((KSet *) list_data(member))->key);
		print_skils(&((KSet *)list_data(member))->set);
	}
}
