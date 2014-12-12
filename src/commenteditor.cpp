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
