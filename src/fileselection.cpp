/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#include <QPushButton>
#include <QFileDialog>
#include <QStringList>
#include <QLineEdit>
#include <string>
#include <sstream>
#include "fileselection.h"

using namespace std;

FileSelection::FileSelection(QWidget *parent, QPushButton* but, QLineEdit *l)
    : QWidget(parent) {
   outputLine = l;
   connect(but, SIGNAL(clicked()), this, SLOT(showFileDialog()));
}

FileSelection::~FileSelection() {

}


QString FileSelection::getFile() {
    return file;
}

void FileSelection::showFileDialog() {

    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(tr("Audio files (*.mp3)"));
    dialog.setViewMode(QFileDialog::Detail);
    dialog.show();
    if(dialog.exec()) {
        QStringList l = dialog.selectedFiles();
        char charComma = '"';
        ostringstream convert;
        convert << charComma;
        string comma = convert.str();
        string stdSeparator = comma + " " + comma;
        QString separator = QString::fromStdString(stdSeparator);
        QString s = l.join(separator);
        string stdFile = comma + s.toStdString() + comma;
        file = QString::fromStdString(stdFile);
        outputLine->clear();
        if(l.size() > 1)
            outputLine->insert(file);
        else
            outputLine->insert(l.join(""));
    }

}
