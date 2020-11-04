#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <Windows.h>
using namespace std;

enum en_DIRS {NORTH, EAST, SOUTH, WEST};

enum en_ROOMS { GREAT_HALL, DEFENSE_AGAINST_THE_DARK_ARTS_ROOM, POTIONS_ROOM, CHARMS_ROOM, HAGRIDS_HUT, GRYFFINDOR_COMMONS, RAVENCLAW_COMMONS, SLYTHERIN_COMMONS, HUFFLEPUFF_COMMONS, PREFECTS_BATHROOM,
CHAMBER_OF_SECRETS, BOYS_BATHROOM, GIRLS_BATHROOM, LIBRARY, RESTRICTED_SECTION, TRANSFIGURATION_ROOM, DUMBLEDORES_OFFICE, FLUFFYS_ROOM, DARK_FOREST, ROOM_OF_REQUIREMENT, ASTRONOMY_TOWER,
OWLERY, KITCHENS, FILCHS_OFFICE, PROFESSOR_SNAPES_OFFICE, MCGONAGALLS_OFFICE, PROFESSOR_SLUGHORNS_OFFICE, GREENHOUSE, TROPHY_ROOM, STAIR_CASE};

enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, SWISH_AND_FLICK, FLY};

enum en_NOUNS { WAND, CLOAK, BOOK, OWL, RAT, CAT, DOOR, STAIRS, TRIWIZARD_CUP, BROOM, TOM_RIDDLES_DIARY, SWORD_OF_GRYFFINDOR, POTION, MIRROR_OF_ERISED, DEMENTOR};

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 30;
const int VERBS = 10;
const int NOUNS = 15;

class words {
public:
	string word;
	int code;
	words();
	~words();
};

words::words() {
	enum en_VERBS { GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, SWISH_AND_FLICK, FLY };

}

words::~words() {
	enum en_VERBS { GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, SWISH_AND_FLICK, FLY };
}

class room {
public:
	string description;
	int exits_to_room[DIRS];
	room();
	~room();
};

room::room() {
	enum en_ROOMS {GREAT_HALL, DEFENSE_AGAINST_THE_DARK_ARTS_ROOM, POTIONS_ROOM, CHARMS_ROOM, HAGRIDS_HUT, GRYFFINDOR_COMMONS, RAVENCLAW_COMMONS, SLYTHERIN_COMMONS, HUFFLEPUFF_COMMONS, PREFECTS_BATHROOM,
	CHAMBER_OF_SECRETS, BOYS_BATHROOM, GIRLS_BATHROOM, LIBRARY, RESTRICTED_SECTION, TRANSFIGURATION_ROOM, DUMBLEDORES_OFFICE, FLUFFYS_ROOM, DARK_FOREST, ROOM_OF_REQUIREMENT, ASTRONOMY_TOWER,
	OWLERY, KITCHENS, FILCHS_OFFICE, PROFESSOR_SNAPES_OFFICE, MCGONAGALLS_OFFICE, PROFESSOR_SLUGHORNS_OFFICE, GREENHOUSE, TROPHY_ROOM, STAIR_CASE};
}

room::~room() {
	enum en_ROOMS {GREAT_HALL, DEFENSE_AGAINST_THE_DARK_ARTS_ROOM, POTIONS_ROOM, CHARMS_ROOM, HAGRIDS_HUT, GRYFFINDOR_COMMONS, RAVENCLAW_COMMONS, SLYTHERIN_COMMONS, HUFFLEPUFF_COMMONS, PREFECTS_BATHROOM,
	CHAMBER_OF_SECRETS, BOYS_BATHROOM, GIRLS_BATHROOM, LIBRARY, RESTRICTED_SECTION, TRANSFIGURATION_ROOM, DUMBLEDORES_OFFICE, FLUFFYS_ROOM, DARK_FOREST, ROOM_OF_REQUIREMENT, ASTRONOMY_TOWER,
	OWLERY, KITCHENS, FILCHS_OFFICE, PROFESSOR_SNAPES_OFFICE, MCGONAGALLS_OFFICE, PROFESSOR_SLUGHORNS_OFFICE, GREENHOUSE, TROPHY_ROOM, STAIR_CASE};
}

class noun {
public:
	string word;
	string description;
	int code;
	int location;
	bool can_carry;
	noun();
	~noun();
};

