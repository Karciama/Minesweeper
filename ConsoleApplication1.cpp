#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector <vector <int>> ms;
class bazine
{
protected:
    int sunk, n, m, minos, minosplaced, zaidI, zaidJ, galas;

public:
    bazine() :n(0), m(0), minosplaced(0), minos(0), sunk(0),zaidI(0),zaidJ(0),galas(0){}
    bazine(int x, int y, int z, int c, int v):sunk(x),n(y),m(z),minos(c){}
        ~bazine(){}
    void ivedsunk() {
        cin >> sunk;
    }
    void operator -() {
        cin >> m >> n >> minos;
    }
    void sunkcheck(int sunk) {
        switch (sunk) {
        case 1:
            m = 9;
            n = 9;
            minos = 10;
            system("cls");
            break;
        case 2:
            m = 16;
            n = 16;
            minos = 40;
            system("cls");
            break;
        case 3:
            m = 24;
            n = 24;
            minos = 99;
            system("cls");
            break;
        case 4:
            cout << "Ok, iveskite eiluciu, stulpeliu ir minu skaiciu" << endl;
            -(*this);
            system("cls");
            break;
        default:
            break;
        }
    }


};
class sweep:public bazine {
public:
    sweep() : bazine() {}
    void minuskirstymas(vector<vector<int>>& ms) {
        time_t laikas = time(nullptr);
        srand(laikas);
        for (int i = 0; i < minos; ++i) {
            int eil = rand() % n;
            int stul = rand() % m;
            if (ms[eil][stul] == -2)
            {
                --i;
            }
            ms[eil][stul] = -2;
        }
    }
    void langeliuuzklojimas(vector<vector<int>>& ms) {
        int aha = -1;
        int n = getn();
        int m = getm();
        ms.resize(n);
        for (int i = 0; i < n; i++) {
            ms[i].resize(m);
            fill(ms[i].begin(), ms[i].end(), aha);
        }
    }


