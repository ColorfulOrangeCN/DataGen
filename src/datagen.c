#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//#include <ldev/lib/lstring.h>

#define MAX_VAR_COUNT 107
#define MAX_WORD_SIZE 64
char *tmp;

int ints[MAX_VAR_COUNT];
char *strings[MAX_VAR_COUNT];
double floats[MAX_VAR_COUNT];

void scan(void);

#define NEXT_WORD scanf("%s", tmp)

void gen_keys(char *key){
	if(!strcmp(key, "ENDL") || !strcmp(key, "E"))
		printf("\n");
	else if(!strcmp(key, "SPACE") || !strcmp(key,"S"))
		printf(" ");
	else if(!strcmp(key, "BREAK") || !strcmp(key, "B"))
		exit(0);
	else if(!strcmp(key, "RANDOM") || !strcmp(key, "R")){
		printf("%d",rand());
	} else if(!strcmp(key, "LET")){
		char *name = tmp;
		scanf("%s", tmp);
		        if(*name == 'i'){
				unsigned int index;
				sscanf(name+1, "%u", &index);
				scanf("%d", ints+index);
			} else if(*name == 's'){
				unsigned int index;
				sscanf(name+1, "%u", &index);
				free(strings[index]);
				strings[index] = malloc(128);
				scanf("%s", strings[index]);
			} else if(*name == 'f'){
				unsigned int index;
				sscanf(name+1, "%u", &index);
				scanf("%lf", floats+index);
			}		
	}else if(!(strcmp(key, "RANDOM_STRU") && strcmp(key, "RANDOM_STR") && strcmp(key, "RSTR") && strcmp(key, "RSTRU"))){
		int cnt;
		scanf("%d", &cnt);
		for(;cnt > 0; --cnt)printf("%c", rand() % 26 + 'A');
	} else if(!strcmp(key, "RANDOM_STRL") || !strcmp(key, "RSTRL")){
		int cnt;
		scanf("%d", &cnt);
		for(;cnt > 0; --cnt)printf("%c", rand() % 26 + 'a');
	} else if(*key == 'S'){
		printf("%s", key + 1);
	} else {
		fprintf(stderr, "Error! Do not know keyword: %s", key);
	}
}

void gen_vars(char *name){
        if(*name == 'i'){
	        unsigned int index;
		sscanf(name+1, "%u", &index);
		printf("%d", ints[index]);
	} else if(*name == 's'){
		unsigned int index;
		sscanf(name+1, "%u", &index);
		printf("%s", strings[index]);
	} else if(*name == 'f'){
		unsigned int index;
		sscanf(name+1, "%u", &index);
		printf("%lf", floats[index]);
	}
}

void scan(void){
	NEXT_WORD;
	if(!strcmp(tmp, ";")){
		exit(0);
	}
        if(isupper(*tmp)){
		gen_keys(tmp);
	} else {
		gen_vars(tmp);
	}
}

int main(){
	tmp = malloc(MAX_WORD_SIZE);
	memset(ints, 0 ,sizeof(ints));
	memset(strings, 0 , sizeof(strings));
	memset(floats, 0 , sizeof(floats));
	srand(time(NULL) + clock());
	while(!feof(stdin)){
		scan();
	}
	return 0;
}
