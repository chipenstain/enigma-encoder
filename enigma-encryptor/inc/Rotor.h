#pragma once
#include "includes.h"

struct Rotor
{
    string name;
    string language;
    vector<int> triggers;

    int position;
    vector<char> in;
    vector<char> out;

    Rotor();
};