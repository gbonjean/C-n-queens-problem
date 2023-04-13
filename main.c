#include <stdio.h>

// Number of queens to place
#define N 11

// Print the solution
void  print(int places[N], int *pn)
{
    int     i;
    char    c;

    printf("%d: ", *pn);
    i = 0;
    while (i < N)
    {
        printf("%d ", places[i++]);
    }
    printf("\n");
}

// Testing placement relative to previous queens
int is_place_ok(int row, int col, int places[N])
{
    int i;
    int s;
    int p;

    i = col - 1;
    s = 1;
    while (i >= 0)
    {
        p = places[i];
        if (row == p || row == p + s || row == p - s)
            return (0);
        s++;
        i--;
    }
    return (1);
}

// Backtracking algorithm
void place_queen(int col, int *pn, int places[N])
{
    int i;

    if (col == N)
    {
        *pn += 1;
        print(places, pn);
        return ;
    }
    i = 0;
    while (i < N)
    {
        if (is_place_ok(i, col, places))
        {
            places[col] = i;
            place_queen(col + 1, pn, places);
        }
        i++;
    }
}


int ft_n_queens_puzzle(void)
{
    int places[N];
    int n;
    int *pn;

    n = 0;
    pn = &n;
    place_queen(0, pn, places);
    return(n);
}

int main()
{
    ft_n_queens_puzzle();
    return 0;
}
