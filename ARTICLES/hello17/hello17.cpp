#include <cstring>
#include <cstdio>
#include <string>

int main(void)
{
    if (FILE *fin = fopen("imm32.asm.txt", "r"))
    {
        char buf[256];
        std::string str;
        for (int iFile = 0; ; ++iFile)
        {
            while (fgets(buf, _countof(buf), fin))
            {
                str += buf;
                if (strcmp(buf, "---\n") == 0)
                    break;
            }

            if (str.empty())
                break;

            sprintf(buf, "imm-func-%02d.asm.txt", iFile);
            if (FILE *fout = fopen(buf, "w"))
            {
                fprintf(fout, "%s", str.c_str());
                fclose(fout);
            }
            else
            {
                puts(buf);
            }

            str.clear();
        }
        fclose(fin);
    }
    else
    {
        puts("fin");
    }

    return 0;
}