noun::noun() {
	enum en_NOUNS { WAND, CLOAK, BOOK, OWL, RAT, CAT, DOOR, STAIRS, TRIWIZARD_CUP, BROOM, TOM_RIDDLES_DIARY, SWORD_OF_GRYFFINDOR, POTION, MIRROR_OF_ERISED, DEMENTOR };
}

noun::~noun() {
	enum en_NOUNS { WAND, CLOAK, BOOK, OWL, RAT, CAT, DOOR, STAIRS, TRIWIZARD_CUP, BROOM, TOM_RIDDLES_DIARY, SWORD_OF_GRYFFINDOR, POTION, MIRROR_OF_ERISED, DEMENTOR };
}

void set_rooms(room *rms) {
	rms[GREAT_HALL].description.assign("the Great Hall");
	rms[GREAT_HALL].exits_to_room[NORTH] = STAIR_CASE;
	rms[GREAT_HALL].exits_to_room[EAST] = TROPHY_ROOM;
	rms[GREAT_HALL].exits_to_room[SOUTH] = HAGRIDS_HUT;
	rms[GREAT_HALL].exits_to_room[WEST] = KITCHENS;
	
	rms[DEFENSE_AGAINST_THE_DARK_ARTS_ROOM].description.assign("the Defense Against the Dark Arts Room");
	rms[DEFENSE_AGAINST_THE_DARK_ARTS_ROOM].exits_to_room[NORTH] = ROOM_OF_REQUIREMENT;
	rms[DEFENSE_AGAINST_THE_DARK_ARTS_ROOM].exits_to_room[EAST] = LIBRARY;
	rms[DEFENSE_AGAINST_THE_DARK_ARTS_ROOM].exits_to_room[SOUTH] = POTIONS_ROOM;
	rms[DEFENSE_AGAINST_THE_DARK_ARTS_ROOM].exits_to_room[WEST] = NONE;

	rms[POTIONS_ROOM].description.assign("the Potions Room");
	rms[POTIONS_ROOM].exits_to_room[NORTH] = DEFENSE_AGAINST_THE_DARK_ARTS_ROOM;
	rms[POTIONS_ROOM].exits_to_room[EAST] = KITCHENS;
	rms[POTIONS_ROOM].exits_to_room[SOUTH] = NONE;
	rms[POTIONS_ROOM].exits_to_room[WEST] = PROFESSOR_SNAPES_OFFICE;

	rms[CHARMS_ROOM].description.assign("the Charms room");
	rms[CHARMS_ROOM].exits_to_room[NORTH] = GRYFFINDOR_COMMONS;
	rms[CHARMS_ROOM].exits_to_room[EAST] = MCGONAGALLS_OFFICE;
	rms[CHARMS_ROOM].exits_to_room[SOUTH] = RESTRICTED_SECTION;
	rms[CHARMS_ROOM].exits_to_room[WEST] = NONE;

	rms[HAGRIDS_HUT].description.assign("Hagrids Hut");
	rms[HAGRIDS_HUT].exits_to_room[NORTH] = GREAT_HALL;
	rms[HAGRIDS_HUT].exits_to_room[EAST] = GREENHOUSE;
	rms[HAGRIDS_HUT].exits_to_room[SOUTH] = DARK_FOREST;
	rms[HAGRIDS_HUT].exits_to_room[WEST] = OWLERY;

	rms[GRYFFINDOR_COMMONS].description.assign("the Gryffindor common room");
	rms[GRYFFINDOR_COMMONS].exits_to_room[NORTH] = NONE;
	rms[GRYFFINDOR_COMMONS].exits_to_room[EAST] = DUMBLEDORES_OFFICE;
	rms[GRYFFINDOR_COMMONS].exits_to_room[SOUTH] = CHARMS_ROOM;
	rms[GRYFFINDOR_COMMONS].exits_to_room[WEST] = NONE;

	rms[RAVENCLAW_COMMONS].description.assign("	the Ravenclaws common room");
	rms[RAVENCLAW_COMMONS].exits_to_room[NORTH] = NONE;
	rms[RAVENCLAW_COMMONS].exits_to_room[EAST] = NONE;
	rms[RAVENCLAW_COMMONS].exits_to_room[SOUTH] = HUFFLEPUFF_COMMONS;
	rms[RAVENCLAW_COMMONS].exits_to_room[WEST] = PREFECTS_BATHROOM;

	rms[SLYTHERIN_COMMONS].description.assign("the Slytherins common room");
	rms[SLYTHERIN_COMMONS].exits_to_room[NORTH] = PROFESSOR_SNAPES_OFFICE;
	rms[SLYTHERIN_COMMONS].exits_to_room[EAST] = NONE;
	rms[SLYTHERIN_COMMONS].exits_to_room[SOUTH] = NONE;
	rms[SLYTHERIN_COMMONS].exits_to_room[WEST] = NONE;

	rms[HUFFLEPUFF_COMMONS].description.assign("the Hufflepuff common room");
	rms[HUFFLEPUFF_COMMONS].exits_to_room[NORTH] = RAVENCLAW_COMMONS;
	rms[HUFFLEPUFF_COMMONS].exits_to_room[EAST] = NONE;
	rms[HUFFLEPUFF_COMMONS].exits_to_room[SOUTH] = NONE;
	rms[HUFFLEPUFF_COMMONS].exits_to_room[WEST] = NONE;

	rms[PREFECTS_BATHROOM].description.assign("the Prefects Bathroom");
	rms[PREFECTS_BATHROOM].exits_to_room[NORTH] = NONE;
	rms[PREFECTS_BATHROOM].exits_to_room[EAST] = RAVENCLAW_COMMONS;
	rms[PREFECTS_BATHROOM].exits_to_room[SOUTH] = NONE;
	rms[PREFECTS_BATHROOM].exits_to_room[WEST] = FILCHS_OFFICE;

	rms[CHAMBER_OF_SECRETS].description.assign("the Chamber of Secrets");
	rms[CHAMBER_OF_SECRETS].exits_to_room[NORTH] = GIRLS_BATHROOM;
	rms[CHAMBER_OF_SECRETS].exits_to_room[EAST] = NONE;
	rms[CHAMBER_OF_SECRETS].exits_to_room[SOUTH] = NONE;
	rms[CHAMBER_OF_SECRETS].exits_to_room[WEST] = TROPHY_ROOM;

	rms[BOYS_BATHROOM].description.assign("the Boys Bathroom");
	rms[BOYS_BATHROOM].exits_to_room[NORTH] = FLUFFYS_ROOM;
	rms[BOYS_BATHROOM].exits_to_room[EAST] = GIRLS_BATHROOM;
	rms[BOYS_BATHROOM].exits_to_room[SOUTH] = TROPHY_ROOM;
	rms[BOYS_BATHROOM].exits_to_room[WEST] = STAIR_CASE;

	rms[GIRLS_BATHROOM].description.assign("the Girls Bathroom\n\nEek!");
	rms[GIRLS_BATHROOM].exits_to_room[NORTH] = FILCHS_OFFICE;
	rms[GIRLS_BATHROOM].exits_to_room[EAST] = NONE;
	rms[GIRLS_BATHROOM].exits_to_room[SOUTH] = CHAMBER_OF_SECRETS;
	rms[GIRLS_BATHROOM].exits_to_room[WEST] = BOYS_BATHROOM;

	rms[LIBRARY].description.assign("the Library");
	rms[LIBRARY].exits_to_room[NORTH] = RESTRICTED_SECTION;
	rms[LIBRARY].exits_to_room[EAST] = STAIR_CASE;
	rms[LIBRARY].exits_to_room[SOUTH] = KITCHENS;
	rms[LIBRARY].exits_to_room[WEST] = DEFENSE_AGAINST_THE_DARK_ARTS_ROOM;

	rms[RESTRICTED_SECTION].description.assign("the Restricted Section");
	rms[RESTRICTED_SECTION].exits_to_room[NORTH] = CHARMS_ROOM;
	rms[RESTRICTED_SECTION].exits_to_room[EAST] = TRANSFIGURATION_ROOM;
	rms[RESTRICTED_SECTION].exits_to_room[SOUTH] = LIBRARY;
	rms[RESTRICTED_SECTION].exits_to_room[WEST] = ROOM_OF_REQUIREMENT;

	rms[TRANSFIGURATION_ROOM].description.assign("the Transfiguration Room");
	rms[TRANSFIGURATION_ROOM].exits_to_room[NORTH] = MCGONAGALLS_OFFICE;
	rms[TRANSFIGURATION_ROOM].exits_to_room[EAST] = FLUFFYS_ROOM;
	rms[TRANSFIGURATION_ROOM].exits_to_room[SOUTH] = STAIR_CASE;
	rms[TRANSFIGURATION_ROOM].exits_to_room[WEST] = RESTRICTED_SECTION;

	rms[DUMBLEDORES_OFFICE].description.assign("Dumbledore's Office");
	rms[DUMBLEDORES_OFFICE].exits_to_room[NORTH] = NONE;
	rms[DUMBLEDORES_OFFICE].exits_to_room[EAST] = PROFESSOR_SLUGHORNS_OFFICE;
	rms[DUMBLEDORES_OFFICE].exits_to_room[SOUTH] = MCGONAGALLS_OFFICE;
	rms[DUMBLEDORES_OFFICE].exits_to_room[WEST] = NONE;

	rms[FLUFFYS_ROOM].description.assign("Fluffys Chambers");
	rms[FLUFFYS_ROOM].exits_to_room[NORTH] = NONE;
	rms[FLUFFYS_ROOM].exits_to_room[EAST] = FILCHS_OFFICE;
	rms[FLUFFYS_ROOM].exits_to_room[SOUTH] = BOYS_BATHROOM;
	rms[FLUFFYS_ROOM].exits_to_room[WEST] = GRYFFINDOR_COMMONS;

	rms[DARK_FOREST].description.assign("the Dark Forest");
	rms[DARK_FOREST].exits_to_room[NORTH] = HAGRIDS_HUT;
	rms[DARK_FOREST].exits_to_room[EAST] = NONE;
	rms[DARK_FOREST].exits_to_room[SOUTH] = NONE;
	rms[DARK_FOREST].exits_to_room[WEST] = ASTRONOMY_TOWER;

	rms[ROOM_OF_REQUIREMENT].description.assign("the Room of Requirement");
	rms[ROOM_OF_REQUIREMENT].exits_to_room[NORTH] = NONE;
	rms[ROOM_OF_REQUIREMENT].exits_to_room[EAST] = RESTRICTED_SECTION;
	rms[ROOM_OF_REQUIREMENT].exits_to_room[SOUTH] = DEFENSE_AGAINST_THE_DARK_ARTS_ROOM;
	rms[ROOM_OF_REQUIREMENT].exits_to_room[WEST] = NONE;

	rms[ASTRONOMY_TOWER].description.assign("the Astronomy Tower");
	rms[ASTRONOMY_TOWER].exits_to_room[NORTH] = OWLERY;
	rms[ASTRONOMY_TOWER].exits_to_room[EAST] = DARK_FOREST;
	rms[ASTRONOMY_TOWER].exits_to_room[SOUTH] = NONE;
	rms[ASTRONOMY_TOWER].exits_to_room[WEST] = NONE;

	rms[OWLERY].description.assign("the Owlery");
	rms[OWLERY].exits_to_room[NORTH] = NONE;
	rms[OWLERY].exits_to_room[EAST] = HAGRIDS_HUT;
	rms[OWLERY].exits_to_room[SOUTH] = ASTRONOMY_TOWER;
	rms[OWLERY].exits_to_room[WEST] = NONE;

	rms[KITCHENS].description.assign("the Kitchens");
	rms[KITCHENS].exits_to_room[NORTH] = LIBRARY;
	rms[KITCHENS].exits_to_room[EAST] = GREAT_HALL;
	rms[KITCHENS].exits_to_room[SOUTH] = OWLERY;
	rms[KITCHENS].exits_to_room[WEST] = NONE;

	rms[FILCHS_OFFICE].description.assign("Filchs Office");
	rms[FILCHS_OFFICE].exits_to_room[NORTH] = NONE;
	rms[FILCHS_OFFICE].exits_to_room[EAST] = PREFECTS_BATHROOM;
	rms[FILCHS_OFFICE].exits_to_room[SOUTH] = GIRLS_BATHROOM;
	rms[FILCHS_OFFICE].exits_to_room[WEST] = FLUFFYS_ROOM;

	rms[PROFESSOR_SNAPES_OFFICE].description.assign("Professor Snapes office");
	rms[PROFESSOR_SNAPES_OFFICE].exits_to_room[NORTH] = NONE;
	rms[PROFESSOR_SNAPES_OFFICE].exits_to_room[EAST] = NONE;
	rms[PROFESSOR_SNAPES_OFFICE].exits_to_room[SOUTH] = SLYTHERIN_COMMONS;
	rms[PROFESSOR_SNAPES_OFFICE].exits_to_room[WEST] = POTIONS_ROOM;

	rms[MCGONAGALLS_OFFICE].description.assign("Professor McGonagalls Office");
	rms[MCGONAGALLS_OFFICE].exits_to_room[NORTH] = DUMBLEDORES_OFFICE;
	rms[MCGONAGALLS_OFFICE].exits_to_room[EAST] = NONE;
	rms[MCGONAGALLS_OFFICE].exits_to_room[SOUTH] = TRANSFIGURATION_ROOM;
	rms[MCGONAGALLS_OFFICE].exits_to_room[WEST] = CHARMS_ROOM;

	rms[PROFESSOR_SLUGHORNS_OFFICE].description.assign("Professor Slughorns Office");
	rms[PROFESSOR_SLUGHORNS_OFFICE].exits_to_room[NORTH] = NONE;
	rms[PROFESSOR_SLUGHORNS_OFFICE].exits_to_room[EAST] = NONE;
	rms[PROFESSOR_SLUGHORNS_OFFICE].exits_to_room[SOUTH] = NONE;
	rms[PROFESSOR_SLUGHORNS_OFFICE].exits_to_room[WEST] = DUMBLEDORES_OFFICE;

	rms[GREENHOUSE].description.assign("the Greenhouse");
	rms[GREENHOUSE].exits_to_room[NORTH] = TROPHY_ROOM;
	rms[GREENHOUSE].exits_to_room[EAST] = NONE;
	rms[GREENHOUSE].exits_to_room[SOUTH] = NONE;
	rms[GREENHOUSE].exits_to_room[WEST] = HAGRIDS_HUT;

	rms[TROPHY_ROOM].description.assign("the Trophy Room");
	rms[TROPHY_ROOM].exits_to_room[NORTH] = BOYS_BATHROOM;
	rms[TROPHY_ROOM].exits_to_room[EAST] = CHAMBER_OF_SECRETS;
	rms[TROPHY_ROOM].exits_to_room[SOUTH] = GREENHOUSE;
	rms[TROPHY_ROOM].exits_to_room[WEST] = GREAT_HALL;

	rms[STAIR_CASE].description.assign("the Staircase");
	rms[STAIR_CASE].exits_to_room[NORTH] = TRANSFIGURATION_ROOM;
	rms[STAIR_CASE].exits_to_room[EAST] = BOYS_BATHROOM;
	rms[STAIR_CASE].exits_to_room[SOUTH] = GREAT_HALL;
	rms[STAIR_CASE].exits_to_room[WEST] = LIBRARY;
}

