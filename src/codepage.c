#include "codepage.h"
#include "dbg.h"
#include "env.h"
#include <stdlib.h>
#include <string.h>

/* List of code-pages */
struct cp_data
{
    const char *names;
    const uint16_t table[256];
};

static const struct cp_data cp_data[] = {
    {
        "437,CP437,IBM437,US",
        {
            0x0020, 0x263a, 0x263b, 0x2665, 0x2666, 0x2663, 0x2660, 0x2022,
            0x25d8, 0x25cb, 0x25d9, 0x2642, 0x2640, 0x266a, 0x266b, 0x263c,
            0x25b6, 0x25c0, 0x2195, 0x203c, 0x00b6, 0x00a7, 0x25ac, 0x21a8,
            0x2191, 0x2193, 0x2192, 0x2190, 0x221f, 0x2194, 0x25b2, 0x25bc,
            0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
            0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
            0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
            0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
            0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
            0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
            0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
            0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
            0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
            0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
            0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
            0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x2302,

            0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x00e0, 0x00e5, 0x00e7,
            0x00ea, 0x00eb, 0x00e8, 0x00ef, 0x00ee, 0x00ec, 0x00c4, 0x00c5,
            0x00c9, 0x00e6, 0x00c6, 0x00f4, 0x00f6, 0x00f2, 0x00fb, 0x00f9,
            0x00ff, 0x00d6, 0x00dc, 0x00a2, 0x00a3, 0x00a5, 0x20a7, 0x0192,
            0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x00f1, 0x00d1, 0x00aa, 0x00ba,
            0x00bf, 0x2310, 0x00ac, 0x00bd, 0x00bc, 0x00a1, 0x00ab, 0x00bb,
            0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
            0x2555, 0x2563, 0x2551, 0x2557, 0x255d, 0x255c, 0x255b, 0x2510,
            0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x255e, 0x255f,
            0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x2567,
            0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256b,
            0x256a, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
            0x03b1, 0x00df, 0x0393, 0x03c0, 0x03a3, 0x03c3, 0x00b5, 0x03c4,
            0x03a6, 0x0398, 0x03a9, 0x03b4, 0x221e, 0x03c6, 0x03b5, 0x2229,
            0x2261, 0x00b1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00f7, 0x2248,
            0x00b0, 0x2219, 0x00b7, 0x221a, 0x207f, 0x00b2, 0x25a0, 0x00a0}
    },
    {
        "850,CP850,IBM850,Latin1,WEU",
        {
            0x0020, 0x263a, 0x263b, 0x2665, 0x2666, 0x2663, 0x2660, 0x2022,
            0x25d8, 0x25cb, 0x25d9, 0x2642, 0x2640, 0x266a, 0x266b, 0x263c,
            0x25b6, 0x25c0, 0x2195, 0x203c, 0x00b6, 0x00a7, 0x25ac, 0x21a8,
            0x2191, 0x2193, 0x2192, 0x2190, 0x221f, 0x2194, 0x25b2, 0x25bc,
            0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
            0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
            0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
            0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
            0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
            0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
            0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
            0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
            0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
            0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
            0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
            0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x2302,

            0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x00e0, 0x00e5, 0x00e7,
            0x00ea, 0x00eb, 0x00e8, 0x00ef, 0x00ee, 0x00ec, 0x00c4, 0x00c5,
            0x00c9, 0x00e6, 0x00c6, 0x00f4, 0x00f6, 0x00f2, 0x00fb, 0x00f9,
            0x00ff, 0x00d6, 0x00dc, 0x00f8, 0x00a3, 0x00d8, 0x00d7, 0x0192,
            0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x00f1, 0x00d1, 0x00aa, 0x00ba,
            0x00bf, 0x00ae, 0x00ac, 0x00bd, 0x00bc, 0x00a1, 0x00ab, 0x00bb,
            0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x00c1, 0x00c2, 0x00c0,
            0x00a9, 0x2563, 0x2551, 0x2557, 0x255d, 0x00a2, 0x00a5, 0x2510,
            0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x00e3, 0x00c3,
            0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x00a4,
            0x00f0, 0x00d0, 0x00ca, 0x00cb, 0x00c8, 0x0131, 0x00cd, 0x00ce,
            0x00cf, 0x2518, 0x250c, 0x2588, 0x2584, 0x00a6, 0x00cc, 0x2580,
            0x00d3, 0x00df, 0x00d4, 0x00d2, 0x00f5, 0x00d5, 0x00b5, 0x00fe,
            0x00de, 0x00da, 0x00db, 0x00d9, 0x00fd, 0x00dd, 0x00af, 0x00b4,
            0x00ad, 0x00b1, 0x2017, 0x00be, 0x00b6, 0x00a7, 0x00f7, 0x00b8,
            0x00b0, 0x00a8, 0x00b7, 0x00b9, 0x00b3, 0x00b2, 0x25a0, 0x00a0}
    },
    {
        "852,CP850,IBM852,Latin2,CEU",
        {
            0x0020, 0x263a, 0x263b, 0x2665, 0x2666, 0x2663, 0x2660, 0x2022,
            0x25d8, 0x25cb, 0x25d9, 0x2642, 0x2640, 0x266a, 0x266b, 0x263c,
            0x25b6, 0x25c0, 0x2195, 0x203c, 0x00b6, 0x00a7, 0x25ac, 0x21a8,
            0x2191, 0x2193, 0x2192, 0x2190, 0x221f, 0x2194, 0x25b2, 0x25bc,
            0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
            0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
            0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
            0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
            0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
            0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
            0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
            0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
            0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
            0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
            0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
            0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x2302,

            0x00c7, 0x00fc, 0x00e9, 0x00e2, 0x00e4, 0x016f, 0x0107, 0x00e7,
            0x0142, 0x00eb, 0x0150, 0x0151, 0x00ee, 0x0179, 0x00c4, 0x0106,
            0x00c9, 0x0139, 0x013a, 0x00f4, 0x00f6, 0x013d, 0x013e, 0x015a,
            0x015b, 0x00d6, 0x00dc, 0x0164, 0x0165, 0x0141, 0x00d7, 0x010d,
            0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x0104, 0x0105, 0x017d, 0x017e,
            0x0118, 0x0119, 0x00ac, 0x017a, 0x010c, 0x015f, 0x00ab, 0x00bb,
            0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x00c1, 0x00c2, 0x011a,
            0x015e, 0x2563, 0x2551, 0x2557, 0x255d, 0x017b, 0x017c, 0x2510,
            0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x0102, 0x0103,
            0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x00a4,
            0x0111, 0x0110, 0x010e, 0x00cb, 0x010f, 0x0147, 0x00cd, 0x00ce,
            0x011b, 0x2518, 0x250c, 0x2588, 0x2584, 0x0162, 0x016e, 0x2580,
            0x00d3, 0x00df, 0x00d4, 0x0143, 0x0144, 0x0148, 0x0160, 0x0161,
            0x0154, 0x00da, 0x0155, 0x0170, 0x00fd, 0x00dd, 0x0163, 0x00b4,
            0x00ad, 0x02dd, 0x02db, 0x02c7, 0x02d8, 0x00a7, 0x00f7, 0x00b8,
            0x00b0, 0x00a8, 0x02d9, 0x0171, 0x0158, 0x0159, 0x25a0, 0x00a0}
    },
    {
        "Kamenický,KEYBCS2,KAMENICKY,Czech,CZ,SK",
        {
            0x0020, 0x263a, 0x263b, 0x2665, 0x2666, 0x2663, 0x2660, 0x2022,
            0x25d8, 0x25cb, 0x25d9, 0x2642, 0x2640, 0x266a, 0x266b, 0x263c,
            0x25b6, 0x25c0, 0x2195, 0x203c, 0x00b6, 0x00a7, 0x25ac, 0x21a8,
            0x2191, 0x2193, 0x2192, 0x2190, 0x221f, 0x2194, 0x25b2, 0x25bc,
            0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027,
            0x0028, 0x0029, 0x002a, 0x002b, 0x002c, 0x002d, 0x002e, 0x002f,
            0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037,
            0x0038, 0x0039, 0x003a, 0x003b, 0x003c, 0x003d, 0x003e, 0x003f,
            0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047,
            0x0048, 0x0049, 0x004a, 0x004b, 0x004c, 0x004d, 0x004e, 0x004f,
            0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057,
            0x0058, 0x0059, 0x005a, 0x005b, 0x005c, 0x005d, 0x005e, 0x005f,
            0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067,
            0x0068, 0x0069, 0x006a, 0x006b, 0x006c, 0x006d, 0x006e, 0x006f,
            0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077,
            0x0078, 0x0079, 0x007a, 0x007b, 0x007c, 0x007d, 0x007e, 0x2302,

            0x010c, 0x00fc, 0x00e9, 0x010f, 0x00e4, 0x010e, 0x0164, 0x010d,
            0x011b, 0x011a, 0x0139, 0x00cd, 0x013e, 0x013a, 0x00c4, 0x00c1,
            0x00c9, 0x017e, 0x017d, 0x00f4, 0x00f6, 0x00d3, 0x016f, 0x00da,
            0x00fd, 0x00d6, 0x00dc, 0x0160, 0x013d, 0x00dd, 0x0158, 0x0165,
            0x00e1, 0x00ed, 0x00f3, 0x00fa, 0x0148, 0x0147, 0x016e, 0x00d4,
            0x0161, 0x0159, 0x0155, 0x0154, 0x00bc, 0x00a7, 0x00ab, 0x00bb,
            0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556,
            0x2555, 0x2563, 0x2551, 0x2557, 0x255d, 0x255c, 0x255b, 0x2510,
            0x2514, 0x2534, 0x252c, 0x251c, 0x2500, 0x253c, 0x255e, 0x255f,
            0x255a, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256c, 0x2567,
            0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256b,
            0x256a, 0x2518, 0x250c, 0x2588, 0x2584, 0x258c, 0x2590, 0x2580,
            0x03b1, 0x03b2, 0x0393, 0x03c0, 0x03a3, 0x03c3, 0x03bc, 0x03c4,
            0x03a6, 0x0398, 0x03a9, 0x03b4, 0x221e, 0x2205, 0x03b5, 0x2229,
            0x2261, 0x00b1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00f7, 0x2248,
            0x2218, 0x00b7, 0x2219, 0x221a, 0x207f, 0x00b2, 0x25a0, 0x00a0}
    },
    {
        0
    }
};

