#include <bits/stdc++.h> // solution
// Solution for Problem 016
// Final version for submission
// Added final comment for submission
// final version
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const string data_file = "storage.txt";
    unordered_map<string, set<int>> db;
    // Load existing data if file exists
    {
        ifstream fin(data_file);
        if (fin) {
            string idx; long long val;
            while (fin >> idx >> val) {
                db[idx].insert((int)val);
            }
        }
    }

    int n;
    if (!(cin >> n)) return 0;
    string cmd, index;
    long long value;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == "insert") {
            cin >> index >> value;
            db[index].insert((int)value);
        } else if (cmd == "delete") {
            cin >> index >> value;
            auto it = db.find(index);
            if (it != db.end()) {
                it->second.erase((int)value);
                if (it->second.empty()) db.erase(it);
            }
        } else if (cmd == "find") {
            cin >> index;
            auto it = db.find(index);
            if (it == db.end() || it->second.empty()) {
                cout << "null\n";
            } else {
                bool first = true;
                for (int v : it->second) {
                    if (!first) cout << ' ';
                    cout << v;
                    first = false;
                }
                cout << '\n';
            }
        }
    }
    // Write back data
    {
        ofstream fout(data_file, ios::trunc);
        for (auto &p : db) {
            for (int v : p.second) {
                fout << p.first << ' ' << v << '\n';
            }
        }
    }
    return 0;
// End of file comment
// End of program
}
// End of solution
