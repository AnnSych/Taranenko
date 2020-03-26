#include <iostream>
#include <windows.h>
#include <math.h>
#include <ctime>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdio.h>
/*#include <cstdlib>
#include "Source.h"*/
using namespace std;
const int N = 10;
int Ships_id = 1;

int main() {
       

    void set_rand_ships(int map[N][N], int size_ship, int num_ships);
        {
            int x, y;
            int dir = 0;
            int count_ship = 0;
            int count_tact = 0;

            while (count_ship < num_ships)
            {
                count_tact++;

                if (count_tact > 1000)
                {
                    break;
                }

                //генерация первичной позиции
                x = rand() % N;
                y = rand() % N;

                int temp_x = x;
                int temp_y = y;

                //генерация направления
                dir = rand() % 4;

                bool setting_is_possible = 1;

                //проверка возможности постановки корабля
                for (int i = 0; i < size_ship; i++)
                {

                    if (x < 0 || y < 0 || x >= N || y >= N)
                    {
                        setting_is_possible = 0;
                        break;
                    }

                    if (map[x][y] == 1 ||
                        map[x][y + 1] == 1 ||
                        map[x][y - 1] == 1 ||
                        map[x + 1][y] == 1 ||
                        map[x + 1][y + 1] == 1 ||
                        map[x + 1][y - 1] == 1 ||
                        map[x - 1][y] == 1 ||
                        map[x - 1][y + 1] == 1 ||
                        map[x - 1][y - 1] == 1)

                    {
                        setting_is_possible = 0;
                        break;
                    }

                    switch (dir)
                    {
                    case 0:
                        x++;
                        break;
                    case 1:
                        y++;
                        break;
                    case 2:
                        x--;
                        break;
                    case 3:
                        y--;
                        break;
                    }

                }

                //ставим корабль, если есть возможность
                if (setting_is_possible == 1)
                {
                    x = temp_x;
                    y = temp_y;

                    for (int i = 0; i < size_ship; i++)
                    {
                        map[x][y] = 1;


                        switch (dir)
                        {
                        case 0:
                            x++;
                            break;
                        case 1:
                            y++;
                            break;
                        case 2:
                            x--;
                            break;
                        case 3:
                            y--;
                            break;
                        }
                    }

                    count_ship++;

                }
            }
        }
        void map_show(int map[N][N], int mask[N][N]);
        {
            //прорисовка
            cout << ' ';

            for (int i = 0; i < N; i++)
            {
                cout << i;
            }
            cout << endl;


            for (int i = 0; i < N; i++)
            {
                cout << i;

                for (int j = 0; j < N; j++)
                {
                    if (mask[j][i] == 1)
                    {
                        if (map[j][i] == 0)
                        {
                            cout << '-';
                        }
                        else
                        {
                            cout << map[j][i];
                        }
                    }
                    else
                    {
                        cout << ' ';
                    }

                }
                cout << endl;
            }
        }


        int _tmain(int argc, _TCHAR* argv[]);
        {
            setlocale(LC_ALL, "rus");


            while (true)
            {
                int map[N][N] = { 0 };
                int mask[N][N] = { 0 };

                set_rand_ships(map, 4, 1);
                set_rand_ships(map, 3, 2);
                set_rand_ships(map, 2, 3);
                set_rand_ships(map, 1, 4);

                int x = 0, y = 0;

                while (true)
                {
                    map_show(map, mask);
                    cout << endl << "enter target coordinates: " << endl;

                    cin >> x;
                    cin >> y;

                    if (map[x][y] == 1)
                    {
                        cout << "hit" << endl;
                    }
                    else
                    {
                        cout << "blunder" << endl;
                    }
                    mask[x][y] = 1;

                    Sleep(1000);
                    system("cls");
                }


                getch();
                system("cls");
            }

            system("pause");
            return 0;
        }