static const uint16_t *cp_table = cp_data[0].table;

static int read_codepage_file(const char *fname)
{
    FILE *f = fopen(fname, "r");
    if(!f)
        return 0;
    // Note: this leaks memory, so this function should be called only once.
    uint16_t *new_table = malloc(sizeof(cp_table[0]) * 256);
    // Start with a copy of CP437
    memcpy(new_table, cp_data[0].table, sizeof(cp_table[0]) * 256);
    // Read all lines in file
    while(!feof(f))
    {
        char line[256];
        int dcode = 0, ucode = 0;
        if(1 != fscanf(f, " %255[^\n\r#]%*[^\n\r]\n", line))
        {
            // Try to consume comments
            fscanf(f, "%*[^\n\r]\n");
            continue;
        }

        if(line[0] == '#')
            continue;
        if(2 == sscanf(line, "%i %i", &dcode, &ucode))
        {
            if(dcode < 0 || dcode > 256)
            {
                fclose(f);
                print_error("reading codepage '%s', line '%s', invalid byte value %d\n",
                            fname, line, dcode);
            }
            // Ignore control-codes
            if(dcode < 32 || dcode == 127)
                continue;
            if(ucode < 32 || ucode > 0xFFFF)
            {
                fclose(f);
                print_error("reading codepage '%s', line '%s', invalid unicode value %d\n",
                            fname, line, ucode);
            }
            new_table[dcode] = ucode;
        }
    }
    fclose(f);
    cp_table = new_table;
    return 1;
}

