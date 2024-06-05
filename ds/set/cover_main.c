// cover_main.c
// Description: Illustrates set covering (chapter 7)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cover.h"
#include "../single/list.h"
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
		fprintf(stdout, "skills[%03d]=%c\n", i, *data);

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
		print_skills(&((KSet *)list_data(member))->set);
	}
	return;
}


// match_key
int matc_key(const void *key1, const void *key2){
	// Determine whether two keyed sets match.
	if(*(char *) ((const KSet *)key1)->key == *(char *) ((const KSet *)key2)->key){
		return 1;
	} else {
		return 0;
	}
}

// match_skils
int match_skill(const void *skill1, const void *skill2){
	// Determine whether two skills match.
	if(*(const char*) skill1 == *(const char *) skill2){
		return 1;
	}	else { return 0;}
}


// match_key

int match_key(const void *key1, const void *key2){
	// Determine whether two keyed sets match.
	if(*(char *) ((const KSet *)key1)->key == *(char *) ((const KSet *)key2)->key){
		return 1;
	} else {
		return 0;
	}
}

// Main
//
int main(int argc, char **argv){
	Set skills, players, covering;

	char skills_array[SKILLS_COUNT], subids_array[PLAYER_COUNT];

	KSet player_array[PLAYER_COUNT];
	int retval;

	// Create the set of skills.

	fprintf(stdout, "Creating the set of skills\n");

	set_init(&skills, match_skill, NULL);

	char each_letter = 'a';
	for ( each_letter = 'a'; each_letter < 'a' + SKILLS_COUNT; each_letter++){
		skills_array[each_letter - 'a'] = (char) each_letter;
	}


	for (int index = 0; index < SKILLS_COUNT; index++){
		if (set_insert(&skills, &skills_array[index]) != 0){
			return 1;
		}
	}

	print_skills(&skills);

	// Create some player sets with certain skills.

	fprintf(stdout, "Creating the player subsets\n");

	set_init(&players, match_key, NULL);

	char each_number = '1';
	for (int i = '1'; i < '1' + PLAYER_COUNT; i++){
		fprintf(stdout, "Creating player %c\n", i);
		subids_array[i - '1'] = i;
	}


	for (int index = 0; index < PLAYER_COUNT; index++){
		player_array[index].key = &subids_array[index];
		set_init(&player_array[index].set, match_skill, NULL);
		switch(index){
			case 0:
			if (set_insert(&player_array[index].set, &skills_array[0]) != 0){
				return 1;
			}
			if (set_insert(&player_array[index].set, &skills_array[1]) != 0){
				return 1;
			}
			if (set_insert(&player_array[index].set, &skills_array[2]) != 0){
				return 1;
			}
			if (set_insert(&player_array[index].set, &skills_array[3]) != 0){
				return 1;
			}
			break;
			case 1:
			if (set_insert(&player_array[index].set, &skills_array[4]) != 0){
				return 1;
			}
			if (set_insert(&player_array[index].set, &skills_array[5]) != 0){
				return 1;
			}
			if (set_insert(&player_array[index].set, &skills_array[6]) != 0){
				return 1;
			}
			if (set_insert(&player_array[index].set, &skills_array[7]) != 0){
				return 1;
			}
			if (set_insert(&player_array[index].set, &skills_array[8]) != 0){
				return 1;
			}
			break;
			
			case 2:
			if (set_insert(&player_array[index].set, &skills_array[9]) != 0){
				return 1;
			}
			if (set_insert(&player_array[index].set, &skills_array[10]) != 0){
				return 1;
			}

			if (set_insert(&player_array[index].set, &skills_array[11]) != 0){
				return 1;
			}
			break;
			
			case 3:
			if(set_insert(&player_array[index].set, &skills_array[0]) != 0){
				return 1;
			}
			if(set_insert(&player_array[index].set, &skills_array[4]) != 0){
				return 1;
			}
			break;
			case 4:
			if(set_insert(&player_array[index].set, &skills_array[1]) != 0){
				return 1;
			}
			if(set_insert(&player_array[index].set, &skills_array[5]) != 0){
				return 1;
			}
			if(set_insert(&player_array[index].set, &skills_array[6]) != 0){
				return 1;
			}
			break;

			case 5:

			if(set_insert(&player_array[index].set, &skills_array[2]) != 0){
				return 1;
			}

			if(set_insert(&player_array[index].set, &skills_array[3]) != 0){
				return 1;
			}

			
			if(set_insert(&player_array[index].set, &skills_array[6]) != 0){
				return 1;
			}

			if(set_insert(&player_array[index].set, &skills_array[7]) != 0){
				return 1;
			}

			if(set_insert(&player_array[index].set, &skills_array[10]) != 0){
				return 1;
			}

			
			if(set_insert(&player_array[index].set, &skills_array[11]) != 0){
				return 1;
			}
			break;

			default:
			if (set_insert(&player_array[index].set, &skills_array[11]) != 0){
				return 1;
			}
		}

		if (set_insert(&players, &player_array[index]) != 0){
			return 1;
		}
	}

	print_players(&players);

	// Compute the set covering.
	fprintf(stdout, "Generating the cover\n");

	if ((retval = cover(&skills, &players, &covering)) != 0){
		return 1;
	}

	if (retval == 1){
		fprintf(stdout, "The set could not be covered\n");
	} else {
		print_players(&covering);
	}

	// Destroy the sets.

	fprintf(stdout, "Destroying the sets\n");

	for (int index = 0; index < PLAYER_COUNT; index++){	
		set_destroy(&player_array[index].set);
	}

	// Destoy skills
	set_destroy(&skills);
	return 0;

}
