#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024
#define TEST

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char *buf = (char *)malloc(sizeof(char) * BUFSIZE);
	int index = 0;

#ifdef TEST
	static int i = 0;
#endif
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

	while (!feof(fp)) {
		fgets(buf, BUFSIZE, fp);
#ifdef TEST
		printf("[line%d] =%s\n", i, buf);
		i++;
#endif
		/*buf 的组成表现为"hello world\n\0",可以通过hex十六进制方式打开  参考如下
		 *http://blog.csdn.net/npjocj/article/details/7311394
		 *当初Android系统下的文本编辑器打开windows文档出现问题，就是通过\r\n-->\n解的
		*/

		/*玩游戏，明日搞*/
		for (; buf[index]) {

		}
	}

fail0:
	free(buf);
	buf = NULL;

	return 0;
}