void set_directions(words *dir) {
	dir[NORTH].code = NORTH;
	dir[NORTH].word = "NORTH";
	dir[EAST].code = EAST;
	dir[EAST].word = "EAST";
	dir[SOUTH].code = SOUTH;
	dir[SOUTH].word = "SOUTH";
	dir[WEST].code = WEST;
	dir[WEST].word = "WEST";
}

void set_verbs(words *vbs) {
	vbs[GET].code = GET;
	vbs[GET].word = "GET";
	vbs[DROP].code = DROP;
	vbs[DROP].word = "DROP";
	vbs[USE].code = USE;
	vbs[USE].word = "USE";
	vbs[OPEN].code = OPEN;
	vbs[OPEN].word = "OPEN";
	vbs[CLOSE].code = CLOSE;
	vbs[CLOSE].word = "CLOSE";
	vbs[EXAMINE].code = EXAMINE;
	vbs[EXAMINE].word = "EXAMINE";
	vbs[INVENTORY].code = INVENTORY;
	vbs[INVENTORY].word = "INVENTORY";
	vbs[LOOK].code = LOOK;
	vbs[LOOK].word = "LOOK";
	vbs[SWISH_AND_FLICK].code = SWISH_AND_FLICK;
	vbs[SWISH_AND_FLICK].word = "SWISH AND FLICK";
	vbs[FLY].code = FLY;
	vbs[FLY].word = "FLY";
}

