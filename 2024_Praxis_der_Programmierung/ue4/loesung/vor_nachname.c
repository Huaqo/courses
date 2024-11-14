#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){

	char s1[MAX];
	char s2[MAX];
	char name[2*MAX];
	int index;

	// AUffordeurng Eingabe Name
	printf("Gebe deinen Vornamen an: \n");
	fgets(s1, MAX, stdin);
	printf("Gebe deinen Nachnamen an: \n");
	fgets (s2, MAX, stdin);

	// ob Vorund Nachname verschieden oder gleich sind
	int rvalue = strcmp(s1, s2);
  	if (rvalue == 0){
    	    printf("Namen sind gleich \n");
	}
 	else {
    	    printf("Strings sind ungleich \n");
	}
	
	// Großschreibung Nachname
	for (index = 0; ((s2[index]) != '\0'); ++index){
		if ((int)s2[index] >= 97  && (int)s2[index] <= 122){
		    s2[index] = (int) s2[index] - 32;
		}
		else{continue;}
	}
	// printf("großgeschriebener Nachname: %s \n", s2);

	// Vorname NACHNAME String
	int len_s1 = strlen(s1);
	if (len_s1 > 0 && s1[len_s1 - 1] == '\n') {
		s1[len_s1 - 1] = ' ';
	}
	else {}
	strcpy(name, s1);
	strncat(name, s2, 2*MAX);
	printf("%s", name);

	// Länge von Namen
	int len_letters = 0;
	for (index = 0; name[index] != '\0'; ++index){
		if ((name[index] >= 'A' && name[index] <= 'Z') || (name[index] >= 'a' && name[index] <= 'z')){
			len_letters ++;
		}
		else{continue;}
	}
	printf("Länge des Names: %d \n", len_letters);

	return 0;	

}
