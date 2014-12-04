#include <QPicture>
#include <QImage>
#include <QPixmap>
#include "pictureselection.h"
#include "taglib.h"

PictureSelection::PictureSelection(QWidget *parent, InputLine *l, QLabel *la, QGridLayout *lay) :
    QPushButton("Browse...", parent) {

    line = l;
    label = la;
    layout = lay;
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(selectPicture()));

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
        QPixmap map = QPixmap::fromImage(*image);
        label->setPixmap(map);
        label->update();
        label->updateGeometry();
        label->update();
        label->show();
        layout->update();
    }


}
