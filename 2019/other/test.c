
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int main()
{
    for (int i = 0; i < 2; ++i)
    {
        fork();
        //write(1, "-", 1);
        //write(1, "-\n", 2);
        printf("-");
         printf("- ");
        // printf("-\n");
    }
    return 0;
}
