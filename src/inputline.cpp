/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#include "inputline.h"

InputLine::InputLine(QWidget *parent, QCheckBox *ch) :
    QLineEdit(parent) {

    check = ch;
    QObject::connect(check, SIGNAL(stateChanged(int)), this, SLOT(disableLine(int)));

}

void InputLine::disableLine(int checked) {

    if(checked != 0) {
        setDisabled(false);
    } else {
        setDisabled(true);
    }

}
