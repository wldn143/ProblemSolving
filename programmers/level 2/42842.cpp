#include <vector>
using namespace std;
int row = 2, column, tmp;
vector<int> solution(int brown, int yellow)
{
    while (tmp != yellow)
    {
        row++;
        column = (brown - row * 2) / 2;
        tmp = column * (row - 2);
    }
    return vector<int>{column + 2, row};
}