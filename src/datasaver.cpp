/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#include <taglib.h>
#include <fileref.h>
#include <string>
#include <algorithm>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDir>
#include <fstream>
#include "datasaver.h"

using namespace std;

DataSaver::DataSaver(QWidget *parent, DataEditors* e, QLineEdit* p) :
    QWidget(parent) {

    editors = e;
    path = p;

}

void DataSaver::saveData() {

    QString qPath = path->text().toLocal8Bit();
    string stdPath = qPath.toStdString();
    if(stdPath.find('"') != string::npos) {

        int i = 0;
        unsigned int i1 = 0, i2 = 1;
        while(i > -1) {

            if(i1 > stdPath.length() || i2 > stdPath.length())
                break;
            i1 = stdPath.find('"', i1);
            i++;
            i2 = stdPath.find('"', i2);
            i++;
            if(i1 == string::npos || i2 == string::npos)
                break;
            string stdPath1 = stdPath.substr(i1+1, i2-(i1+1));
            cout << stdPath1 << "\n";
            const char* charPath = stdPath1.c_str();
            ifstream fileCheck(charPath);
            if(!fileCheck.good()) {

                QWidget *w = new QWidget();
                QLabel *l = new QLabel("Invalid file!", w);
                QPushButton *b = new QPushButton("OK", w);
                QVBoxLayout *lay = new QVBoxLayout();
                lay->addWidget(l);
                lay->addWidget(b);
                w->setLayout(lay);
                w->setFixedHeight(100);
                w->setFixedWidth(150);
                QWidget::connect(b, SIGNAL(clicked()), w, SLOT(close()));
                w->show();
                return;
            }
            TagLib::FileName name = charPath;
            TagLib::FileRef file(name);
            if(editors->artist->isEnabled())
                file.tag()->setArtist(editors->artist->text().toStdString());
            if(editors->album->isEnabled())
                file.tag()->setAlbum(editors->album->text().toStdString());
            if(editors->track->isEnabled())
                file.tag()->setTrack(editors->track->text().toInt());
            if(editors->title->isEnabled())
                file.tag()->setTitle(editors->title->text().toStdString());
            if(editors->year->isEnabled())
                file.tag()->setYear(editors->year->text().toInt());
            file.tag()->setGenre(editors->genre->currentText().toStdString());
            file.save();
            cout << "saved.\n";
            i1=i2+1;
            i2+=3;

        }

    } else {
        const char* charPath = stdPath.c_str();
        ifstream fileCheck(charPath);
        if(!fileCheck.good()) {

            QWidget *w = new QWidget();
            QLabel *l = new QLabel("Invalid file!", w);
            QPushButton *b = new QPushButton("OK", w);
            QVBoxLayout *lay = new QVBoxLayout();
            lay->addWidget(l);
            lay->addWidget(b);
            w->setLayout(lay);
            QWidget::connect(b, SIGNAL(clicked()), w, SLOT(close()));
            w->show();
            return;
        }
        TagLib::FileName name = charPath;
        TagLib::FileRef file(name);
        if(editors->artist->isEnabled())
            file.tag()->setArtist(editors->artist->text().toStdString());
        if(editors->album->isEnabled())
            file.tag()->setAlbum(editors->album->text().toStdString());
        if(editors->track->isEnabled())
            file.tag()->setTrack(editors->track->text().toInt());
        if(editors->title->isEnabled())
            file.tag()->setTitle(editors->title->text().toStdString());
        if(editors->year->isEnabled())
            file.tag()->setYear(editors->year->text().toInt());
        file.tag()->setGenre(editors->genre->currentText().toStdString());
        file.save();
    }

    QWidget* w = new QWidget();
    QLabel *l = new QLabel("Saved.", w);
    QPushButton* b = new QPushButton("OK", w);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(l);
    layout->addWidget(b);
    w->setLayout(layout);
    w->setFixedHeight(100);
    w->setFixedWidth(150);
    w->show();
    QWidget::connect(b, SIGNAL(clicked()), w, SLOT(close()));

}
