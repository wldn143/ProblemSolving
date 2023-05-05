#include <iostream>
#include <algorithm>
using namespace std;
int n, m, b, map[250001], max_hight, min_time = 64000001, result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> b;
    for (int i = 0; i < n * m; i++)
    {
        cin >> map[i];
        b += map[i];
    }

    max_hight = b / (n * m);

    for (int i = 0; i <= max_hight; i++)
    {
        int tmp = 0;

        for (int j = 0; j < n * m; j++)
        {
            if (map[j] > i)
                tmp += (map[j] - i) * 2;
            else if (map[j] < i)
                tmp += (i - map[j]);
        }
        if (tmp <= min_time)
        {
            min_time = tmp;
            result = i;
        }
    }
    cout << min_time << " " << result;
}