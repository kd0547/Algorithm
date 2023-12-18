#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



int strlen(char* s) {
    int len = 0;

    if (s == NULL) {
        return 1;
    }
    

    while (s[len] != '\0') {
        len++;
    }

    return len;
}

int removeZero(char* s) {
    int len = strlen(s);
    int i = 0;
    int result = 0;

    while (i < len) {
        if (s[i] == '1') {
            result++;
        }
        i++;
    }

    return result;
}

char* binaryConverter(int len) {
    if (len == 1) {
        return NULL;
    }

    int len_copy = len;
    int memory_size = len +1;
    int i = 0;

    char* source_bin = (char*)calloc('0', sizeof(char) * memory_size);
    char* dest_bin = (char*)calloc('0', sizeof(char) * memory_size);

   

    if (source_bin != NULL && dest_bin != NULL) {
        source_bin[sizeof(char) * memory_size - 1] = '\0';
        dest_bin[sizeof(char) * memory_size - 1] = '\0';

        while (len_copy >= 1) {

            if (len_copy % 2 == 1) {
                source_bin[i] = '1';
            }
            else if (len_copy % 2 == 0) {
                source_bin[i] = '0';
            }
            len_copy = len_copy / 2;

            i++;
        }
        int len2 = strlen(source_bin);

        for (int i = 0; i < len2; i++)
        {
            dest_bin[i] = source_bin[(len2 - i) - 1];
        }
    }
   
    if (source_bin != NULL) {
        free(source_bin);
    }
   
    


    return dest_bin;
}


// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
int* solution(const char* s) {

    int* answer = (int*)malloc(sizeof(int) * 2); 
    int removeCount = 0;
    int removeLen = 0;

    if (answer != NULL) {
        char* data = s;

        while (strlen(data) != 1)
        {
            int d = removeZero(data);

            removeLen = removeLen + strlen(data) - d;

            data = binaryConverter(d);
            removeCount++;
        }

        *(answer + 0) = removeCount;
        *(answer + 1) = removeLen;
    }

    return answer;
}

int main() {
    char* binaryString = "110010101001";

    int* test = solution(binaryString);
    
    for (int i = 0; i < 2; i++)
    {
        printf_s("%d \n", test[i]);
    }
    
}