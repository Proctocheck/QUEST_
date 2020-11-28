#ifndef INTERFACE_H
#define INTERFACE_H
#include "core.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_H 104



static const string here = "-> ";
static const string _here = "   ";

void Print_Menu();

void Invent(vector<string> inv);

void Hello_Menu();

void Advance_field_sett(Field& f);

void Settings(Field& f);

void MainMenu();

#endif // INTERFACE_H
