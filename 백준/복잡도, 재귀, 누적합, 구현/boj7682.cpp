#include <iostream>
#include <algorithm>
#include <string>
#define MAX 987654321
using namespace std;
string input;
char map[10][10];
int x_connect[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
int y_connect[3][3] = {{0, 3, 6}, {1, 4, 7}, {2, 5, 8}};
int z_connect[2][3] = {{0, 4, 8}, {2, 4, 6}};
int main()
{
    while (1)
    {
        cin >> input;
        if (input == "end")
            break;
        int xcnt = 0;
        int ocnt = 0;

        for (char c : input)
        {
            if (c == 'X')
                xcnt++;
            else if (c == 'O')
                ocnt++;
        }

        if (xcnt == ocnt || xcnt == (ocnt + 1))
        {
            int xwin = 0;
            int owin = 0;

            for (int i = 0; i < 3; i++)
            {
                char c = input[x_connect[i][0]];
                if (c == input[x_connect[i][1]] && c == input[x_connect[i][2]])
                {
                    if (c == 'X')
                        xwin++;
                    if (c == 'O')
                        owin++;
                }
                c = input[y_connect[i][0]];
                if (c == input[y_connect[i][1]] && c == input[y_connect[i][2]])
                {
                    if (c == 'X')
                        xwin++;
                    if (c == 'O')
                        owin++;
                }
            }
            for (int i = 0; i < 2; i++)
            {
                char c = input[z_connect[i][0]];
                if (c == input[z_connect[i][1]] && c == input[z_connect[i][2]])
                {
                    if (c == 'X')
                        xwin++;
                    if (c == 'O')
                        owin++;
                }
            }

            if ((xwin + owin) > 2)
            {
                cout << "invalid\n";
                continue;
            }

            if (xwin + owin == 0 && (xcnt + ocnt) < 9)
            {
                cout << "invalid\n";
                continue;
            }

            if (owin && (xcnt != ocnt))
            {
                cout << "invalid\n";
                continue;
            }

            if (xwin && (xcnt == ocnt))
            {
                cout << "invalid\n";
                continue;
            }

            cout << "valid\n";
        }
        else
            cout << "invalid\n";
    }
}
