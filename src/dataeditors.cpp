/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#include <QLineEdit>
#include "dataeditors.h"

DataEditors::DataEditors(QObject *parent, QLineEdit *pTitle,
                         QLineEdit *pTrack,
                         QLineEdit *pAlbum,
                         QLineEdit *pArtist,
                         QLineEdit *pYear,
                         QComboBox *pGenre,
                         QLineEdit *pPicture,
                         QLabel *pLabel,
                         QImage *pImage) : QObject(parent) {

        title = pTitle;
        track = pTrack;
        album = pAlbum;
        artist = pArtist;
        year = pYear;
        genre = pGenre;
        picture = pPicture;
        pictureLabel = pLabel;
        image = pImage;

}
