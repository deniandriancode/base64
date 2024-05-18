#ifndef BASE64_UTILS_H
#define BASE64_UTILS_H

#include <string.h>

static char lookup_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void reverse(char *buf);
void itobstr(int d, char *buf);
int bstrtoi(char *buf);


void reverse(char *buf)
{
    int len = strlen(buf);
    char *start = buf;
    char *end = start + len - 1;
    char c;

    while (start < end) {
	c = *start;
	*start++ = *end;
	*end-- = c;
    }
}

void itobstr(int d, char *buf)
{
    char tmp_buf[9];
    int i;
    for (i = 0; d; d /=2, ++i) {
	if (d % 2 == 0)
	    tmp_buf[i] = '0';
	else
	    tmp_buf[i] = '1';
    }

    while (i < 8)
	tmp_buf[i++] = '0';

    tmp_buf[i] = '\0';
    reverse(tmp_buf);
    
    strncat(buf, tmp_buf, 9);
}

int bstrtoi(char *buf)
{
    int i = 0;
    int j = strlen(buf) - 1;
    int sum = 0;

    while (i <= j) {
	if (buf[j-i] == '1')
	    sum += 1 << i;

	++i;
    }

    return sum;
}

#endif
