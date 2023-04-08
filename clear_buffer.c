#include <stdio.h>
#include "clear_buffer.h"

void clear_buffer()
{
    while (getchar() != '\n') { ; }
}