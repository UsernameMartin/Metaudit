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
#include <iostream>
#include <string>
#include "dataextractor.h"
#include "fileselection.h"
#include "dataeditors.h"
#include "datasaver.h"
#include "genreselection.h"
#include "inputline.h"
#include "pictureselection.h"

void setDarkTheme(QApplication &a);

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    QIcon icon("icon.ico");
    a.setWindowIcon(icon);
    setDarkTheme(a);
    QWidget *window = new QWidget();
    QGridLayout *layout = new QGridLayout(window);

    QCheckBox *pictureCheck = new QCheckBox("Picture file (full path):", window);
    pictureCheck->setChecked(true);
    InputLine *picture = new InputLine(window, pictureCheck);
    QLabel *pictureLabel = new QLabel();
    PictureSelection* pictureSelection = new PictureSelection(window, picture, pictureLabel, layout);
    QPushButton *selectFile = new QPushButton("Browse...", window);
    QLineEdit *path = new QLineEdit(window);
    QLabel *pathLabel = new QLabel("File (full path):", window);
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
    GenreSelection *genre = new GenreSelection(window);
    QPushButton *save = new QPushButton("Save data", window);

    track->setValidator(new QIntValidator(1, 100000000, window));
    year->setValidator(new QIntValidator(0, 2060, window));
    DataEditors *editors = new DataEditors(window, title, track, album, author, year, genre);
    DataExtractor *extractor = new DataExtractor(window, editors, path);
    DataSaver *saver = new DataSaver(window, editors, path);
    QObject::connect(showData, SIGNAL(clicked()), extractor, SLOT(extractData()));
    QObject::connect(save, SIGNAL(clicked()), saver, SLOT(saveData()));

    layout->addWidget(pathLabel, 0, 0, 1, 1, 0);
    layout->addWidget(path, 0, 1, 1, 1, 0);
    layout->addWidget(selectFile, 0, 2, 1, 1, 0);
    layout->addWidget(showData, 1, 0, 1, 1, 0);
    layout->addWidget(authorCheck, 2, 0, 1, 1, 0);
    layout->addWidget(author, 2, 1, 1, 1, 0);
    layout->addWidget(albumCheck, 3, 0, 1, 1, 0);
    layout->addWidget(album, 3, 1, 1, 1, 0);
    layout->addWidget(trackCheck, 4, 0, 1, 1, 0);
    layout->addWidget(track, 4, 1, 1, 1, 0);
    layout->addWidget(titleCheck, 5, 0, 1, 1, 0);
    layout->addWidget(title, 5, 1, 1, 1, 0);
    layout->addWidget(yearCheck, 6, 0, 1, 1, 0);
    layout->addWidget(year, 6, 1, 1, 1, 0);
    layout->addWidget(genre, 7, 1, 1, 1, 0);
    layout->addWidget(save, 8, 2, 1, 1, 0);
    layout->addWidget(pictureCheck, 9, 0, 1, 1, 0);
    layout->addWidget(picture, 9, 1, 1, 1, 0);
    layout->addWidget(pictureSelection, 9, 2, 1, 1, 0);
    layout->addWidget(pictureLabel, 10, 1);

    window->setFixedHeight(350);
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
