#include "next.h"




char *ft_malloc(int size)
{
    char *tmp = malloc(size);
    int i = 0;
    while (tmp[i])
        tmp[i++] = 0;
    return tmp;
}

int ft_strlen(char *s)
{
    int i = 0;
    if (!s)
        return i;
    while (s[i])
        i++;
    return i;
}

int ft_index_of(char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return -1;
    while (s[i])
    {
        if (s[i] == c)
            return i;
        i++;
    }
    return -1;
}

int ft_strlcpy(char *d, const char *s, int len)
{
    int i;

    i = 0;
    if (!d || !s)
        return i;
    while (s[i] && i < len - 1)
    {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
    return i;
}

char *ft_memcpy(char *d, const char *s, int len)
{
    int i;

    i = 0;
    if (!d || !s)
        return NULL;
    while (s[i] && i < len)
    {
        d[i] = s[i];
        i++;
    }
    return d;
}

int extract_line(char *stach, char *line)
{
    int index;
    char *tmp;
    int len;

    len = 0;
    index = ft_index_of(stach, '\n');
    tmp = NULL;
    if (index != -1)
    {
        len = ft_strlen(stach);
        line = ft_malloc(index + 2);
        ft_strlcpy(line, stach, index + 2);
        tmp = ft_malloc(len - index);
        ft_memcpy(tmp, stach + index + 1, len - index);
        free(stach);
        stach = ft_malloc(len - index);
        ft_memcpy(stach, tmp, len - index);
        free(tmp);
        return 1;
    }
    return 0;
}

// while (stach[i])
// {
//     if (stach[i] == '\n')
//     {
//         int j = 0;
//         char *line = ft_malloc(i + 2);
//         while (j < i + 1)
//         {
//             line[j] = stach[j];
//             j++;
//         }
//         line[j] = '\0';
//         free(buffer);
//         int size = strlen(stach); // "Hello!how" len = 9 , i = 5, rest = len - 5 = 4,
//         j = 0;
//         char *tmp = ft_malloc(size - i);
//         while (j < size - i)
//         {
//             tmp[j] = stach[i + 1 + j];
//             j++;
//         }
//         free(stach);
//         stach = ft_malloc(size - i);
//         i = 0;
//         while (tmp[i])
//         {
//             stach[i] = tmp[i];
//             i++;
//         }
//         stach[i] = 0;
//         free(tmp);
//         return (line);
//     }
//     i++;
// }

// while (stach && stach[i])
// {
//     if (stach[i] == '\n')
//     {
//         int j = 0;
//         char *line = ft_malloc(i + 2);
//         while (j < i + 1)
//         {
//             line[j] = stach[j];
//             j++;
//         }
//         line[j] = '\0';
//         if (buffer)
//             free(buffer);
//         int size = strlen(stach); // "Hello!how" len = 9 , i = 5, rest = len - 5 = 4,
//         j = 0;
//         char *tmp = ft_malloc(size - i);
//         while (j < size - i)
//         {
//             tmp[j] = stach[i + 1 + j];
//             j++;
//         }
//         free(stach);
//         stach = ft_malloc(size - i);
//         i = 0;
//         while (tmp[i])
//         {
//             stach[i] = tmp[i];
//             i++;
//         }
//         stach[i] = 0;
//         free(tmp);
//         return (line);
//     }
//     i++;
// }
int main()
{
    char *s = "12345";
    char *d = ft_malloc(5);
    ft_strlcpy(d, s, 5);
    printf("%s--", d);
}