void set_nouns(noun *nns) {
	nns[WAND].word = "WAND";
	nns[WAND].code = WAND;
	nns[WAND].description = "a magical wand";
	nns[WAND].can_carry = true;
	nns[WAND].location = NONE;
	
	nns[CLOAK].word = "CLOAK";
	nns[CLOAK].code = CLOAK;
	nns[CLOAK].description = "a warm cloak";
	nns[CLOAK].can_carry = true;
	nns[CLOAK].location = GRYFFINDOR_COMMONS, RAVENCLAW_COMMONS, SLYTHERIN_COMMONS, HUFFLEPUFF_COMMONS;

	nns[BOOK].word = "BOOK";
	nns[BOOK].code = BOOK;
	nns[BOOK].description = "a book";
	nns[BOOK].can_carry = true;
	nns[BOOK].location = LIBRARY;

	nns[OWL].word = "OWL";
	nns[OWL].code = OWL;
	nns[OWL].description = "a snowy owl";
	nns[OWL].can_carry = false;
	nns[OWL].location = OWLERY;

	nns[RAT].word = "RAT";
	nns[RAT].code = RAT;
	nns[RAT].description = "a scrawny rat";
	nns[RAT].can_carry = true;
	nns[RAT].location = NONE;

	nns[CAT].word = "CAT";
	nns[CAT].code = CAT;
	nns[CAT].description = "a mangy cat";
	nns[CAT].can_carry = false;
	nns[CAT].location = NONE;

	nns[DOOR].word = "DOOR";
	nns[DOOR].code = DOOR;
	nns[DOOR].description = "a wooden door";
	nns[DOOR].can_carry = false;
	nns[DOOR].location = NONE;

	nns[STAIRS].word = "STAIRS";
	nns[STAIRS].code = STAIRS;
	nns[STAIRS].description = "stairs";
	nns[STAIRS].can_carry = false;
	nns[STAIRS].location = STAIR_CASE;

	nns[TRIWIZARD_CUP].word = "TRIWIZARD_CUP";
	nns[TRIWIZARD_CUP].code = TRIWIZARD_CUP;
	nns[TRIWIZARD_CUP].description = "a cup for champions";
	nns[TRIWIZARD_CUP].can_carry = false;
	nns[TRIWIZARD_CUP].location = TROPHY_ROOM;

	nns[BROOM].word = "BROOM";
	nns[BROOM].code = BROOM;
	nns[BROOM].description = "a broom";
	nns[BROOM].can_carry = false;
	nns[BROOM].location = NONE;

	nns[TOM_RIDDLES_DIARY].word = "TOM_RIDDLES_DIARY";
	nns[TOM_RIDDLES_DIARY].code = TOM_RIDDLES_DIARY;
	nns[TOM_RIDDLES_DIARY].description = "a dark ominous book";
	nns[TOM_RIDDLES_DIARY].can_carry = false;
	nns[TOM_RIDDLES_DIARY].location = RESTRICTED_SECTION;

	nns[SWORD_OF_GRYFFINDOR].word = "SWORD_OF_GRYFFINDOR";
	nns[SWORD_OF_GRYFFINDOR].code = SWORD_OF_GRYFFINDOR;
	nns[SWORD_OF_GRYFFINDOR].description = "a perfect sword";
	nns[SWORD_OF_GRYFFINDOR].can_carry = false;
	nns[SWORD_OF_GRYFFINDOR].location = DUMBLEDORES_OFFICE;

	nns[POTION].word = "POTION";
	nns[POTION].code = POTION;
	nns[POTION].description = "a brewed potion";
	nns[POTION].can_carry = true;
	nns[POTION].location = POTIONS_ROOM;

	nns[MIRROR_OF_ERISED].word = "MIRROR_OF_ERISED";
	nns[MIRROR_OF_ERISED].code = MIRROR_OF_ERISED;
	nns[MIRROR_OF_ERISED].description = "a mirror showing your desires";
	nns[MIRROR_OF_ERISED].can_carry = false;
	nns[MIRROR_OF_ERISED].location = NONE;

	nns[DEMENTOR].word = "DEMENTOR";
	nns[DEMENTOR].code = DEMENTOR;
	nns[DEMENTOR].description = "a soul sucker";
	nns[DEMENTOR].can_carry = false;
	nns[DEMENTOR].location = NONE;
} 

