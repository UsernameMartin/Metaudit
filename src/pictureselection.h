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
    explicit PictureSelection(QWidget *parent, InputLine* l, QLabel *la, QGridLayout* lay);

public slots:
    void selectPicture();

private:
    InputLine *line;
    QLabel *label;
    QGridLayout *layout;
};

#endif // PICTURESELECTION_H
