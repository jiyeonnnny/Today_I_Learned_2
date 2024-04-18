#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void func(vector<int>& list, char cmd, int x, stringstream& st)
{
    int y;
    switch (cmd)
    {
    case 'I':
        st >> y;
        for (int i = 0, insertIdx = x; i < y; i++, insertIdx++)
        {
            int k;
            st >> k;
            list.insert(list.begin() + insertIdx, k);
        }
        break;
    case 'D':
        st >> y;
        for (int i = 0; i < y; i++)
        {
            list.erase(list.begin() + x);
        }
        break;
    case 'A':
        for (int i = 0; i < x; i++)
        {
            st >> y;
            list.push_back(y);
        }
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stringstream sb;

    for (int tt = 1; tt <= 10; tt++)
    {
        vector<int> list;
        int N;
        cin >> N;
        cin.ignore();

        string line;
        getline(cin, line);
        stringstream st(line);

        for (int i = 0; i < N; i++)
        {
            int num;
            st >> num;
            list.push_back(num);
        }

        int Q;
        cin >> Q;
        cin.ignore();

        getline(cin, line);
        stringstream st2(line);

        for (int i = 0; i < Q; i++)
        {
            char cmd;
            st2 >> cmd;
            int x;
            st2 >> x;
            func(list, cmd, x, st2);
        }

        cout << "#" << tt;
        for (int i = 0; i < 10; i++)
        {
            cout << " " << list[i];
        }
        cout << "\n";
    }

    return 0;
}
