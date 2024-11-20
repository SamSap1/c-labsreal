#include<coding.h>

const unsigned char val=10;

unsigned char encode(unsigned char c)
{
    return c ^ val;
}
unsigned char decode(unsigned char c)
{
    return c ^ val;
}
