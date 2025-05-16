#include "filehandling.h"

char *my_strndup(const char *s, size_t n)
{
    char *result;
    size_t len = strlen(s);

    if (n < len)
    {
        len = n;
    }

    result = (char *)malloc(len + 1);
    if (!result)
    {
        return NULL;
    }

    strncpy(result, s, len);
    result[len] = '\0';

    return result;
}