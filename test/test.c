#include <unistd.h>

int main(void)
{
    write(1, "Hi", 2);
    return (0);
}