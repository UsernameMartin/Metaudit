/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/


#include "commenteditor.h"

CommentEditor::CommentEditor(QWidget *parent, QCheckBox *pCheck): QTextEdit(parent) {
    check = pCheck;
    QObject::connect(check, SIGNAL(toggled(bool)), this, SLOT(disable(bool)));
}

CommentEditor::~CommentEditor() {

}

void CommentEditor::disable(bool checked) {
    if(checked)
        setDisabled(false);
    else
        setDisabled(true);

}
