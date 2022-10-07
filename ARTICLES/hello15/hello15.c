#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>

int doReadFile(const char *filename, char **ppData)
{
    FILE *fin;
    size_t size, readLen;
    char *pData;
    struct stat st;

    *ppData = NULL;

    if (stat(filename, &st) != 0)
        return -1;

    size = st.st_size;

    fin = fopen(filename, "rb");
    if (!fin)
        return -2;

    pData = malloc(size + 1); // including NUL
    if (!pData)
    {
        fclose(fin);
        return -3;
    }

    readLen = fread(pData, 1, size, fin);
    pData[size] = 0; // set NUL

    fclose(fin);

    if (readLen != size)
    {
        free(pData);
        return -4;
    }

    *ppData = pData;
    return 0; // success
}

int printFile(const char *filename)
{
    char *pData;
    int ret;

    ret = doReadFile(filename, &pData);
    switch (ret)
    {
    case 0: // success
        printf("%s\n", pData);
        free(pData);
        break;
    case -1:
    case -2:
        printf("ERROR: cannot open '%s'\n", filename);
        break;
    case -3:
        printf("ERROR: Out of memory\n");
        break;
    case -4:
        printf("ERROR: cannot read '%s'\n", filename);
        break;
    default:
        assert(0);
        break;
    }

    return ret;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: hello15 \"file.txt\"\n");
        return 0;
    }

    return printFile(argv[1]);
}
