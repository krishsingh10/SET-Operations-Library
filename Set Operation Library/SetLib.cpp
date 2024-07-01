#include <iostream>
#include <vector>
using namespace std;

class SET {
private:
    vector<vector<int>> sets;

public:
    int Insert(int setNum, int setdata) {
        if (setNum >= sets.size()) {
            sets.resize(setNum + 1, {});
        }
        vector<int>& initialset = sets[setNum];
        for (int i = 0; i < initialset.size(); i++) {
            if (initialset[i] == setdata) {
                return initialset.size();
            } else if (initialset[i] > setdata) {
                initialset.insert(initialset.begin() + i, setdata);
                return initialset.size();
            }
        }
        initialset.push_back(setdata);
        return initialset.size();
    }

    int Size(int setNum);

    int Delete(int setNum, int setdata) {
        if (setNum >= 0 && setNum < sets.size()) {
            vector<int>& initialset = sets[setNum];
            for (int i = 0; i < initialset.size(); i++) {
                if (initialset[i] == setdata) {
                    initialset.erase(initialset.begin() + i);
                    return initialset.size();
                }
            }
            return initialset.size();
        }
        return -1;
    }

    int Belongsto(int setNum, int setdata) {
        if (setNum >= 0 && setNum < sets.size()) {
            vector<int>& initialset = sets[setNum];
            for (int i = 0; i < initialset.size(); i++) {
                if (initialset[i] == setdata) {
                    return 1;
                }
            }
            return 0;
        }
        return -1;
    }

    int Union(int setnum1, int setnum2) {
        if (setnum1 >= sets.size()) {
            sets.resize(setnum1 + 1, {});
        }
        if (setnum2 >= sets.size()) {
            sets.resize(setnum2 + 1, {});
        }
        vector<int>& set1 = sets[setnum1];
        vector<int>& set2 = sets[setnum2];
        int i = 0;
        int j = 0;
        vector<int> unionele;
        while (i < set1.size() && j < set2.size()) {
            if (set1[i] < set2[j]) {
                unionele.push_back(set1[i]);
                i++;
            } else if (set1[i] > set2[j]) {
                unionele.push_back(set2[j]);
                j++;
            } else {
                unionele.push_back(set1[i]);
                i++;
                j++;
            }
        }
        while (i < set1.size()) {
            unionele.push_back(set1[i]);
            i++;
        }
        while (j < set2.size()) {
            unionele.push_back(set2[j]);
            j++;
        }
        sets[setnum1] = unionele;
        return sets[setnum1].size();
    }

    int Intersection(int setnum1, int setnum2);

    int Difference(int setnum1, int setnum2) {
        if (setnum1 >= sets.size() || setnum2 >= sets.size()) {
            sets.resize(max(setnum1, setnum2) + 1, {});
        }
        vector<int>& set1 = sets[setnum1];
        vector<int>& set2 = sets[setnum2];
        vector<int> indicesToDelete;

        int i = 0, j = 0;
        while (i < set1.size() && j < set2.size()) {
            if (set1[i] < set2[j]) {
                i++;
            } else if (set1[i] > set2[j]) {
                j++;
            } else {
                set1.erase(set1.begin() + i);
            }
        }

        return set1.size();
    }

    int SymmetricDifference(int setnum1, int setnum2) {
        if (setnum1 >= sets.size() || setnum2 >= sets.size()) {
            sets.resize(max(setnum1, setnum2) + 1, {});
        }
        vector<int>& set1 = sets[setnum1];
        vector<int>& set2 = sets[setnum2];
        vector<int> symetricdiff;
        int i = 0, j = 0;
        while (i < set1.size() && j < set2.size()) {
            if (set1[i] < set2[j]) {
                symetricdiff.push_back(set1[i]);
                i++;
            } else if (set1[i] > set2[j]) {
                symetricdiff.push_back(set2[j]);
                j++;
            } else {
                i++;
                j++;
            }
        }
        while (i < set1.size()) {
            symetricdiff.push_back(set1[i]);
            i++;
        }
        while (j < set2.size()) {
            symetricdiff.push_back(set2[j]);
            j++;
        }
        sets[setnum1] = symetricdiff;
        return symetricdiff.size();
    }

    void Print(int setnum) {
        if (setnum >= sets.size() || sets[setnum].size() == 0) {
            cout << endl;
            return;
        }
        vector<int>& initialset = sets[setnum];
        for (int i = 0; i < initialset.size() - 1; i++) {
            cout << initialset[i] << ",";
        }
        cout << initialset[initialset.size() - 1] << endl;
    }
};

int SET::Size(int setNum) {
    if (setNum >= sets.size()) {
        sets.resize(setNum + 1, {});
        return 0;
    }
    return sets[setNum].size();
}

int SET::Intersection(int setnum1, int setnum2) {
    if (setnum1 >= sets.size() || setnum2 >= sets.size()) {
        sets.resize(max(setnum1, setnum2) + 1, {});
    }
    vector<int>& set1 = sets[setnum1];
    vector<int>& set2 = sets[setnum2];
    int i = 0;
    int j = 0;
    vector<int> intersectionele;
    while (i < set1.size() && j < set2.size()) {
        if (set1[i] == set2[j]) {
            intersectionele.push_back(set1[i]);
            i++;
            j++;
        } else if (set1[i] < set2[j]) {
            i++;
        } else if (set1[i] > set2[j]) {
            j++;
        }
    }

    sets[setnum1] = intersectionele;
    return sets[setnum1].size();
}

int main() {
    SET setLibrary;
    int checknum;
    while (cin >> checknum && checknum != 0) {
        if (checknum == 6 || checknum == 9) {
            int num;
            cin >> num;
            switch (checknum) {
            case 6:
                cout << setLibrary.Size(num) << endl;
                break;
            case 9:
                setLibrary.Print(num);
                break;
            }
        } else {
            switch (checknum) {
            case 1: {
                int setNum, setdata;
                cin >> setNum >> setdata;
                int a = setLibrary.Insert(setNum, setdata);
                cout << a << endl;
                break;
            }
            case 2: {
                int setNum, setdata;
                cin >> setNum >> setdata;
                int a = setLibrary.Delete(setNum, setdata);
                cout << a << endl;
                break;
            }
            case 3: {
                int setNum, setdata;
                cin >> setNum >> setdata;
                int a = setLibrary.Belongsto(setNum, setdata);
                cout << a << endl;
                break;
            }
            case 4: {
                int setnum1, setnum2;
                cin >> setnum1 >> setnum2;
                int a = setLibrary.Union(setnum1, setnum2);
                cout << a << endl;
                break;
            }
            case 5: {
                int setnum1, setnum2;
                cin >> setnum1 >> setnum2;
                int a = setLibrary.Intersection(setnum1, setnum2);
                cout << a << endl;
                break;
            }
            case 7: {
                int setnum1, setnum2;
                cin >> setnum1 >> setnum2;
                int diffSize = setLibrary.Difference(setnum1, setnum2);
                cout << diffSize << endl;
                break;
            }
            case 8: {
                int setnum1, setnum2;
                cin >> setnum1 >> setnum2;
                int symDiffSize = setLibrary.SymmetricDifference(setnum1, setnum2);
                cout << symDiffSize << endl;
                break;
            }
            default:
                return 0;
            }
        }
    }
    return 0;
}
