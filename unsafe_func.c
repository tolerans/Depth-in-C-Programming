#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	int line_number = 0;
	fp = fopen(argv[2], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
    
    
    while ((read = getline(&line, &len, fp)) != -1) {
		line_number++;
		if (strstr(line, "strcpy")){
			printf("Line %d: strcpy() is used, you should use strlcpy (BSD library) or strncpy() instead.", line_number);
			printf(" Warning usage -->%s", line); 
		}
		if (strstr(line, "strcat")){
			printf("Line %d: strcat() is used, you should use strlcat (BSD library) or strncat() instead.", line_number);
			printf(" Warning usage -->%s", line); 
		}
		if (strstr(line, "sprintf")){
			printf("Line %d: sprintf() is used, you should use snprintf() instead.", line_number);
			printf(" Warning usage -->%s", line); 
		}
		if (strstr(line, "gets")){
			printf("Line %d: gets() is used, you should use fgets() instead.", line_number);
			printf(" Warning usage -->%s", line); 
		}
		if (strstr(line, "getpw")){
			printf("Line %d: getpw() is used, you should use getpwuid() instead.", line_number);
			printf(" Warning usage -->%s", line); 
		}
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

