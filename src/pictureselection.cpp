#include <QPicture>
#include <QImage>
#include <QPixmap>
#include <QCheckBox>
#include "pictureselection.h"
#include "taglib.h"

PictureSelection::PictureSelection(QWidget *parent, InputLine *l, QLabel *la, QGridLayout *lay, QCheckBox* ch) :
    QPushButton("Browse...", parent) {

    line = l;
    label = la;
    layout = lay;
    check = ch;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(selectPicture()));
    QObject::connect(check, SIGNAL(clicked()), this, SLOT(disable()));

}

void PictureSelection::selectPicture() {

    QFileDialog dialog(this);
    dialog.setNameFilter("Image files (*.png)");
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.show();
    if(dialog.exec()) {
        QStringList nameList = dialog.selectedFiles();
        QString name = nameList.join("");
        line->setText(name);
        name = name.toLocal8Bit();
        QImage *image = new QImage(name);
        if(image->isNull()) {
            QPixmap map(QPixmap::fromImage(QImage(":/images/nosuchfile.png")));
            label->setPixmap(map);
            label->update();
            layout->update();
            return;
        }
        QPixmap map = QPixmap::fromImage(*image);
        map = map.scaled(100, 100);
        label->setPixmap(map);
        label->update();
        layout->update();
    }

}

void PictureSelection::disable() {
    if(check->isChecked()) {
        label->setDisabled(false);
    } else {
        label->setDisabled(true);
    }
}
