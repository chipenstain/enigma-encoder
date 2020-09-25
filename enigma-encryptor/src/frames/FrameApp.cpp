#include "../../inc/frames/FrameApp.h"

FrameApp::FrameApp(const wxString& title, const wxPoint& pos, const wxSize & size) : wxFrame((wxFrame*)NULL, -1, title, pos, size)
{
    //TODO: fix sizers

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    
    wxBoxSizer* rotorsDisplay = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(rotorsDisplay, wxALL | wxEXPAND);

    wxBoxSizer* rotorsUp = new wxBoxSizer(wxHORIZONTAL);
    reflectorUpBtn = new wxButton(this, wxID_ANY, wxString("prev"), wxPoint(90,10), wxSize(70,20));
    reflectorUpBtn->SetName("reflectorUpBtn");
    reflectorUpBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotor4UpBtn = new wxButton(this, wxID_ANY, wxString("prev"), wxPoint(180, 10), wxSize(70, 20));
    rotor4UpBtn->SetName("rotor4UpBtn");
    rotor4UpBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotor3UpBtn = new wxButton(this, wxID_ANY, wxString("prev"), wxPoint(270, 10), wxSize(70, 20));
    rotor3UpBtn->SetName("rotor3UpBtn");
    rotor3UpBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotor2UpBtn = new wxButton(this, wxID_ANY, wxString("prev"), wxPoint(360, 10), wxSize(70, 20));
    rotor2UpBtn->SetName("rotor2UpBtn");
    rotor2UpBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotor1UpBtn = new wxButton(this, wxID_ANY, wxString("prev"), wxPoint(450, 10), wxSize(70, 20));
    rotor1UpBtn->SetName("rotor1UpBtn");
    rotor1UpBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotorsDisplay->Add(rotorsUp, wxALL);
    
    wxBoxSizer* rotors = new wxBoxSizer(wxHORIZONTAL);
    reflectorOut = new wxStaticText(this, wxID_ANY, "A", wxPoint(85,40), wxSize(80,100), wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_HORIZONTAL);
    reflectorOut->SetBackgroundColour(wxColor(80, 191, 222));
    reflectorOut->SetFont(wxFont(64, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    rotor4Out = new wxStaticText(this, wxID_ANY, "A", wxPoint(175,40), wxSize(80, 100), wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_HORIZONTAL);
    rotor4Out->SetBackgroundColour(wxColor(80, 191, 222));
    rotor4Out->SetFont(wxFont(64, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    rotor3Out = new wxStaticText(this, wxID_ANY, "A", wxPoint(265,40), wxSize(80, 100), wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_HORIZONTAL);
    rotor3Out->SetBackgroundColour(wxColor(80, 191, 222));
    rotor3Out->SetFont(wxFont(64, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    rotor2Out = new wxStaticText(this, wxID_ANY, "A", wxPoint(355,40), wxSize(80, 100), wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_HORIZONTAL);
    rotor2Out->SetBackgroundColour(wxColor(80, 191, 222));
    rotor2Out->SetFont(wxFont(64, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    rotor1Out = new wxStaticText(this, wxID_ANY, "A", wxPoint(445,40), wxSize(80, 100), wxALIGN_CENTRE_HORIZONTAL | wxALIGN_CENTRE_HORIZONTAL);
    rotor1Out->SetBackgroundColour(wxColor(80, 191, 222));
    rotor1Out->SetFont(wxFont(64, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    rotorsDisplay->Add(rotors, wxALL | wxEXPAND);

    wxBoxSizer* rotorsDown = new wxBoxSizer(wxHORIZONTAL);
    reflectorDownBtn = new wxButton(this, wxID_ANY, wxString("next"), wxPoint(90,150), wxSize(70, 20));
    reflectorDownBtn->SetName("reflectorDownBtn");
    reflectorDownBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotor4DownBtn = new wxButton(this, wxID_ANY, wxString("next"), wxPoint(180,150), wxSize(70, 20));
    rotor4DownBtn->SetName("rotor4DownBtn");
    rotor4DownBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotor3DownBtn = new wxButton(this, wxID_ANY, wxString("next"), wxPoint(270,150), wxSize(70, 20));
    rotor3DownBtn->SetName("rotor3DownBtn");
    rotor3DownBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotor2DownBtn = new wxButton(this, wxID_ANY, wxString("next"), wxPoint(360,150), wxSize(70, 20));
    rotor2DownBtn->SetName("rotor2DownBtn");
    rotor2DownBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotor1DownBtn = new wxButton(this, wxID_ANY, wxString("next"), wxPoint(450,150), wxSize(70, 20));
    rotor1DownBtn->SetName("rotor1DownBtn");
    rotor1DownBtn->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FrameApp::OnBtnClick, this);
    rotorsDisplay->Add(rotorsDown, wxALL | wxEXPAND);
    
    wxBoxSizer* fieldsSizer = new wxBoxSizer(wxHORIZONTAL);
    inputField = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(0, 278), wxSize(312, 200), wxTE_MULTILINE | wxTE_LEFT | wxBORDER_RAISED);
    inputField->Bind(wxEVT_TEXT, &FrameApp::OnEnter, this);
    outputField = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(314, 278), wxSize(312, 200), wxTE_MULTILINE | wxTE_READONLY | wxTE_LEFT | wxBORDER_RAISED);
    mainSizer->Add(fieldsSizer, wxALL | wxEXPAND);

    SetSizer(mainSizer);
}

void FrameApp::OnEnter(wxCommandEvent& event)
{
    Rotor tmpRotor;
    wxString str = inputField->GetValue();
    string strStd = (string)str;

    if (strStd.length() > encryptStr.length())
    {
        if (strStd[strStd.length() - 1] == ' ') encryptStr += ' ';
        else encryptStr += encryptor.Encrypt(strStd[strStd.length() - 1]);
    }
    else if (strStd.length() < encryptStr.length())
    {
        tmpRotor = encryptor.GetActivRotor(0);
        if (tmpRotor.position > 0) tmpRotor.position--;
        else tmpRotor.position = (int)tmpRotor.in.size() - 1;
        encryptor.SetActivRotor(tmpRotor, 0);
        encryptStr.pop_back();
    }

    tmpRotor = encryptor.GetActivRotor(0);
    rotor1Out->SetLabel(tmpRotor.in[tmpRotor.position]);
    rotor1Out->Refresh();

    tmpRotor = encryptor.GetActivRotor(1);
    rotor2Out->SetLabel(tmpRotor.in[tmpRotor.position]);
    rotor2Out->Refresh();

    tmpRotor = encryptor.GetActivRotor(2);
    rotor3Out->SetLabel(tmpRotor.in[tmpRotor.position]);
    rotor3Out->Refresh();

    tmpRotor = encryptor.GetActivRotor(3);
    rotor4Out->SetLabel(tmpRotor.in[tmpRotor.position]);
    rotor4Out->Refresh();

    tmpRotor = encryptor.GetActivRotor(0, true);
    reflectorOut->SetLabel(tmpRotor.in[tmpRotor.position]);
    reflectorOut->Refresh();
    
    outputField->SetValue(encryptStr);
}

void FrameApp::OnBtnClick(wxCommandEvent& event)
{
    string nameBtn = string(((wxButton*)event.GetEventObject())->GetName());
    Rotor tmpRotor;

    if (nameBtn == "rotor1UpBtn")
    {
        tmpRotor = encryptor.GetActivRotor(0);
        if (tmpRotor.position < (int)tmpRotor.in.size() - 1) tmpRotor.position++;
        else tmpRotor.position = 0;
        rotor1Out->SetLabel(tmpRotor.in[tmpRotor.position]);
        rotor1Out->Refresh();
        encryptor.SetActivRotor(tmpRotor, 0);
    }
    else if (nameBtn == "rotor2UpBtn")
    {
        tmpRotor = encryptor.GetActivRotor(1);
        if (tmpRotor.position < (int)tmpRotor.in.size() - 1) tmpRotor.position++;
        else tmpRotor.position = 0;
        rotor2Out->SetLabel(tmpRotor.in[tmpRotor.position]);
        rotor2Out->Refresh();
        encryptor.SetActivRotor(tmpRotor, 1);
    }
    else if (nameBtn == "rotor3UpBtn")
    {
        tmpRotor = encryptor.GetActivRotor(2);
        if (tmpRotor.position < (int)tmpRotor.in.size() - 1) tmpRotor.position++;
        else tmpRotor.position = 0;
        rotor3Out->SetLabel(tmpRotor.in[tmpRotor.position]);
        rotor3Out->Refresh();
        encryptor.SetActivRotor(tmpRotor, 2);
    }
    else if (nameBtn == "rotor4UpBtn")
    {
        tmpRotor = encryptor.GetActivRotor(3);
        if (tmpRotor.position < (int)tmpRotor.in.size() - 1) tmpRotor.position++;
        else tmpRotor.position = 0;
        rotor4Out->SetLabel(tmpRotor.in[tmpRotor.position]);
        rotor4Out->Refresh();
        encryptor.SetActivRotor(tmpRotor, 3);
    }
    else if (nameBtn == "reflectorUpBtn")
    {
        tmpRotor = encryptor.GetActivRotor(0, true);
        if (tmpRotor.position < (int)tmpRotor.in.size() - 1) tmpRotor.position++;
        else tmpRotor.position = 0;
        reflectorOut->SetLabel(tmpRotor.in[tmpRotor.position]);
        reflectorOut->Refresh();
        encryptor.SetReflector(tmpRotor);
    }
    else if (nameBtn == "rotor1DownBtn")
    {
        tmpRotor = encryptor.GetActivRotor(0);
        if (tmpRotor.position > 0) tmpRotor.position--;
        else tmpRotor.position = (int)tmpRotor.in.size() - 1;
        rotor1Out->SetLabel(tmpRotor.in[tmpRotor.position]);
        rotor1Out->Refresh();
        encryptor.SetActivRotor(tmpRotor, 0);
    }
    else if (nameBtn == "rotor2DownBtn")
    {
        tmpRotor = encryptor.GetActivRotor(1);
        if (tmpRotor.position > 0) tmpRotor.position--;
        else tmpRotor.position = (int)tmpRotor.in.size() - 1;
        rotor2Out->SetLabel(tmpRotor.in[tmpRotor.position]);
        rotor2Out->Refresh();
        encryptor.SetActivRotor(tmpRotor, 1);
    }
    else if (nameBtn == "rotor3DownBtn")
    {
        tmpRotor = encryptor.GetActivRotor(2);
        if (tmpRotor.position > 0) tmpRotor.position--;
        else tmpRotor.position = (int)tmpRotor.in.size() - 1;
        rotor3Out->SetLabel(tmpRotor.in[tmpRotor.position]);
        rotor3Out->Refresh();
        encryptor.SetActivRotor(tmpRotor, 2);
    }
    else if (nameBtn == "rotor4DownBtn")
    {
        tmpRotor = encryptor.GetActivRotor(3);
        if (tmpRotor.position > 0) tmpRotor.position--;
        else tmpRotor.position = (int)tmpRotor.in.size() - 1;
        rotor4Out->SetLabel(tmpRotor.in[tmpRotor.position]);
        rotor4Out->Refresh();
        encryptor.SetActivRotor(tmpRotor, 3);
    }
    else if (nameBtn == "reflectorDownBtn")
    {
        tmpRotor = encryptor.GetActivRotor(0, true);
        if (tmpRotor.position > 0) tmpRotor.position--;
        else tmpRotor.position = (int)tmpRotor.in.size() - 1;
        reflectorOut->SetLabel(tmpRotor.in[tmpRotor.position]);
        reflectorOut->Refresh();
        encryptor.SetReflector(tmpRotor);
    }
}