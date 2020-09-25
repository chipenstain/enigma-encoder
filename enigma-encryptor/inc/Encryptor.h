#pragma once
#include "Rotor.h"

static class Encryptor
{
public:
    Encryptor();
    void AddRotor(Rotor rotor, bool isReflector = false);
    Rotor GetRotor(int id, bool isReflector = false);
    Rotor GetActivRotor(int id = 0, bool isReflector = false);
    void SetRotor(Rotor rotor, bool isReflector = false, int id = 0);
    void SetActivRotor(Rotor rotor, int id);
    void SetRotors(Rotor* rotors);
    void SetReflector(Rotor reflector);
    char Encrypt(char s);
    void ChangeStyle(bool style4);

private:
    vector<Rotor> rotors;
    vector<Rotor> reflectors;

    Rotor activRotor[4];
    Rotor activReflector;

    bool is4StyleEnigma = false;

    int GetIdOfKey(char s, vector<char> keyboard);
};