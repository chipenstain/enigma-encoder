#include "main.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    encryptor = Encryptor();
    LoadSettings();
    Rotor r[4] = { encryptor.GetRotor(0), encryptor.GetRotor(1), encryptor.GetRotor(2),  encryptor.GetRotor(3)};
    encryptor.SetRotors(r);
    encryptor.SetReflector(encryptor.GetRotor(0, true));
        
    FrameApp* frame = new FrameApp(wxT("ENIGMA encryptoryptor"), wxDefaultPosition, wxSize(640, 480));
    frame->SetSizeHints(wxSize(640, 480), wxSize(640, 480));
    frame->Show(true);

    frame->encryptor = encryptor;

    return true;
}

void App::LoadSettings()
{
    ifstream rotors_settings(rotorsPath);
    if (!rotors_settings)
    {
        ofstream rotors_settings_new(rotorsPath);
        rotors_settings_new.write("", 50);
        rotors_settings_new.close();
    }
    else
    {
        int i = 0;
        bool createRotor = true;
        do
        {
            if (createRotor)
            {
                encryptor.AddRotor(Rotor());
                createRotor = false;
            }

            string in;
            getline(rotors_settings, in);
            if (in == "")
            {
                i++;
                createRotor = true;
                continue;
            }

            string parametr = in.substr(0, in.find('='));
            string value = in.substr(in.find('=') + 1);

            Rotor r = encryptor.GetRotor(i);

            if (parametr == "rotor") r.name = value;
            else if (parametr == "language") r.language = value;
            else
            {
                r.in.push_back(parametr.c_str()[0]);
                r.out.push_back(value.c_str()[0]);
            }

            encryptor.SetRotor(r, false, i);

        } while (!rotors_settings.eof());

        rotors_settings.close();
    }

    ifstream reflector_settings(reflectorsPath);
    if (!reflector_settings.is_open())
    {
        ofstream reflector_settings_new(reflectorsPath);
        reflector_settings_new.write("", 50);
        reflector_settings_new.close();
    }
    else
    {
        int i = 0;
        bool createReflector = true;
        do
        {
            if (createReflector)
            {
                encryptor.AddRotor(Rotor(), true);
                createReflector = false;
            }

            string in;
            getline(reflector_settings, in);
            if (in == "")
            {
                i++;
                createReflector = true;
                continue;
            }

            string parametr = in.substr(0, in.find('='));
            string value = in.substr(in.find('=') + 1);

            Rotor r = encryptor.GetRotor(i, true);

            if (parametr == "reflector") r.name = value;
            else if (parametr == "language") r.language = value;

            else
            {
                r.in.push_back(parametr.c_str()[0]);
                r.out.push_back(value.c_str()[0]);
            }

            encryptor.SetRotor(r, true, i);

        } while (!reflector_settings.eof());

        reflector_settings.close();
    }

    ifstream settings(settingsPath);
    if (!settings)
    {
        ofstream settings_new(reflectorsPath);
        settings_new.write("", 50);
        settings_new.close();
    }
}

void App::SaveSettings()
{

}