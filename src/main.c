#include <stdio.h>
#define CW 16

int main(int argc, char *argv[]){
	FILE *fp = fopen(argv[1], "r");
	int cc = 0, c, b = 0;
	char cb[CW];

	if (fp != NULL){
		while (1){
			if ((c = fgetc(fp)) == EOF){
				while (cc < CW){
					printf("-- ");
					cb[cc++] = 0;
				}
				b = 1;
			}else{
				if (c < 16) printf("0");
				printf("%x ", c);
				cb[cc++] = c;
			}
			if (cc > CW - 1){
				cc = 0;
				printf("| ");
				for (int i = 0; i < CW; i++){
					if (cb[i] > 32 && cb[i] < 128){
						printf("%c", cb[i]);
					}else{
						printf(".");
					}
				}
				printf("\n");
			}
			if (b) break;
		}
	}

	fclose(fp);
	return 0;
}