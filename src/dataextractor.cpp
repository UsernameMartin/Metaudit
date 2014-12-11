/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#include <QObject>
#include <QPushButton>
#include <taglib.h>
#include <fileref.h>
#include <mpegfile.h>
#include <id3v2tag.h>
#include <tpropertymap.h>
#include <attachedpictureframe.h>
#include <string>
#include <iostream>
#include <sstream>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPixmap>
#include <fstream>
#include "dataextractor.h"

using namespace std;

DataExtractor::DataExtractor(QWidget *parent, DataEditors* d, QLineEdit* p) :
    QWidget(parent) {

    editors = d;
    pathEdit = p;

}

void DataExtractor::extractData() {

    QString qPath = pathEdit->text();
    string stdPath = qPath.toStdString();
    if(stdPath.find('"') != std::string::npos) {
        int i1 = stdPath.find('"', 0);
        int i2 = stdPath.find('"', 1);
        stdPath = stdPath.substr(i1+1, i2-1);
    }
    const char* charPath = stdPath.c_str();
    ifstream fileCheck(charPath);
    if(!fileCheck.good()) {

        QWidget *w = new QWidget();
        QLabel *l = new QLabel("Invalid name of file!\n"
                               "If you are trying to open a file with a localized name, check your path in the editor,\n"
                               "because there can be errors when converting the text!");
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
    int intTrack = file.tag()->track();
    string stdTrack;
    ostringstream convert;
    convert << intTrack;
    stdTrack = convert.str();
    string stdYear;
    ostringstream convertYear;
    convertYear << file.tag()->year();
    stdYear = convertYear.str();

    QString artist = QString::fromLocal8Bit(file.tag()->artist().toCString());
    if(editors->artist->isEnabled())
        editors->artist->setText(artist);
    QString album = QString::fromLocal8Bit(file.tag()->album().toCString());
    if(editors->album->isEnabled())
        editors->album->setText(album);
    QString track = QString::fromStdString(stdTrack);
    if(editors->track->isEnabled())
        editors->track->setText(track);
    QString title = QString::fromLocal8Bit(file.tag()->title().toCString());
    if(editors->title->isEnabled())
        editors->title->setText(title);
    QString year = QString::fromStdString(stdYear);
    if(editors->year->isEnabled())
        editors->year->setText(year);
    int i = editors->genre->findText(QString::fromLocal8Bit(file.tag()->genre().toCString()));
    editors->genre->setCurrentIndex(i);

    TagLib::MPEG::File *mpegFile = new TagLib::MPEG::File(name);
    TagLib::ID3v2::Tag *tag = mpegFile->ID3v2Tag();
    QImage image;
    TagLib::ID3v2::FrameList l = tag->frameList("APIC");
    if(l.isEmpty()) {
        editors->picture->clear();
        editors->pictureLabel->setPixmap(QPixmap::fromImage(QImage(":images/nofile.png")));
        editors->pictureLabel->update();
        return;
    }

    TagLib::ID3v2::AttachedPictureFrame *f =
            static_cast<TagLib::ID3v2::AttachedPictureFrame *>(l.front());
    image.loadFromData((const uchar *) f->picture().data(), f->picture().size());
    image = image.scaled(100, 100);
    editors->image = &image;
    editors->pictureLabel->setPixmap(QPixmap::fromImage(image));
    editors->pictureLabel->update();
    editors->mpegFile = mpegFile;
    editors->picture->setText("<Attached picture>");

}
