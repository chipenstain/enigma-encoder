#include "../inc/Encryptor.h"

Encryptor::Encryptor() {}

char Encryptor::Encrypt(char s)
{
    if (activRotor[0].position < (int)activRotor[0].in.size() - 1) activRotor[0].position++;
    else activRotor[0].position = 0;

    char key = toupper(s);
    int idKey = 0;

    idKey = GetIdOfKey(key, activRotor[0].in); //получить позицию символа в алфавите

    //алгоритм первого ротора
    idKey += activRotor[0].position;
    if (idKey >= (int)activRotor[0].in.size()) idKey -= (int)activRotor[2].in.size();
    else if (idKey < 0) idKey += (int)activRotor[2].in.size();
    key = activRotor[0].out[idKey];

    idKey = GetIdOfKey(key, activRotor[1].in);

    //алгоритм второго ротора
    idKey += (activRotor[1].position - activRotor[0].position);
    if (idKey >= (int)activRotor[1].in.size()) idKey -= (int)activRotor[2].in.size();
    else if (idKey < 0) idKey += (int)activRotor[2].in.size();
    key = activRotor[1].out[idKey];

    idKey = GetIdOfKey(key, activRotor[2].in);

    //алгоритм третьего ротора
    idKey += (activRotor[2].position - activRotor[1].position);
    if (idKey >= (int)activRotor[2].in.size()) idKey -= (int)activRotor[2].in.size();
    else if (idKey < 0) idKey += (int)activRotor[2].in.size();
    key = activRotor[2].out[idKey];

    idKey = GetIdOfKey(key, activReflector.in);

    //алгоритм рефлектора
    idKey -= activRotor[2].position;
    if (idKey >= (int)activReflector.in.size()) idKey -= (int)activRotor[2].in.size();
    else if (idKey < 0) idKey += (int)activRotor[2].in.size();
    key = activReflector.out[idKey];

    idKey = GetIdOfKey(key, activReflector.in);

    //алгоритм третьего ротора - после рефлектора
    idKey += activRotor[2].position;
    if (idKey >= (int)activRotor[2].in.size()) idKey -= (int)activRotor[2].in.size();
    else if (idKey < 0) idKey += (int)activRotor[2].in.size();
    key = activReflector.in[idKey];
    idKey = GetIdOfKey(key, activRotor[2].out);
    key = activRotor[2].in[idKey]; // h

    //алгоритм второго ротора - после рефлектора
    idKey -= activRotor[2].position - activRotor[1].position;
    if (idKey >= (int)activRotor[1].in.size()) idKey -= (int)activRotor[1].in.size();
    else if (idKey < 0) idKey += (int)activRotor[2].in.size();
    key = activRotor[2].in[idKey];
    idKey = GetIdOfKey(key, activRotor[1].out);
    key = activRotor[1].in[idKey];

    //алгоритм первого ротора - после рефлектора
    idKey -= activRotor[1].position - activRotor[0].position;
    if (idKey >= (int)activRotor[0].in.size()) idKey -= (int)activRotor[0].in.size();
    else if (idKey < 0) idKey += (int)activRotor[2].in.size();
    key = activRotor[1].in[idKey];
    idKey = GetIdOfKey(key, activRotor[0].out);
    key = activRotor[0].in[idKey];

    //алгоритм - после роторов
    idKey -= activRotor[0].position;
    if (idKey >= (int)activRotor[0].in.size()) idKey -= (int)activRotor[0].in.size();
    else if (idKey < 0) idKey += (int)activRotor[2].in.size();
    key = activRotor[0].in[idKey];

    return key;
}

int Encryptor::GetIdOfKey(char s, vector<char> keyboard)
{
    for (int i = 0; i < (int)keyboard.size(); i++)
    {
        if (s == keyboard[i])
        {
            return i;
        }
    }
    return 0;
}

void Encryptor::AddRotor(Rotor rotor, bool isReflector)
{
    if (!isReflector) rotors.push_back(rotor);
    else reflectors.push_back(rotor);
}

Rotor Encryptor::GetRotor(int id, bool isReflector)
{
    if (!isReflector) return rotors[id];
    else return reflectors[id];
}

Rotor Encryptor::GetActivRotor(int id, bool isReflector)
{
    if (!isReflector) return activRotor[id];
    else return activReflector;
}

void Encryptor::SetRotor(Rotor rotor, bool isReflector, int id)
{
    if (!isReflector) rotors[id] = rotor;
    else reflectors[id] = rotor;
}

void Encryptor::SetRotors(Rotor* rotors)
{
    activRotor[0] = rotors[0];
    activRotor[1] = rotors[1];
    activRotor[2] = rotors[2];
    activRotor[3] = rotors[3];
}

void Encryptor::SetActivRotor(Rotor rotor, int id)
{
    activRotor[id] = rotor;
}

void Encryptor::SetReflector(Rotor reflector)
{
    activReflector = reflector;
}

void Encryptor::ChangeStyle(bool style4)
{

}