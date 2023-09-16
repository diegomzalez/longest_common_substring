#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "longest_common_substring.h"

int longest_common_substring(const char *word_to_check, const char *word_to_compare)
{
    size_t height = strlen(word_to_check);
    size_t width = strlen(word_to_compare);

    int **grid = malloc(height * sizeof(int *));

    int max_length = 0;

    for (size_t i = 0; i < height; i++)
    {
        grid[i] = calloc(width, sizeof(int));
    }

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < width; j++)
        {
            int length = 0;
            if (word_to_check[i] == word_to_compare[j])
            {
                length++;
                if (i > 0)
                {
                    length += grid[i - 1][j - 1];
                }
            }
            grid[i][j] = length;
            printf("%i", length);
            max_length = length > max_length ? length : 0;
        }
        printf("\n");
    }
    for (size_t i = 0; i < height; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return max_length;
}