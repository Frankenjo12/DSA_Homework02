#include "game_of_life.h"
#include <ctime>

bool game_of_life::random_value()
{
    int n = rand() % 4 + 1;
    if (n == 1)
        return true;
    return false;
}

bool game_of_life::cell_taken(int j, int i)
{
    if (j >= 0 && j < COLS && i >= 0 && i < ROWS && _generation[i][j] == '*')
        return true;
    return false;
}

game_of_life::game_of_life()
{
    srand(time(nullptr));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (random_value())
            {
                _generation[i][j] = '*';
            }
            else
            {
                _generation[i][j] = '_';
            }
        }
    }
}

void game_of_life::next_generation()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbor = 0;

            if (cell_taken(j - 1, i - 1))
                neighbor++;
            if (cell_taken(j, i - 1))
                neighbor++;
            if (cell_taken(j + 1, i - 1))
                neighbor++;
            if (cell_taken(j - 1, i))
                neighbor++;
            if (cell_taken(j + 1, i))
                neighbor++;
            if (cell_taken(j - 1, i + 1))
                neighbor++;
            if (cell_taken(j, i + 1))
                neighbor++;
            if (cell_taken(j + 1, i + 1))
                neighbor++;

            if (cell_taken(j, i))
            {
                if (neighbor < 2 || neighbor > 3)
                    _next_generation[i][j] = '_';
                else
                    _next_generation[i][j] = '*';
            }
            else
            {
                if(neighbor == 3)
                    _next_generation[i][j] = '*';
                else
                    _next_generation[i][j] = '_';
            }
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            _generation[i][j] = _next_generation[i][j];
        }
    }
}

void game_of_life::draw()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << _generation[i][j] << " ";
        }
        cout << endl;
    }
}
