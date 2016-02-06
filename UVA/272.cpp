#include <stdio.h>

using namespace std;

int main(void) {
    bool first_quotes = true;

    char c;
    while ((c = getchar()) != EOF) {
        // If the next character is a quote
        // we either need to use beginning single quotes
        // or end single quotes, depending on if the quote
        // is the first or second in a pair. Thus we just
        // check if the character is a quote and, if it is,
        // we swap it out for the start or end quotes
        // then change the boolean first_quotes to reflect
        // that the next quote will be the opposite to
        // the currently swapped quote.

        if (c == '"') {
            if (first_quotes) {
                putchar('`');
                putchar('`');
            }

            else {
                putchar('\'');
                putchar('\'');
            }

            first_quotes = !first_quotes;
        }

        else putchar(c);
    }
}