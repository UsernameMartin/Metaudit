/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/



#ifndef DATAEDITORS_H
#define DATAEDITORS_H

#include <QObject>
#include <QLineEdit>
#include <QComboBox>
#include <QImage>
#include <QLabel>
#include <QTextEdit>
#include <attachedpictureframe.h>
#include <mpegfile.h>

class DataEditors : public QObject {
    Q_OBJECT
public:
    explicit DataEditors(QObject *parent, QLineEdit* pTitle, QLineEdit* pTrack,
                         QLineEdit* pAlbum, QLineEdit* pArtist, QLineEdit* pYear,
                         QComboBox* pGenre, QLineEdit* pPicture, QLabel* pLabel,
                         QImage *pImage, QTextEdit *pComment);
    QLineEdit* title;
    QLineEdit* track;
    QLineEdit* album;
    QLineEdit* artist;
    QLineEdit* year;
    QComboBox* genre;
    QLineEdit* picture;
    QLabel* pictureLabel;
    QImage* image;
    TagLib::MPEG::File* mpegFile;
    QTextEdit* comment;
};

#endif // DATAEDITORS_H
