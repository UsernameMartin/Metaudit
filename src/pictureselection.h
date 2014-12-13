/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/


#ifndef PICTURESELECTION_H
#define PICTURESELECTION_H

#include <QWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QGridLayout>
#include "inputline.h"

class PictureSelection : public QPushButton {

    Q_OBJECT
public:
    explicit PictureSelection(QWidget *parent, InputLine* l, QLabel *la, QGridLayout* lay, QCheckBox *ch);

public slots:
    void selectPicture();
    void disable();

private:
    InputLine *line;
    QLabel *label;
    QGridLayout *layout;
    QCheckBox *check;
};

#endif // PICTURESELECTION_H
