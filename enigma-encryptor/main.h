 #pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "inc/includes.h"
#include "inc/Encryptor.h"
#include "inc/frames/FrameApp.h"

const string settingsPath = "settings.dat";
const string rotorsPath = "rotors.dat";
//const string reflectorsPath = "reflectors.dat";
const string reflectorsPath = "C:/projects/enigma-encryptor/Debug/reflectors.dat";

class App : public wxApp
{
public:
    bool OnInit();

    void LoadSettings();
    void SaveSettings();

private:
    Encryptor encryptor;
};

