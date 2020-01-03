// 需使用独立的终端打开
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void display_progess(int total_length, int current_length)
{
    int time_slot = 100 * 1000; //ms
    int left_length = total_length - current_length;

    //绘制等号
    usleep(time_slot);
    for (int i = 0; i < current_length; i++)
    {
        printf("\033[31m=\033[0m");
    }
    //绘制横线
    for (int i = 0; i < left_length; i++)
    {
        printf("-");
    }
    char buf[100];
    sprintf(buf, "[%d%%]", current_length);
    printf("[%d%%]", current_length);
    fflush(stdout);
    if (current_length == total_length)
    {
        printf("\n");
    }
    else
    {
        for (int i = 0; i < total_length + strlen(buf); i++)
        {
            printf("%c", '\b');
        }
    }
}

int main(int argc, char const *argv[])
{
    int total_length = 100;
    for (int i = 0; i <= total_length; i++)
    {
        display_progess(total_length, i);
    }
    return 0;
}
