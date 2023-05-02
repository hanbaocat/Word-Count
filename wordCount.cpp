#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *fp;
    char *filename;
    char *mode;
    int ch_count = 0, word_count = 0;
    char buf[BUF_SIZE];
    int i, len;

    // 解析命令行参数
    if (argc < 2 || argc > 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }
    mode = argv[1];
    if (argc == 3) {
        filename = argv[2];
    }

	
    // 打开文件
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return 1;
    }
		printf("文件内容为：");
    // 逐行读取文件内容
    while (fgets(buf, BUF_SIZE, fp) != NULL) {
    	printf("%s",buf);
        len = strlen(buf);
        if (len > 0 && buf[len-1] == '\n') {
            buf[len-1] = '\0';  // 去掉行末的换行符
            len--;
        }

        // 统计字符数和单词数
        if (strcmp(mode, "-c") == 0) {
            ch_count += len;
        } else if (strcmp(mode, "-w") == 0) {
            for (i = 0; i < len; i++) {
                if (isspace(buf[i]) || buf[i] == ',') {
                    // 空格或逗号表示单词分隔符
                    word_count++;
                }
            }
            word_count++;  // 最后一个单词没有分隔符，需要额外计数
        } else {
            printf("出错啦");
            return 1;
        }
    }
	puts("");
    // 关闭文件
    fclose(fp);
    // 输出结果
    if (strcmp(mode, "-c") == 0) {
        printf("字符数为： %d\n", ch_count);
    } else {
        printf("单词数为： %d\n", word_count);
    }

    return 0;
}
