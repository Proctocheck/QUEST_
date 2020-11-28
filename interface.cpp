#include "interface.h"

void Print_Menu() {

    for(int i=0;i<5;i++)
        cout << "########################################################################################"
             << "################################";
}

void Invent(vector<string> inv) {

    for(size_t i = 0; i < inv.size(); i++)
        cout << "     | " << inv[i] << " |";
    cout << endl;
}

void Hello_Menu() {

    system("cls");
    cout << endl << endl << endl
         << "                                          The" << endl;
    Sleep(1000);
    cout << "                                          Game" << endl;
    Sleep(1000);
    cout << "                                          Starts" << endl;
    Sleep(1000);
    cout << "                                          Now" << endl;
    Sleep(1000);
    cout << "                                       ";
    for(int i = 0; i < 11; i++)
    {
        cout << '.';
        Sleep(200);
    }

    system("cls");
}

void Field::core_settings() {

    vector<string> s(5,_here);
    s[0] = here;
    int id = 0;
    while(1) {

        system("cls");

        Print_Menu();
        cout << s[0] << "Number of stones"  << '<' << stones_size << '>' << endl
                     << s[1] << "Number of enemies" << '<' << enemy_size << '>' << endl
                     << s[2] << "Number of traders" << '<' << traders_size << '>' << endl << endl
                     << s[3] << "Coordinates" << endl << endl
                     << s[4] << "Exit" << endl;
        Print_Menu();

        int c = getch();
        switch (c) {

        case KEY_DOWN:
            s[id] = _here;
            if (id == s.size()-1) {

                s[0] = here;
                id = 0;
            }
            else {

                s[id+1] = here;
                id++;
            }
            break;
        case KEY_UP:
            s[id] = _here;
            if (id == 0) {

                s[s.size()-1] = here;
                id = s.size()-1;
            }
            else {

                s[id-1] = here;
                id--;
            }
            break;
        case KEY_LEFT:
            switch (id) {

            case 0:
                if (stones_size != 0) {

                    stones_size--;
                    stones.pop_back();
                }
                break;
            case 1:
                if (enemy_size != 0) {

                    enemy_size--;
                    enemy.pop_back();
                }
                break;
            case 2:
                if (traders_size != 0) {

                    traders_size--;
                    traders.pop_back();
                }
                break;
            }
            break;
        case KEY_RIGHT:
            switch (id) {

            case 0:
                stones_size++;
                stones.push_back(0);
                break;
            case 1:
                enemy_size++;
                enemy.push_back(0);
                break;
            case 2:
                traders_size++;
                traders.push_back(0);
                break;
            }
            break;
        case KEY_ESC:
            system("cls");
            return;
        case KEY_ENTER:
            switch (id) {

            case 0:
                is_prompt = !is_prompt;
                break;
            case 1:
                //f.Field_Settings(f);
                break;
            case 4:
                return;
            }
            break;
        }
    }
}

void Settings(Field& f)
{
    system("cls");

    vector<string> s(3);
    s[0] = here;
    s[1] = _here;
    s[2] = _here;
    int id = 0;
    while(1) {

        Print_Menu();
        cout << s[0] << "Prompt   " << (is_prompt ? "ON" : "OFF") << endl << s[1] << "Advantage settings" << endl << endl << s[2] << "Exit" << endl;
        Print_Menu();
        int c = getch();

        string s1;

        switch (c) {

        case KEY_DOWN:
            s[id] = _here;
            if (id == s.size()-1) {

                s[0] = here;
                id = 0;
            }
            else {

                s[id+1] = here;
                id++;
            }
            break;
        case KEY_UP:
            s[id] = _here;
            if (id == 0) {

                s[s.size()-1] = here;
                id = s.size()-1;
            }
            else {

                s[id-1] = here;
                id--;
            }
            break;
        case KEY_ESC:
            system("cls");
            return;
        case KEY_ENTER:
            switch (id)
            {
            case 0:
                is_prompt = !is_prompt;
                break;
            case 1:
                //f.core_settings();
                break;
            case 2:
                return;
            }
            break;
        }
        system("cls");
    }
}

void MainMenu() {

    system("cls");
    vector<int> q(0);
    vector<int> q2(1,0);
    vector<int> q1(1,14);
    Field f(q1,q2,q,2,rand()%101);

    vector<string> s(5,_here);
    s[0] = here;

    int id = 0;

    while(1) {

        Print_Menu();
        cout << endl;
        cout << s[0] << "New game" << endl << s[1] << "Continue" << endl << endl << s[2] << "Settings" << endl << s[3] <<  "Map redactor" << endl << endl << s[4] << "Exit" << endl;
        Print_Menu();

        int c = getch();


        switch (c) {

        case KEY_DOWN:
            s[id] = _here;
            if (id == s.size()-1) {

                s[0] = here;
                id = 0;
            }
            else {

                s[id+1] = here;
                id++;
            }
            break;
        case KEY_UP:
            s[id] = _here;
            if (id == 0) {

                s[s.size()-1] = here;
                id = s.size()-1;
            }
            else {

                s[id-1] = here;
                id--;
            }
            break;
        case KEY_ESC:
            system("cls");
            return;
        case KEY_ENTER:
            switch (id)
            {
            case 4:
                system("cls");
                return;
            case 3:
                f.core_settings();
                break;
            case 2:
                Settings(f);
                break;
            case 1:
                break;
            case 0:
                f.interf_game();
                return;
            }
            //else Settings(f);
            break;
        }



        system("cls");
    }


}
