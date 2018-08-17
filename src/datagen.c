#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//#include <ldev/lib/lstring.h>

#define MAX_VAR_COUNT 107
#define MAX_WORD_SIZE 64
char *tmp;

int ints[MAX_VAR_COUNT];
//lstring *strings[MAX_VAR_COUNT]；

#define NEXT_WORD scanf("%s", tmp)

void gen_keys(char *key){
	if(!strcmp(key, "ENDL"))
		printf("\n");
	else if(!strcmp(key, "SPACE"))
		printf(" ");
	else if(!strcmp(key, "BREAK"))
		exit(0);
	else if(!strcmp(key, "RANDOM")){
		printf("%d",rand());
	} else if(!(strcmp(key, "RANDOM_STRU") || strcmp(key, "RANDOM_STR"))){
		int cnt;
		scanf("%d", &cnt);
		for(;cnt > 0; --cnt)printf("%c", rand() % 26 + 'A');
	} else if(!strcmp(key, "RANDOM_STRL")){
		int cnt;
		scanf("%d", &cnt);
		for(;cnt > 0; --cnt)printf("%c", rand() % 26 + 'a');
	} else if(*key == 'S'){
		printf("%s", key + 1);
	} else {
		fprintf(stderr, "Error! Do not know keyword: %s", key);
	}
}

void scan(void){
	NEXT_WORD;
        if(isupper(*tmp)){
		gen_keys(tmp);
	}
}

int main(){
	tmp = malloc(MAX_WORD_SIZE);
	while(!feof(stdin)){
		scan();
	}
	return 0;
}
