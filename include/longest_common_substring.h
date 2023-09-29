#ifndef LONGEST_COMMON_SUBSTRING_H
#define LONGEST_COMMON_SUBSTRING_H

#include <stddef.h>

size_t max(size_t a, size_t b);

size_t **allocate2DSizeTArray(size_t height, size_t width);

size_t longest_common_substring(const char *word_to_check, const char *word_to_compare);

#endif // LONGEST_COMMON_SUBSTRING_H