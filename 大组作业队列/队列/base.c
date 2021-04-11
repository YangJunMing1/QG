#include"base.h"

void SIZE()
{
    if (strcmp(datatype, "int") == 0)
        type_size = sizeof(int);
    else if (strcmp(datatype, "char\0") == 0)
        type_size = sizeof(char);
    else if (strcmp(datatype, "double\0") == 0)
        type_size = sizeof(double);
}