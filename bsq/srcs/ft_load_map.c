/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:33:27 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/28 13:33:29 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../includes/pointer.h"

#define MAX_ROWS 100
int **g_arr_ptr;
int ft_atoi(char *str);
char *ft_strncpy(char *src);
int max_size(int **arr, int rows, int cols);
void updateArray(int **arr, int rows, int cols, int result);
void displayArray(int **arr, int rows, int cols);
void free2DArray(int **g_arr_ptr, int rows);
int **create2DArray(int rows, int cols, int arr[rows][cols])
{
    int **g_arr_ptr;
    int i;
    int j;

    g_arr_ptr = (int **)malloc(rows * sizeof(int *));
    i = 0;
    while (i < rows)
    {
        g_arr_ptr[i] = (int *)malloc(cols * sizeof(int));
        j = 0;
        while (j < cols)
        {
            g_arr_ptr[i][j] = arr[i][j];
            j++;
        }
        i++;
    }
    return (g_arr_ptr);
}
void free2DArray(int **g_arr_ptr, int rows)
{
    int i;

    i = 0;
    while (i < rows)
    {
        free(g_arr_ptr[i]);
        i++;
    }
    free(g_arr_ptr);
}
int count_columns(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    char buffer[1];
    int num_columns = 0;
    int first_line = 1;
    while (read(fd, buffer, 1) > 0)
    {
        if (first_line)
        {
            if (buffer[0] == '\n')
            {
                first_line = 0;
            }
        }
        else if (buffer[0] == '\n')
        {

            break;
        }
        else
        {
            num_columns++;
        }
    }

    close(fd);

    return num_columns;
}
void encode_function(int rows, int cols, char map[rows][cols])
{

    int i;
    int j;
    int arr[rows][cols];
    i = 0;
    j = 0;

    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            if (map[i][j] == space)
            {
                arr[i][j] = 1;
            }
            else if (map[i][j] == obstacle)
            {
                arr[i][j] = 0;
            }
            j++;
        }
        i++;
    }

    //
    /* int r = sizeof(arr) / sizeof(arr[0]);
    int c = sizeof(arr[0]) / sizeof(arr[0][0]); */

    g_arr_ptr = create2DArray(rows, cols, arr);

    int result = max_size(g_arr_ptr, rows, cols);
    // printf("%d\n", result);

    updateArray(g_arr_ptr, rows, cols, result);

    displayArray(g_arr_ptr, rows, cols);

    free2DArray(g_arr_ptr, rows);
}
int main(int argc, char **argv)
{

    if (argc >= 2)
    {
        int o_map = 1;
        while (o_map < argc)
        {
            char *filename = argv[o_map];
            int fd = open(filename, O_RDONLY);
            if (fd == -1)
            {
                perror("open");
                exit(1);
            }

            char buffer[1];
            int row = 0, col = 0;
            int num_cols = count_columns(filename);
            // printf("num cols %i", num_cols);
            char map[MAX_ROWS][num_cols];
            char first[100];
            char chars[1];

            int first_line = 1;
            int i =0;
            while (read(fd, buffer, 1) > 0)
            {
                if (first_line)
                {
                    if (buffer[0] == '\n')
                    {
                        first_line = 0;
                        ft_atoi(ft_strncpy(first));
                    }
                    else
                    {
                        first[i] = buffer[0];
                        i++;
                    }

                }
                else
                {
                    if (buffer[0] == '\n')
                    {
                        row++;
                        col = 0;
                    }
                    else
                    {
                        map[row][col] = buffer[0];
                        col++;
                    }
                }
            }
            close(fd);
            encode_function(row, num_cols, map);
            printf("\n\n");
            o_map++;
        }
    }
    else
    {
        int fd;
        char chars[1];
        char first[100];
        int i = 0;
        // fd = 0;
        while (read(fd, chars, 1) > 0)
        {
            if (chars[0] == '\n')
            {
                break;
            }
            else
            {
                first[i] = chars[0];
                i++;
            }
        }
        int m = ft_atoi(ft_strncpy(first));
        /*         printf("user input  %i \n", m);
                printf("user obstacle  %c \n", obstacle);
                printf("user free  %c \n", space);
                printf("user feel  %c \n", fill); */

        char **map;
        int cols;
        int j = 0;
        int p = 0;
        cols = 0;
        map = (char **)malloc(m * sizeof(char *));
        while (j < m)
        {
            while (read(fd, chars, 1) > 0)
            {
                if (chars[0] == '\n')
                {

                    map[j] = (char *)malloc((cols + 1) * sizeof(char));
                    p = 0;
                    while (p < cols)
                    {
                        map[j][p] = first[p];
                        p++;
                    }
                    map[j][p] = '\0'; // Null-terminate the string
                    cols = 0;

                    break;
                }
                else
                {
                    first[cols] = chars[0];
                    cols++;
                }
            }
            j++;
        }
        int c = p;
        char mp[m][c];
        int row = 0;
        int col;
        while (row < m)
        {
            col = 0;
            while (col < c)
            {
                mp[row][col] = map[row][col];
                col++;
                ;
            }

            row++;
        }
        printf("\n");
        encode_function(m, c, mp);
    }
    return 0;
}
