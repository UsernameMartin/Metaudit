/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#ifndef DATAEXTRACTOR_H
#define DATAEXTRACTOR_H

#include <QWidget>
#include <QLineEdit>
#include "dataeditors.h"

class DataExtractor : public QWidget {
    Q_OBJECT
public:
    explicit DataExtractor(QWidget *parent, DataEditors* d, QLineEdit* p);

public slots:
    void extractData();

private:
    DataEditors *editors;
    QLineEdit *pathEdit;

};

#endif // DATAEXTRACTOR_H