void section_command(string Cmd, string &wd1, string &wd2) {
	string sub_str;
	vector<string> words;
	char search = '  ';
	size_t i, j;

	for (i = 0; i < Cmd.size(); i++) {
		if (Cmd.at(i) != search) {
			sub_str.insert(sub_str.end(), Cmd.at(i));
		}
		if (i == Cmd.size() - 1) {
			words.push_back(sub_str);
			sub_str.clear();
		}
		if (Cmd.at(i) == search) {
			words.push_back(sub_str);
			sub_str.clear();
		}
	}
	for (i = words.size() - 1; i > 0; i--) {
		if (words.at(i) == " ") {
			words.erase(words.begin() + i);
		}
	}
	for (i = 0; i < words.size(); i++) {
		for (j = 0; j < words.at(i).size(); j++) {
			if (islower(words.at(i).at(j))) {
				words.at(i).at(j) = toupper(words.at(i).at(j));
			}
		}
	}
	if (words.size() == 0) {
		cout << "No command was given" << endl;
	}
	if (words.size() == 1) {
		wd1 = words.at(0);
	}
	if (words.size() == 2) {
		wd1 = words.at(0);
		wd2 = words.at(1);
	}
	if (words.size() > 2) {
		cout << "Command is too long. Only type one or two words (direction or verb and noun)" << endl;
	}
}

