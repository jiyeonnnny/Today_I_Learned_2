#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int n, m, tgtIdx;
        cin >> n >> m >> tgtIdx;

        list<int> linkedList;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            linkedList.push_back(num);
        }

        for (int i = 0; i < m; i++)
        {
            string cmd;
            cin >> cmd;

            if (cmd == "I")
            {
                int x, y;
                cin >> x >> y;

                auto it = linkedList.begin();
                advance(it, x);
                linkedList.insert(it, y);
            }
            else if (cmd == "D")
            {
                int x;
                cin >> x;

                auto it = linkedList.begin();
                advance(it, x);
                linkedList.erase(it);
            }
            else if (cmd == "C")
            {
                int x, y;
                cin >> x >> y;

                auto it = linkedList.begin();
                advance(it, x);
                *it = y;
            }
        }

        if (linkedList.size() > tgtIdx)
        {
            auto it = linkedList.begin();
            advance(it, tgtIdx);
            cout << "#" << tc << " " << *it << endl;
        }
        else
        {
            cout << "#" << tc << " " << -1 << endl;
        }
    }

    return 0;
}
