#ifndef CORE_H
#define CORE_H

#include "header_list.h"

using namespace std;

const int sf = 9;
static bool is_prompt = true;

enum subj
{
    GRASS = 0, HERO, STONE, TRADER, ENEMY
};


struct Inventory
{
    int money;
    int Tier;

    vector<string> inventory;
};


struct Enemy_ch {

    int x;
    int y;
    string type;
    int hp;
    int damage;
};



class Field {

public:
    vector<vector<subj>> field;

    void interf_game();//GAME INTERFACE

    void core_settings();

    int get_size(Field F) {

        return F.s;
    }

    void print() {

        system("cls");
        for (int i=0;i<s;i++)
        {
            for (int j=0;j<s;j++)
                cout << obj[field[i][j]] << "  ";
            cout <<'\n';
        }
        cout <<"\n\n";
    }

    //конструктор для создания поля из файла


    //конструктор для создания поля из стартовых функций
    Field(vector<int> trader, vector<int> enemy, vector<int> stones, int hero, int money)
        : enemy_size(enemy.size()),traders_size(trader.size()),stones_size(stones.size()) {

        field.resize(s);
        g.resize(s*s);

        for(int x = 0; x < s; x++)
            field[x].resize(s);

        for(int i = 0; i < trader.size(); i++)
            field[trader[i]/s][trader[i]%s] =  TRADER;

        for(int i = 0; i < enemy.size(); i++)
            field[enemy[i]/s][enemy[i]%s] =  ENEMY;

        for(int i = 0; i < stones.size(); i++)
            field[stones[i]/s][stones[i]%s] =  STONE;

        field[hero/s][hero%s] =  HERO;

        this->enemy = enemy;

        this->stones = stones;

        this->traders = trader;

        inv.money = money;
        inv.Tier = 1;

        this->hero = hero;
        fill_grahp();
    }

    Field() {

        stones.resize(0);
        stones_size = 0;

        enemy.resize(0);
        enemy_size = 0;

        traders.resize(0);
        traders_size = 0;
    }

    ~Field() {


    }


private:

    vector<string> obj{".","H","#","T","&"};

    int xh, yh;
    int hero;
    int s = sf;

    Inventory inv;


    vector<vector<int>> g;//вектор графа


    void fill_grahp() {

        for(int x = 0; x < s; x++)
            for(int y = 0; y < s; y++)
            {
                if (field[x][y] == STONE)
                    continue;
                if (y<s-1 && field[x][y+1] != STONE)
                {
                    g[x*s + y].push_back(x*s + y+1);
                    g[x*s + y+1].push_back(x*s + y);
                }
                if (y>0 && field[x][y-1] != STONE)
                {
                    g[x*s + y].push_back(x*s + y-1);
                    g[x*s + y-1].push_back(x*s + y);
                }
                if (x>0 && field[x-1][y] != STONE)
                {
                    g[(x-1)*s + y].push_back(x*s + y);
                    g[x*s + y].push_back((x-1)*s + y);
                }
                if (x<s-1 && field[x+1][y] != STONE)
                {
                    g[(x+1)*s + y].push_back(x*s + y);
                    g[x*s + y].push_back((x+1)*s + y);
                }
            }
    }


    void enemy_move(int x, int y);
    void fight();


    void trade();
    void trade_shop();


//    void Coordinates_window(int id, int size, vector<int> elem);
//    void get_coord(vector<int>& v1, vector<int>& v2);
//    void Change_field(vector<int> stones, vector<int> enemy, vector<int> traders, int hero, Field& f);


    void move_hero(int x, int y,vector<int>& d);//функция для перемещения персонажа

    void splitter(int x, int y);//разветвление по функциям, исходя из входных данных


    ///изменяемые вектора
    vector<int> enemy;
    int enemy_size;

    vector<int> stones;
    int stones_size;

    vector<int> traders;
    int traders_size;
};



#endif // CORE_H