void set_codepage(const char *cp_name)
{
    // Search our list of codepages
    for(const struct cp_data *cp = cp_data; cp->names; cp++)
    {
        char *names = strdup(cp->names);
        for(char *name = strtok(names, ","); name; name = strtok(0, ","))
        {
            if(0 == strcasecmp(cp_name, name))
            {
                debug(debug_dos, "set_codepage: DOS CP set to '%s'\n", names);
                cp_table = cp->table;
                return;
            }
        }
    }
    if(!read_codepage_file(cp_name))
        print_error("missing or unknown codepage '%s', use '?' for a list.\n",
                    cp_name);
}

static void list_codepages(void)
{
    fprintf(stderr, "List of internal codepages:\n");
    for(const struct cp_data *cp = cp_data; cp->names; cp++)
        fprintf(stderr, "\t%s\n", cp->names);
    print_error("select one of the above or a filename with a translation table.\n");
}

void init_codepage(void)
{
    const char *cp = getenv(ENV_CODEPAGE);
    if(cp && *cp)
    {
        if(!strcmp(cp, "?"))
            list_codepages();
        set_codepage(cp);
    }
}

/* Transforms a DOS char to Unicode */
int get_unicode(uint8_t cp)
{
    return cp_table[cp];
}

/* Transforms a Unicode code-point to the DOS char */
int get_dos_char(int uc)
{
    // TODO: faster searching
    for(int i = 0; i < 256; i++)
        if(uc == cp_table[i])
            return i;
    // Assume space is always valid
    return ' ';
}