void look_around(int loc, room *rms, words *dir, /* Added parameter */ noun *nns) {
	int i;
	cout << "I am in a " << rms[loc].description << "." << endl;

	for (i = 0; i < DIRS; i++) {
		if (rms[loc].exits_to_room[i] != NONE) {
			cout << "There is an exit " << dir[i].word << " to a " << rms[rms[loc].exits_to_room[i]].description << "." << endl;
		}
	}
	for (i = 0; i < NOUNS; i++) {
		cout << "I see " << nns[i].description << "." << endl;
	}
}

bool parser(int &loc, string wd1, string wd2, words *dir, words *vbs, room *rms, /* Added parameter */ noun *nns) {
	vector<string> inventory;
	vector<string>::iterator changeIter;
	vector<string>::const_iterator readIter;
	string input;
	inventory.push_back("Wand");
	inventory.push_back("Books");
	inventory.push_back("Sorcerers Stone");
	static bool door_state = false; // false is a closed door
	int i;
	for (i = 0; i < DIRS; i++) {
		if (wd1 == dir[i].word) {
			if (rms[loc].exits_to_room[dir[i].code] != NONE) {
				loc = rms[loc].exits_to_room[dir[i].code];
				cout << "I am now in " << rms[loc].description << "." << endl;
				if (loc == GREAT_HALL || loc == STAIR_CASE) {
					nns[GREAT_HALL].location = loc;
				}
				return true;
			}
			else {
				cout << "No exit that way." << endl;
				return true;
			}
		}
	}
	int NOUN_MATCH = NONE;
	int VERB_ACTION = NONE;

	for (i = 0; i < VERBS; i++) {
		if (wd1 == vbs[i].word) {
			VERB_ACTION = vbs[i].code;
			break;
		}
	}
	if (wd2 != " ") {
		for (i = 0; i < NOUNS; i++) {
			if (wd2 == nns[i].word) {
				NOUN_MATCH = nns[i].code;
				break;
			}
		}
	}
	if (VERB_ACTION == NONE) {
		cout << "No valid command entered." << endl;
		return true;
	}
	if (VERB_ACTION == LOOK) {
		look_around(loc, rms, dir, /* Added parameter nns */ nns);
		return true;
	}
	if (VERB_ACTION == OPEN) {
		if (NOUN_MATCH == GREAT_HALL) {
			if (door_state == false) {
				door_state = true;
				rms[GREAT_HALL].exits_to_room[EAST] = TROPHY_ROOM;
				rms[GREAT_HALL].exits_to_room[NORTH] = STAIR_CASE;
				nns[GREAT_HALL].description.clear();
				nns[GREAT_HALL].description.assign("an open store room door");
				cout << "I have opened the door" << endl;
				return true;
			}
			else if (door_state == true) {
				cout << "The door is already open" << endl;
				return true;
			}
		}
		else {
			cout << "Opening that is not possible" << endl;
			return true;
		}
	}
	if (VERB_ACTION == SWISH_AND_FLICK) {
		cout << "*SWISH AND FLICK*" << "Wingardium Leviosa!" << endl;
		Sleep(3000);
		cout << "\nBOOM!!\n";
		Sleep(2000);
		cout << "\nIts LeviosA, not LevioSAH!" << endl;
		return true;
	}
	if (VERB_ACTION == GET) {
		cout << "What would you like to add to your inventory?: \n";
		cout << "Broom\n";
		cout << "Potion\n";
		cout << "Chocolate frog\n";
		cout << "Marauders map\n";
		getline(cin, input);
		inventory.push_back(input);
		return true;
	}
	if (VERB_ACTION == DROP) {
		string dropItem;
		cout << "What would you like to drop?:\n ";
		cout << "Wand\n";
		cout << "Books\n";
		cout << "Sorcerers Stone\n";
		cout << input;
		getline(cin, dropItem);
		if (dropItem == "Wand" || dropItem == "wand") {
			changeIter == inventory.begin();
			inventory.erase(changeIter);
			cout << "\nYour items:\n";
			for (readIter = inventory.begin(); readIter != inventory.end(); readIter++) {
				cout << *readIter << endl;
			}
		}
		else if (dropItem == "Books" || dropItem == "books") {
			changeIter == inventory.begin() + 1;
			inventory.erase(changeIter);
			cout << "\nYour items:\n";
			for (readIter = inventory.begin(); readIter != inventory.end(); readIter++) {
				cout << *readIter << endl;
			}
		}
		else if (dropItem == "Sorcerers Stone" || dropItem == "sorcerers stone") {
			changeIter == inventory.begin() + 2;
			inventory.erase(changeIter);
		 	cout << "\nYour items:\n";
			for (readIter = inventory.begin(); readIter != inventory.end(); readIter++) {
				cout << *readIter << endl;
			}
		}
		else if (dropItem == input) {
			changeIter == inventory.begin() + 3;
			inventory.erase(changeIter);
			cout << "\nYour items:\n";
			for (readIter = inventory.begin(); readIter != inventory.end(); readIter++) {
				cout << *readIter << endl;
			}
		}
		return true;
	}
	if (VERB_ACTION == FLY) {
		cout << "You hop on the Firebolt broom stick and zip off over to Hagrids Hut" << endl;
		nns[HAGRIDS_HUT].location = loc;
		return true;
	}
	if (VERB_ACTION == INVENTORY) {
		for (readIter = inventory.begin(); readIter != inventory.end(); readIter++) {
			cout << *readIter << endl;
		}
		return true;
	}
	if (VERB_ACTION == EXAMINE) {
		string examineItem;
		cout << en_NOUNS() << endl;
		cout << "What would you like to examine?: \n";
		getline(cin, examineItem);
		if (examineItem == "WAND") {
			cout << nns[WAND].description << endl;
		}
		else if (examineItem == "CLOAK") {
			cout << nns[CLOAK].description << endl;
		}
		else if (examineItem == "BOOK") {
			cout << nns[BOOK].description << endl;
		}
		else if (examineItem == "OWL") {
			cout << nns[OWL].description << endl;
		}
		else if (examineItem == "RAT") {
			cout << nns[RAT].description << endl;
		}
		else if (examineItem == "CAT") {
			cout << nns[CAT].description << endl;
		}
		else if (examineItem == "DOOR") {
			cout << nns[DOOR].description << endl;
		}
		else if (examineItem == "STAIRS") {
			cout << nns[STAIRS].description << endl;
		}
		else if (examineItem == "TRIWIZARD CUP") {
			cout << nns[TRIWIZARD_CUP].description << endl;
		}
		else if (examineItem == "BROOM") {
			cout << nns[BROOM].description << endl;
		}
		else if (examineItem == "TOM RIDDLES DIARY") {
			cout << nns[TOM_RIDDLES_DIARY].description << endl;
		}
		else if (examineItem == "SWORD OF GRYFFINDOR") {
			cout << nns[SWORD_OF_GRYFFINDOR].description << endl;
		}
		else if (examineItem == "POTION") {
			cout << nns[POTION].description << endl;
		}
		else if (examineItem == "MIRROR OF ERISED") {
			cout << nns[MIRROR_OF_ERISED].description << endl;
		}
		else if (examineItem == "DEMENTOR") {
			cout << nns[DEMENTOR].description << endl;
		}
	}
	return true;
}

int main() {
	string command;
	string word_1;
	string word_2;

	room rooms[ROOMS];
	set_rooms(rooms);

	words directions[DIRS];
	set_directions(directions);

	words verbs[VERBS];
	set_verbs(verbs);

	noun nouns[NOUNS];
	set_nouns(nouns);

	int location = GREAT_HALL;

	while (word_1 != "Quit") {
		command.clear();
		cout << "What shall I do? ";
		getline(cin, command);

		word_1.clear();
		word_2.clear();

		section_command(command, word_1, word_2);

		if (word_1 != "Quit") {
			parser(location, word_1, word_2, directions, verbs, rooms, /* Added parameter */ nouns);
		}
	}
	return 0;
}
