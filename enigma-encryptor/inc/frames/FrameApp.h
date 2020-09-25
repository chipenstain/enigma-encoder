#pragma once
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <wx/statline.h>
#include "../Encryptor.h"
#include "../includes.h"

class FrameApp : public wxFrame
{
public:
    Encryptor encryptor;

    wxTextCtrl* inputField;
    wxTextCtrl* outputField;
    
    wxStaticText* reflectorOut; wxButton* reflectorUpBtn; wxButton* reflectorDownBtn;
    wxStaticText* rotor4Out; wxButton* rotor4UpBtn; wxButton* rotor4DownBtn;
    wxStaticText* rotor3Out; wxButton* rotor3UpBtn; wxButton* rotor3DownBtn;
    wxStaticText* rotor2Out; wxButton* rotor2UpBtn; wxButton* rotor2DownBtn;
    wxStaticText* rotor1Out; wxButton* rotor1UpBtn; wxButton* rotor1DownBtn;

    FrameApp(const wxString& title, const wxPoint& pos, const wxSize& size);

    void OnEnter(wxCommandEvent& event);
    void OnBtnClick(wxCommandEvent& event);

private:
    string encryptStr;
};