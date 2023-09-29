#include "longest_common_substring.h"
#include <stdio.h>
int main()
{
    const char *word_to_check = "Hish";
    const char *word_to_compare = "Fish";
    const size_t result = longest_common_substring(word_to_check, word_to_compare);
    printf("\nThe largest substring length is: %zu\n", result);
    return 0;
}