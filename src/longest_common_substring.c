#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "longest_common_substring.h"

int longest_common_substring(const char *word_to_check, const char *word_to_compare)
{
    int height = strlen(word_to_check);
    int width = strlen(word_to_compare);

    int **grid = malloc(height * sizeof(int *));

    int max_length = 0;

    for (int i = 0; i < height; i++)
    {
        grid[i] = malloc(width * sizeof(int));
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            grid[i][j] = 0;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
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
    for (int i = 0; i < height; i++)
    {
        free(grid[i]);
    }
    free(grid);

    return max_length;
}