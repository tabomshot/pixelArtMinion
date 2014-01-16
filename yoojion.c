
#include <stdio.h>
#include <stdlib.h>

#include "animation.h"

void draw(int fnum)
{
	int i, j;
	char** cframe = NULL;

	switch(fnum) {
		case 0:
			cframe = frame0;
			break;
		case 1:
			cframe = frame1;
			break;
		default:
			cframe = frame0;
			break;
	}

    for(i=0; i<50; i++) {
        for(j=0; j<56; j++) {
            switch(cframe[i][j]) {
                case ',': case '%': case '(':
                    printf("\x1b[47m%c%c\x1b[0m", ' ', ' ');
                    break;
                case '-': case '@': case '^':
                    printf("\x1b[40m%c%c\x1b[0m", ' ', ' ');
                    //printf("\033[0;40;33m%c\x1b[0m", ' ');
                    break;
                case '*':
                    printf("\x1b[43m%c%c\x1b[0m", ' ', ' ');
                    break;
                case '&': case ')':
                    printf("\x1b[40m%c%c\x1b[0m", ' ', ' ');
                    break;
                case '$':
                    printf("\x1b[44m%c%c\x1b[0m", ' ', ' ');
                    break;
                case '+':
                    //printf("\x1b[45m%c\x1b[0m", ' ');
                    printf("\x1b[41m%c%c\x1b[0m", ' ', ' ');
                    break;
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
	int i=0;
	while(1) {
		system("clear");
		draw(i%2);
		usleep(700000);
		i++;
	}

	return 0;
}
