#ifndef UNITTEST_H_
#define UNITTEST_H_

#include "Element.h"


class UnitTest
{
public:
    UnitTest();
    ~UnitTest();
    UnitTest(const UnitTest& other);
    
    void initVars();
    void test1();
    void test2();
    void void3();
private:
    Element* _mainWindow;
    Element* _fileDialog;
    Element* _fileDialogSaveButton;
    Element* _fileDialogCancelButton;
    Element* _findReplaceDialog;
    Element* _findReplaceDialogFindButton;
    Element* _findReplaceDialogReplaceButton;
    Element* _fontDialog;
    Element* _fontDialogOkButton;
    Element* _fontDialogColorButton;
    Element* _fontDialogSizeButton;
    Element* _aboutDialog;
    Element* _aboutScrollButton
    Element* _aboutOkButton;
    
};

#endif
