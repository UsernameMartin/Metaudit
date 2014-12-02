/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#ifndef INPUTLINE_H
#define INPUTLINE_H

#include <QLineEdit>
#include <QCheckBox>

class InputLine : public QLineEdit {
    Q_OBJECT
public:
    explicit InputLine(QWidget *parent, QCheckBox* ch);

public slots:
    void disableLine(int checked);

private:
    QCheckBox *check;

};

#endif // INPUTLINE_H
