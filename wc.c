#include <stdio.h>
#include <stdlib.h>


#define BUFSIZE 1024

typedef enum{false, true} bool;

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char *buf = (char *)malloc(sizeof(char) * BUFSIZE);
	int i = 0;
	int alpha = 0, word = 0, line = 0;
	bool head = true;

	/*do with 通配符 * , 以及多个文件*/
	if (argc < 2) {
		fprintf(stderr, "argc err\n");
		fprintf(stdout, "Usage: ./a.out file1 file2 ...");
		return -1;
	}

	fp = fopen(argv[1], "r");
	if (!fp) {
		fprintf(stderr, "open err\n");
		goto fail0;
	}

	printf("%-9s%-9s%-9s\n", "line", "word", "alpha");
	while (fgets(buf, BUFSIZE, fp) != NULL) {
		for (; buf[i] != '\n'; i++) {
			if (isalpha(buf[i]) || ispunct(buf[i])) {
				head = false;
				alpha++;
			} else if ((isspace(buf[i])||ispunct(buf[i])) && head == false) {
				word++;
			} else if (isspace(buf[i]) && head == true) {
				continue;
			}
		}
		line++;
		if (!ispunct(buf[i - 1])) {
			word++;//一行结束都算作一个单词，这是在不考虑单词占据两行的情况下
		}

		printf("%-9d%-9d%-9d\n\n", line, word, alpha);
		word = 0;
		alpha = 0;
		head = true;
		i = 0;
	}

fail0:
	free(buf);
	buf = NULL;

	return 0;
}
