#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students { /* Global structure of the programme */
	int age, SID, height, political, weight;
	char major_hobby[20], minor_hobby[20], name[20], orientation, sex;
	struct students *next; /* For linked list */
	};

void find_matches(struct students *info,struct students *s, int SID)
{
	struct students *c = s; /* Student to be matched with */
	struct students *b = info; /* All other students */
	char ID[20];
	char match[20] = "match_";
	FILE *out;
	
	sprintf(ID, "%d" , SID);
	strcat(ID, ".txt");
	strcat(match, ID);
	out = fopen(match, "w");
	fprintf(out, "Matches for user %d (%s): \n", SID,s -> name);
	while (b)
	{
	if ( c -> SID != b -> SID) 
	{
		if ( c -> orientation == b -> sex && b -> orientation == c -> sex)
		{
			if (abs(c -> age - b -> age) <= 10)
			{
				if (abs(c -> political - b -> political) <= 2)
				fprintf(out, "- %d (%s)\n", b -> SID, b -> name);
			}
			else if (strcmp(b -> major_hobby, c -> major_hobby) == 0)
			{
				if (strcmp(b -> minor_hobby, c -> minor_hobby) == 0)
				fprintf(out, "- %d (%s)\n", b -> SID, b -> name);
			}
			else if (c -> height >= b -> height * 0.9 && c -> height <=
			b -> height * 1.1)
			{
				if (c -> weight >= b -> weight * 0.9 && c -> weight <= b -> weight
			* 1.1)
				fprintf(out, "- %d (%s)\n", b -> SID, b -> name);
			}
		} 
	
	}
	b = b -> next;
	}
}

struct students *delete(struct students *info)
{
	struct students *last, *prev;
	
	if (!info)
		return NULL;

	if (!info -> next) 
	{
		free(info);
		return NULL;
	}
	prev = info;
	last = info -> next;
	while (last -> next != NULL) 
	{
		prev = last;
		last = last -> next;
	}
	prev -> next = NULL;
	free(last);
	
	return info;
}

struct students *search(struct students *info, int SID)
{
	struct students *s = info;	
	while (s && s -> SID != SID)
		s = s -> next;
	if (!s)
	{
	printf("User with SID ");
	printf("%09d", SID);
	printf(" not found\n");
	exit(1);
	} else 
	return s;
}

struct students *insert(struct students *info, int SID, char name[20], char sex, char orientation,
			int age, int political, char major_hobby[20], char minor_hobby[20], 
			int height, int weight)
{
	struct students *s;
	struct students *end;
	
	s = malloc(sizeof(struct students));
	s -> SID = SID;	
	strcpy(s -> name, name);
	s -> sex = sex;
	s -> orientation = orientation;
	s -> age = age;
	s -> political = political;
	strcpy(s -> major_hobby,  major_hobby);
	strcpy(s -> minor_hobby, minor_hobby);
	s -> height = height;
	s -> weight = weight;
	s -> next = NULL;
	
	if (!info)
	return s;
	
	end = info;
	while (end -> next != NULL)
		end = end -> next;
	end -> next = s;

	return info;
}

int main(int argc, char *argv[])
{
	FILE *data;
	int age, height, person_SID, political, SID, weight;
	char buffer[256], major_hobby[20], minor_hobby[20], name[20], orientation, sex;
	struct students *info = NULL, *s;
	if (argc < 3)
	{
		printf("Usage: ./UCupiD db_file SID\n");
		return 1;
	}
	else
	{
		data = fopen(argv[1], "r");
	if (data == 0)
	{
		printf("Error: cannot open %s\n", argv[1]);
		return 1;
	}
	}
	person_SID = atoi(argv[2]);
	while (fgets(buffer, 80, data))
	{
	sscanf(buffer, "%d,%[^,],%c,%c,%d,%d,%[^,],%[^,],%d,%d", &SID,
	name, &sex, &orientation, &age, &political, major_hobby, minor_hobby, &height, &weight);
	info = insert(info, SID, name, sex, orientation, age, political, major_hobby, minor_hobby,
	height, weight);
	}
	s = search(info, person_SID);
	find_matches(info, s, person_SID);
	delete(info);	

	return 0;
}
