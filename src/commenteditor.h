/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/


#ifndef COMMENTEDITOR_H
#define COMMENTEDITOR_H

#include <QTextEdit>
#include "inputline.h"

class CommentEditor: public QTextEdit {

    Q_OBJECT

public:
    explicit CommentEditor(QWidget* parent, QCheckBox* pCheck);
    ~CommentEditor();

private:
    QCheckBox* check;

public slots:
    void disable(bool checked);
};


#endif // COMMENTEDITOR
