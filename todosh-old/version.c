#include <todosh/version.h>

char current_version[6] = {'\0'};

char *tsh_version() {
    sprintf(current_version, "%d.%d.%d", TSH_VER_MAJ, TSH_VER_MIN, TSH_VER_REV);
    return current_version;
}
