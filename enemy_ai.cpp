#include "core.h"
///ЛУЧШЕ ВСЕГО ТУТ СДЕЛАТЬ А*, ХОТЯ ГРАФ НЕ ВЗВЕШАННЫЙ
void move(vector<vector<int>> g, int x, int y, vector<int>& way, int hero, int s) { //двигает врага в сторону героя

    int v0 = hero,v1 = x*s+y;

    vector<int> par(s*s,-1);
    vector<bool> is_vis(g.size(),false);
    queue<int> q;
    vector<int> d(s*s);

    q.push(v0);
    d[v0] = 0;
    is_vis[v0] = true;
    while(!q.empty()) {

        int v = q.front();
        q.pop();
        is_vis[v] = true;
        for(int i: g[v])
            if (is_vis[i] == false)
            {
                par[i] = v;
                q.push(i);
                d[i] = d[v] + 1;
                is_vis[i] = true;

                if (i == v1)
                {
                    way.push_back(v);
                    while(v != v0)
                    {
                        way.push_back(par[v]);
                        v = par[v];
                    }
                    reverse(way.begin(),way.end());
                    return;
                }
            }
    }

    cout << "FALSE COORD" << endl;
    Sleep(1000);
}

void Field::enemy_move(int type, int num, int x, int y) {

    vector<int> ver;

    if (ver.size() != 1) {

        int d = ver[0];
        field[d/s][d%s] = ENEMY;
        field[x][y] = GRASS;
    }

}


void Field::fight() {


}
