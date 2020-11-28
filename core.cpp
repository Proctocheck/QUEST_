#include "core.h"
#include "interface.h"

//забацать изменение количества объектов в настройках, для камней, торговцев и врагов.
//И сделать ещё внутриигровые настройки
//короче пишем всё по другому, сначала заходим в меню->ну там в настроички, с полем рабоем->нью гейм


void Help() {

    system("cls");
    Print_Menu();
    cout << "Coming soon..." << endl << endl << endl << "Press any button..." << endl;
    Print_Menu();
    while(1)
    {
        int c = getch();
        break;
    }
}


void Field::move_hero(int x, int y, vector<int>& way) { //двигает героя в какую-то точку, если в неё можно пробраться

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
                    field[hero/s][hero%s] = GRASS;
                    field[v1/s][v1%s] = HERO;
                    hero = v1;
                    return;
                }
            }
    }

    cout << "FALSE COORD" << endl;
    Sleep(1000);
}

void Field::splitter(int x, int y) { //рассматривает рядом стоящую клетку и вызыввает нужную функцию


    if (x<0 || y<0 || x>8 || y>8)
        return;

    vector<int> d;
    switch(field[x][y])
    {
    case GRASS:
        move_hero(x,y,d);
        break;
    case STONE:
        break;
    case TRADER:
        trade();
        break;
    case ENEMY:
        break;
    }
}

void Field::interf_game() {


    //Hello_Menu();


    while(1) {


        print();
        if (is_prompt)
            cout << "u can use only this keys: arrows - move, 'h' - help, 'esc' - exit\n\n" << endl;
        Invent(inv.inventory);

        int c = getch();
        //cout << c << ' ';
        switch (c) {

        case KEY_UP:
            //cout << hero/s - 1 << ' ' << hero%s << endl;
            splitter(hero/s - 1,hero%s);
            break;
        case KEY_RIGHT:
            // << hero/s << ' ' << hero%s + 1  << endl;
            splitter(hero/s,hero%s + 1);
            break;
        case KEY_LEFT:
            //cout << hero/s << ' ' << hero%s - 1 << endl;
            splitter(hero/s,hero%s - 1);
            break;
        case KEY_DOWN:
            //cout << hero/s + 1 << ' ' << hero%s << endl;
            splitter(hero/s + 1,hero%s);
            break;
        case KEY_ESC:
            system("cls");
            cout << "Exit...";
            return;
        case KEY_H:
            Help();
            break;
        default:
            break;
        }
    }
}
