/*

(C) 2014 by Karel Patlejch

Licensed under GNU GPL 2.0

TagLib: taglib.github.io/
Qt 4.8- (C) by Trolltech: http://qt-project.org/

*/

#include "genreselection.h"

GenreSelection::GenreSelection(QWidget *parent, QCheckBox *pCheck) :
    QComboBox(parent) {

    check = pCheck;
    QObject::connect(check, SIGNAL(toggled(bool)), this, SLOT(hide(bool)));
    setInsertPolicy(QComboBox::InsertAlphabetically);
    addItem("Blues");
    addItem("Classic Rock");
    addItem("Country");
    addItem("Dance");
    addItem("Disco");
    addItem("Funk");
    addItem("Grunge");
    addItem("Hip-Hop");
    addItem("Jazz");
    addItem("Metal");
    addItem("New Age");
    addItem("Oldies");
    addItem("Other");
    addItem("Pop");
    addItem("R&B");
    addItem("Rap");
    addItem("Reggae");
    addItem("Rock");
    addItem("Techno");
    addItem("Industrial");
    addItem("Alternative");
    addItem("Ska");
    addItem("Death Metal");
    addItem("Pranks");
    addItem("Soundtrack");
    addItem("Euro-Techno");
    addItem("Ambient");
    addItem("Trip-Hop");
    addItem("Vocal");
    addItem("Jazz+Funk");
    addItem("Fusion");
    addItem("Trance");
    addItem("Classical");
    addItem("Instrumental");
    addItem("Acid");
    addItem("House");
    addItem("Game");
    addItem("Sound Clip");
    addItem("Gospel");
    addItem("Noise");
    addItem("AlternRock");
    addItem("Bass");
    addItem("Soul");
    addItem("Punk");
    addItem("Space");
    addItem("Meditative");
    addItem("Instrumental Pop");
    addItem("Instrumental Rock");
    addItem("Ethnic");
    addItem("Gothic");
    addItem("Darkwave");
    addItem("Techno-Industrial");
    addItem("Electronic");
    addItem("Pop-Folk");
    addItem("Eurodance");
    addItem("Dream");
    addItem("Southern Rock");
    addItem("Comedy");
    addItem("Cult");
    addItem("Gangsta Rap");
    addItem("Top 40");
    addItem("Christian Rap");
    addItem("Pop / Funk");
    addItem("Jungle");
    addItem("Native American");
    addItem("Cabaret");
    addItem("New Wave");
    addItem("Psychedelic");
    addItem("Rave");
    addItem("Showtunes");
    addItem("Trailer");
    addItem("Lo-Fi");
    addItem("Tribal");
    addItem("Acid Punk");
    addItem("Acid Jazz");
    addItem("Polka");
    addItem("Retro");
    addItem("Musical");
    addItem("Rock & Roll");
    addItem("Hard Rock");
    addItem("");

}

void GenreSelection::hide(bool show) {
    if(show) {
        setVisible(true);

    } else {
        setVisible(false);
    }
}
