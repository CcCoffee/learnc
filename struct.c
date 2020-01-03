#include <stdio.h>

struct company
{
    char cn[3];
    int pm;
};

struct company dec = {"DEV", 123};
int main(int argc, char const *argv[])
{
    dec.cn[0] = 'A';
    dec.pm = 44;
    printf("%s\n", dec.cn);
    printf("%d\n", dec.pm);
    return 0;
}
