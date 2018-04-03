#ifndef CHANGEFORMAT_H
#define CHANGEFORMAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseFormatFile(char* inputfile, char* cloudfilename) {
    int filename_len = strlen(inputfile);
    if(strcmp(inputfile + filename_len -3, "txt") == 0) {
        FILE* fp = fopen(inputfile, "r");
            if(fp == NULL){
                printf("this is no file");
                return;
            }
            const int LEN = 1024;
            char buf[60];
            char* file_buf = (char*) malloc(100*LEN*LEN);
            size_t line_num = 0;
            size_t cursor = 0;
            while(!feof(fp)){
                if(fgets(buf, 60, fp) == NULL)
                    continue;
                ++line_num;
                size_t str_len = strlen(buf);
                strncpy(file_buf + cursor, buf, str_len);
                cursor += str_len;
            }
            char file_head[200];
            sprintf(file_head,
                    "# .PCD v0.7 - Point Cloud Data file format\n"
                            "VERSION 0.7\n"
                            "FIELDS x y z\n"
                            "SIZE 4 4 4\n"
                            "TYPE F F F\n"
                            "COUNT 1 1 1\n"
                            "WIDTH %d\n"
                            "HEIGHT 1\n"
                            "VIEWPOINT 0 0 0 1 0 0 0\n"
                            "POINTS %d\n"
                            "DATA ascii\n", (int)line_num, (int)line_num
            );
            //printf("%s", file_head);
            //printf("%s", file_buf);
            strcpy(cloudfilename, inputfile);
            //printf("%s\n", inputfile);
            //printf("%d\n", filename_len);
            cloudfilename[filename_len-3] = 'p';
            cloudfilename[filename_len-2] = 'c';
            cloudfilename[filename_len-1] = 'd';

            FILE *reverse_fp = fopen(cloudfilename, "w");
            fputs(file_head, reverse_fp);
            fputs(file_buf, reverse_fp);
            fclose(reverse_fp);
            free(file_buf);
            fclose(fp);
            //printf("%s-------\n", cloudfilename);
            return;
    }
    else if(strcmp(inputfile + filename_len -3, "pcd") == 0) {
        strcpy(cloudfilename, inputfile);
        return;
    }
}





#endif // CHANGEFORMAT_H
