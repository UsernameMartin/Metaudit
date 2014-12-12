/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QCheckBox>
#include <Qt>
#include <QPlastiqueStyle>
#include <QFile>
#include <QTextStream>
#include <QGtkStyle>
#include <QIcon>
#include <QImage>
#include <QTextCodec>
#include <qglobal.h>
#include <iostream>
#include <string>
#include "dataextractor.h"
#include "fileselection.h"
#include "dataeditors.h"
#include "datasaver.h"
#include "genreselection.h"
#include "inputline.h"
#include "pictureselection.h"
#include "commenteditor.h"

void setDarkTheme(QApplication &a);

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    QTextCodec *codec;
#ifdef WIN32
    codec = QTextCodec::codecForName("Windows-1250");
#else
    codec = QTextCodec::codecForName("UTF-8");
#endif
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QIcon icon(":images/icon.ico");
    a.setWindowIcon(icon);
    setDarkTheme(a);
    QWidget *window = new QWidget();
    QGridLayout *layout = new QGridLayout(window);

    QCheckBox *pictureCheck = new QCheckBox("Picture file:", window);
    pictureCheck->setChecked(true);
    InputLine *picture = new InputLine(window, pictureCheck);
    QLabel *pictureLabel = new QLabel();
    PictureSelection* pictureSelection = new PictureSelection(window, picture, pictureLabel, layout, pictureCheck);
    QPushButton *selectFile = new QPushButton("Browse...", window);
    QLineEdit *path = new QLineEdit(window);
    QLabel *pathLabel = new QLabel("File(s):", window);
    FileSelection selection(window, selectFile, path);
    QPushButton *showData = new QPushButton("Extract data", window);
    QCheckBox *authorCheck = new QCheckBox("Artist:", window);
    authorCheck->setChecked(true);
    InputLine *author = new InputLine(window, authorCheck);
    QCheckBox *albumCheck = new QCheckBox("Album:", window);
    albumCheck->setChecked(true);
    InputLine *album = new InputLine(window, albumCheck);
    QCheckBox *trackCheck = new QCheckBox("Track (number):", window);
    trackCheck->setChecked(true);
    InputLine *track = new InputLine(window, trackCheck);
    QCheckBox *titleCheck = new QCheckBox("Title:", window);
    titleCheck->setChecked(true);
    InputLine *title = new InputLine(window, titleCheck);
    QCheckBox *yearCheck = new QCheckBox("Year:", window);
    yearCheck->setChecked(true);
    InputLine *year = new InputLine(window, yearCheck);
    QCheckBox *genreCheck = new QCheckBox("Genre:", window);
    genreCheck->setChecked(true);
    GenreSelection *genre = new GenreSelection(window, genreCheck);
    QCheckBox* commentCheck = new QCheckBox("Comment:", window);
    commentCheck->setChecked(true);
    CommentEditor *comment = new CommentEditor(window, commentCheck);
    comment->setFixedHeight(50);
    QPushButton *save = new QPushButton("Save data", window);

    QImage *image = new QImage();
    track->setValidator(new QIntValidator(1, 100000000, window));
    year->setValidator(new QIntValidator(0, 2060, window));
    DataEditors *editors = new DataEditors(window, title, track, album, author, year, genre, picture, pictureLabel, image, comment);
    DataExtractor *extractor = new DataExtractor(window, editors, path);
    DataSaver *saver = new DataSaver(window, editors, path);
    QObject::connect(showData, SIGNAL(clicked()), extractor, SLOT(extractData()));
    QObject::connect(save, SIGNAL(clicked()), saver, SLOT(saveData()));
    pictureLabel->setPixmap(QPixmap::fromImage(QImage(":images/nofile.png")));

    int i = 0;
    layout->addWidget(pathLabel, i, 0, 1, 1, 0);
    layout->addWidget(path, i, 1, 1, 1, 0);
    layout->addWidget(selectFile, i, 2, 1, 1, 0);
    i++;
    layout->addWidget(showData, i, 0, 1, 1, 0);
    i++;
    layout->addWidget(pictureCheck, i, 0, 1, 1, 0);
    layout->addWidget(picture, i, 1, 1, 1, 0);
    layout->addWidget(pictureSelection, i, 2, 1, 1, 0);
    i++;
    layout->addWidget(pictureLabel, i, 1, 1, 1, 0);
    i++;
    layout->addWidget(authorCheck, i, 0, 1, 1, 0);
    layout->addWidget(author, i, 1, 1, 1, 0);
    i++;
    layout->addWidget(genreCheck, i, 0, 1, 1, 0);
    layout->addWidget(genre, i, 1, 1, 1, 0);
    i++;
    layout->addWidget(albumCheck, i, 0, 1, 1, 0);
    layout->addWidget(album, i, 1, 1, 1, 0);
    i++;
    layout->addWidget(yearCheck, i, 0, 1, 1, 0);
    layout->addWidget(year, i, 1, 1, 1, 0);
    i++;
    layout->addWidget(trackCheck, i, 0, 1, 1, 0);
    layout->addWidget(track, i, 1, 1, 1, 0);
    i++;
    layout->addWidget(titleCheck, i, 0, 1, 1, 0);
    layout->addWidget(title, i, 1, 1, 1, 0);
    i++;
    layout->addWidget(commentCheck, i, 0, 1, 1, 0);
    layout->addWidget(comment, i, 1, 1, 1, 0);
    i++;
    layout->addWidget(save, i, 2, 1, 1, 0);


    window->setFixedHeight(450);
    window->setFixedWidth(400);
    window->setLayout(layout);
    window->show();

    return a.exec();

}

void setDarkTheme(QApplication &a) {

    QFile f(":qdarkstyle/style.qss");
    if (f.exists()) {

        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        a.setStyleSheet(ts.readAll());
    }

}
