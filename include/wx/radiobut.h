///////////////////////////////////////////////////////////////////////////////
// Name:        wx/radiobut.h
// Purpose:     wxRadioButton declaration
// Author:      Vadim Zeitlin
// Modified by:
// Created:     07.09.00
// Copyright:   (c) Vadim Zeitlin
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_RADIOBUT_H_BASE_
#define _WX_RADIOBUT_H_BASE_

#include "wx/defs.h"

#if wxUSE_RADIOBTN

/*
   There is no wxRadioButtonBase class as wxRadioButton interface is the same
   as wxCheckBox(Base), but under some platforms wxRadioButton really
   derives from wxCheckBox and on the others it doesn't.

   The pseudo-declaration of wxRadioButtonBase would look like this:

   class wxRadioButtonBase : public ...
   {
   public:
        virtual void SetValue(bool value);
        virtual bool GetValue() const;
   };
 */

#include "wx/control.h"

class WXDLLIMPEXP_FWD_CORE wxRadioButton;

wxRadioButton* wxGetNextButtonInGroup(wxRadioButton *btn);
wxRadioButton* wxGetPreviousButtonInGroup(wxRadioButton *btn);
wxRadioButton* wxGetFirstButtonInGroup(wxRadioButton *btn);
wxRadioButton* wxGetLastButtonInGroup(wxRadioButton *btn);

template <class W>
class WXDLLIMPEXP_CORE wxRadioButtonBase : public W
{
public:
    typedef W BaseWindowClass;

    wxRadioButtonBase() { }

    wxRadioButton* GetFirstInGroup() const
    {
        return wxGetFirstButtonInGroup( static_cast<wxRadioButton*>(this));
    }

    wxRadioButton* GetLastInGroup() const
    {
        return wxGetLastButtonInGroup( static_cast<wxRadioButton*>(this));
    }

    wxRadioButton* GetPreviousInGroup() const
    {
        return wxGetPreviousButtonInGroup( static_cast<wxRadioButton*>(this));
    }

    wxRadioButton* GetNextInGroup() const
    {
        return wxGetNextButtonInGroup( static_cast<wxRadioButton*>(this));
    }

private:
    wxDECLARE_NO_COPY_TEMPLATE_CLASS(wxRadioButtonBase, W);
};

extern WXDLLIMPEXP_DATA_CORE(const char) wxRadioButtonNameStr[];

#if defined(__WXUNIVERSAL__)
    #include "wx/univ/radiobut.h"
#elif defined(__WXMSW__)
    #include "wx/msw/radiobut.h"
#elif defined(__WXMOTIF__)
    #include "wx/motif/radiobut.h"
#elif defined(__WXGTK20__)
    #include "wx/gtk/radiobut.h"
#elif defined(__WXGTK__)
    #include "wx/gtk1/radiobut.h"
#elif defined(__WXMAC__)
    #include "wx/osx/radiobut.h"
#elif defined(__WXQT__)
    #include "wx/qt/radiobut.h"
#endif

#endif // wxUSE_RADIOBTN

#endif
    // _WX_RADIOBUT_H_BASE_
