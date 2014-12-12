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
