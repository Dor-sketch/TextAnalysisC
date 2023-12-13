/* program "con" replaced sequence of following ascii characters
    it checks if the ascii value of the character is greater by
    one than the last character, and if it finds sequence greater
    than 3 following characters replaces it with a shortened version */

/* UPDATE - Low level support for runing inside xv6 OS */
#include "types.h"
#include "user.h"

char buf[512];

/* a function that checks if an input charcer is "alpha numeric":
    if it is - returns 1
    otherwise - returns 0 */
int is_alpha_numeric(char c) {
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
        ('0' <= c && c <= '9'))
        return 1;
    return 0;
}

/* a function that gets a string and returns a shortened version of it -
    every following sequence of ascii characters greater than 2 will be replaced
   by: "the first character" + "-" + "the last character in the sequence" */
void con(int fd) {
    int n, i, start_i;
    while ((n = read(fd, buf, sizeof(buf))) > 0) {
        for (i = 0; i < n; i++) {
            start_i = i;
            // Detect start of a sequence
            while (i < n - 1 && !(buf[i] - buf[i + 1])) {
                i++;
            }
            // Check if sequence is longer than 2
            if (i - start_i >= 2) {
                // Print condensed form
                printf(1, "%c...%c", buf[start_i], buf[i]);
            } else {
                // Print characters as they are
                while (start_i <= i) {
                    printf(1, "%c", buf[start_i++]);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int fd, i;

    // standard input
    if (argc <= 1) {
        con(0);
        exit();
    }

    for (i = 1; i < argc; i++) {
        if ((fd = open(argv[i], 0)) < 0) {
            printf(1, "con: cannot open %s\n", argv[i]);
            exit();
        }
        con(fd);
        close(fd);
    }
    exit();
}
