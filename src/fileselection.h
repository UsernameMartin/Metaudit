/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#ifndef FILESELECTION_H
#define FILESELECTION_H

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLineEdit>

class FileSelection : public QWidget {
    Q_OBJECT

public:
    FileSelection(QWidget *parent = 0, QPushButton *but = NULL, QLineEdit *l = NULL);
    ~FileSelection();
    QString getFile();

private slots:
    void showFileDialog();

private:
    QString file;
    QLineEdit *outputLine;

};

#endif // FILESELECTION_H
