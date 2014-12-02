/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#ifndef DATASAVER_H
#define DATASAVER_H

#include <QWidget>
#include "dataeditors.h"

class DataSaver : public QWidget {
    Q_OBJECT
public:
    explicit DataSaver(QWidget *parent, DataEditors* e, QLineEdit* p);

public slots:
    void saveData();

private:
    DataEditors *editors;
    QLineEdit *path;

};

#endif // DATASAVER_H
