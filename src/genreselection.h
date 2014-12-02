/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#ifndef GENRESELECTION_H
#define GENRESELECTION_H

#include <QWidget>
#include <QComboBox>

class GenreSelection : public QComboBox
{
    Q_OBJECT
public:
    explicit GenreSelection(QWidget *parent = 0);

};

#endif // GENRESELECTION_H
