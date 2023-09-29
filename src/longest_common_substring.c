#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "longest_common_substring.h"

size_t max(size_t a, size_t b)
{
    return a > b ? a : b;
}

size_t longest_common_substring(const char *word_to_check, const char *word_to_compare)
{
    size_t height = strlen(word_to_check);
    size_t width = strlen(word_to_compare);

    size_t **grid = allocate2DSizeTArray(++height, ++width);

    size_t max_length = 0;

    for (size_t i = 1; i < height; i++)
    {
        for (size_t j = 1; j < width; j++)
        {
            if (word_to_check[i - 1] == word_to_compare[j - 1])
            {
                grid[i][j] = grid[i - 1][j - 1] + 1;
            }
            max_length = max(max_length, grid[i][j]);
        }
    }
    for (size_t i = 0; i < height; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return max_length;
}

size_t **allocate2DSizeTArray(size_t height, size_t width)
{
    size_t **array = malloc(height * sizeof(size_t *));
    if (!array)
    {
        return NULL;
    }

    for (size_t i = 0; i < height; i++)
    {
        array[i] = calloc(width, sizeof(size_t));
        if (!array[i])
        {
            for (size_t j = 0; j < i; j++)
            {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }
    return array;
}