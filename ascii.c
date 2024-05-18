#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void encode(char *buf);

int main(int argc, char **argv)
{
    encode("Sun");
    
    return 0;
}

void encode(char *buf)
{
    int len = 3; // easy first
    char *tmp = (char *) malloc(32 * sizeof(char));
    char *med = (char *) malloc(32 * sizeof(char));
    int delim = 6;

    for (int i = 0; i < len; ++i) {
	itobstr(buf[i], tmp);
	printf("%c -> %s\n", buf[i], tmp);
	strcat(med, tmp);
	tmp[0] = '\0';
    }

    printf("Sun -> %s\n", med);

    char ss[7];
    char res[5];
    for (int j = 0; j < 4; ++j) {
	strncpy(ss, med + (j*delim), delim);
	int idx = bstrtoi(ss);
	res[j] = lookup_table[idx];
	printf("ss -> %s\n", ss);
    }

    res[4] = '\0';
    
    printf("%s\n", res);


    free(med);
    free(tmp);
}