    void loss(vector <vector <int>>& ms) {
        system("cls");
        cout << "boom, game over\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ms[i][j] == -1)
                    cout << "- ";
                else if (ms[i][j] == 0)
                    cout << 0 << " ";
                else if (ms[i][j] == 1)
                    cout << 1 << " ";
                else if (ms[i][j] == 2)
                    cout << 2 << " ";
                else if (ms[i][j] == 3)
                    cout << 3 << " ";
                else if (ms[i][j] == 4)
                    cout << 4 << " ";
                else if (ms[i][j] == 5)
                    cout << 5 << " ";
                else if (ms[i][j] == 6)
                    cout << 6 << " ";
                else if (ms[i][j] == 7)
                    cout << 7 << " ";
                else if (ms[i][j] == 8)
                    cout << 8 << " ";
                else if (ms[i][j] == -2)
                    cout << "X ";
                if (j == m - 1)
                    cout << endl;
                if (i == n - 1 && j == m - 1)
                    exit(0);
            }
        }
    }
    void nemina(vector<vector<int>>& ms, int zaidI, int zaidJ) {
        system("cls");
        if (zaidI == 0 && zaidJ == 0)
        {
            int bomba = 0;
            if (ms[zaidI + 1][zaidJ] == -2)
                ++bomba;
            if (ms[zaidI][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ + 1] == -2)
                ++bomba;
            ms[zaidI][zaidJ] = bomba;
        }
        if (zaidI == n - 1 && zaidJ == 0)
        {
            int bomba = 0;
            if (ms[zaidI - 1][zaidJ] == -2)
                ++bomba;
            if (ms[zaidI][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ + 1] == -2)
                ++bomba;
            ms[zaidI][zaidJ] = bomba;

        }
        if (zaidI == 0 && zaidJ == m - 1)
        {
            int bomba = 0;
            if (ms[zaidI + 1][zaidJ] == -2)
                ++bomba;
            if (ms[zaidI][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ - 1] == -2)
                ++bomba;
            ms[zaidI][zaidJ] = bomba;
        }
        if (zaidI == n - 1 && zaidJ == m - 1)
        {
            int bomba = 0;
            if (ms[zaidI - 1][zaidJ] == -2)
                ++bomba;
            if (ms[zaidI][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ - 1] == -2)
                ++bomba;
            ms[zaidI][zaidJ] = bomba;
        }
        if (zaidI == 0 && zaidJ > 0 && zaidJ < m - 1)
        {
            int bomba = 0;
            if (ms[zaidI][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ] == -2)
                ++bomba;
            ms[zaidI][zaidJ] = bomba;
        }
        if (zaidI > 0 && zaidI < n - 1 && zaidJ == 0)
        {
            int bomba = 0;
            if (ms[zaidI][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ] == -2)
                ++bomba;
            ms[zaidI][zaidJ] = bomba;
        }
        if (zaidI > 0 && zaidI < n - 1 && zaidJ == m - 1)
        {
            int bomba = 0;
            if (ms[zaidI - 1][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ] == -2)
                ++bomba;
            ms[zaidI][zaidJ] = bomba;
        }
        if (zaidI == n - 1 && zaidJ > 0 && zaidJ < m - 1)
        {
            int bomba = 0;
            if (ms[zaidI][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ] == -2)
                ++bomba;
            ms[zaidI][zaidJ] = bomba;
        }
        if (zaidI > 0 && zaidI < n - 1 && zaidJ>0 && zaidJ < m - 1)
        {
            int bomba = 0;
            if (ms[zaidI - 1][zaidJ] == -2)
                ++bomba;
            if (ms[zaidI][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ - 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ] == -2)
                ++bomba;
            if (ms[zaidI][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI - 1][zaidJ + 1] == -2)
                ++bomba;
            if (ms[zaidI + 1][zaidJ - 1] == -2)
                ++bomba;
            ms[zaidI][zaidJ] = bomba;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (ms[i][j] == -1 || ms[i][j] == -2)
                    cout << "- ";
                else if (ms[i][j] == 0)
                    cout << 0 << " ";
                else if (ms[i][j] == 1)
                    cout << 1 << " ";
                else if (ms[i][j] == 2)
                    cout << 2 << " ";
                else if (ms[i][j] == 3)
                    cout << 3 << " ";
                else if (ms[i][j] == 4)
                    cout << 4 << " ";
                else if (ms[i][j] == 5)
                    cout << 5 << " ";
                else if (ms[i][j] == 6)
                    cout << 6 << " ";
                else if (ms[i][j] == 7)
                    cout << 7 << " ";
                else if (ms[i][j] == 8)
                    cout << 8 << " ";
                if (j == m - 1)
                    cout << endl;

            }
        }
    }
    void nuliurekursija(vector<vector<int>>& ms, int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || ms[i][j] != -1) return; 
        nemina(ms, i, j);
        if (ms[i][j] > 0) return;
        nuliurekursija(ms, i - 1, j - 1);
        nuliurekursija(ms, i - 1, j);
        nuliurekursija(ms, i - 1, j + 1);
        nuliurekursija(ms, i, j - 1);
        nuliurekursija(ms, i, j + 1);
        nuliurekursija(ms, i + 1, j - 1);
        nuliurekursija(ms, i + 1, j);
        nuliurekursija(ms, i + 1, j + 1);
    }
    void endcheck(vector<vector<int>>& ms) {
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < m; ++b) {
                if (a == 0 && b == 0)
                    galas = 0;
                if (ms[a][b] == -1)
                    ++galas;
                if (a == n - 1 && b == m - 1 && galas == 0)
                {
                    system("cls");
                    for (int y = 0; y < n; ++y) {
                        for (int r = 0; r < m; ++r) {
                            if (ms[y][r] == -1)
                                cout << "- ";
                            else if (ms[y][r] == 0)
                                cout << 0 << " ";
                            else if (ms[y][r] == 1)
                                cout << 1 << " ";
                            else if (ms[y][r] == 2)
                                cout << 2 << " ";
                            else if (ms[y][r] == 3)
                                cout << 3 << " ";
                            else if (ms[y][r] == 4)
                                cout << 4 << " ";
                            else if (ms[y][r] == 5)
                                cout << 5 << " ";
                            else if (ms[y][r] == 6)
                                cout << 6 << " ";
                            else if (ms[y][r] == 7)
                                cout << 7 << " ";
                            else if (ms[y][r] == 8)
                                cout << 8 << " ";
                            else if (ms[y][r] == -2)
                                cout << "X ";
                            if (r == m - 1)
                                cout << endl;
                        }
                    }
                    cout << "Didziausi sveikinimai!\n";
                    exit(0);
                }
            }
        }
    }
    int getsunk() {
        return sunk;
    }
    int getn() {
        return n;
    }
    int getm() {
        return m;
    }

};
int main(){
    sweep mine;
    int sunk(0), sunk0(0), zaidI(0), zaidJ(0), galas(0), n(0), m(0), minos(0);
    cout << "Pasirinkite sunkumo lygi (1, 2, 3 ir 4 jei norit patys susikurti)\n";
    mine.ivedsunk();
    sunk = mine.getsunk();
    mine.sunkcheck(sunk);
    n = mine.getn();
    m = mine.getm();
    mine.langeliuuzklojimas(ms);
    mine.minuskirstymas(ms);
    if (sunk != 0) {
        cout << "Iveskite eilute ir stulpeli kad atidarytumete laukelius.\n";
        while(true) {
            cin >> zaidI >> zaidJ;
            if (zaidI < 0 || zaidI >= n || zaidJ < 0 || zaidJ >= m) {
                cout << "Neteisingas inputas, is naujo.\n";
                continue;
            }
            if (ms[zaidI][zaidJ] == -2)
            {
                mine.loss(ms);
            }
            else if (ms[zaidI][zaidJ] == -1)
            {
                mine.nuliurekursija(ms, zaidI, zaidJ);
            }
            mine.endcheck(ms);
        }
    }

    return 0;
}