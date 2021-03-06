#if 1

#include <stdio.h>
#include <unistd.h>

/*progress为进度百分比，取值为0~100, last_char_count为上一次显示进度条时所用到的字符个数*/
int display_progress(int progress, int last_char_count)
{
    int i = 0;

    /*把上次显示的进度条信息全部清空*/
    for (i = 0; i < last_char_count; i++)
    {
        printf("\b");
    }

    /*此处输出‘=’，也可以是其他字符，仅个人喜好*/
    for (i = 0; i < progress; i++)
    {
        printf("=");
    }
    printf(">>");
    /*输出空格截止到第104的位置，仅个人审美*/
    for (i += 2; i < 104; i++)
    {
        printf(" ");
    }
    /*输出进度条百分比*/
    i = i + printf("[%d%%]", progress);
    /*此处不能少，需要刷新输出缓冲区才能显示，
这是系统的输出策略*/
    fflush(stdout);

    /*返回本次显示进度条时所输出的字符个数*/
    return i;
}

int main(void)
{
    int i = 0;
    int ret = 0;

    printf("progress: ");
    for (i = 0; i < 101; i++)
    {
        ret = display_progress(i, ret);
        usleep(1000 * 200);
    }
    printf("\n");
    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <unistd.h>
//#include <unistd.h>

int main()
{
    int i = 0;
    char bar[102];
    const char *lable = "|/-\\";
    bar[0] = 0;
    while (i <= 100)
    {
        printf("[%-100s][%d%%][%c]\r", bar, i, lable[i % 4]);
        fflush(stdout);
        bar[i++] = '#';
        bar[i] = 0;
        usleep(100000);
    }
    printf("\n");
    return 0;
}

#endif
