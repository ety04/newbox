#include "fenprincipale.h"

FenPrincipale::FenPrincipale() : QMainWindow()
{
    setFixedSize(600, 400);
}

FenPrincipale::FenPrincipale(int w, int h) : QMainWindow()
{
    setFixedSize(w, h);
    setWindowTitle("NewBox");
    move(100, 50);

    QWidget* win = new QWidget;
    setCentralWidget(win);

    QVBoxLayout *vb = new QVBoxLayout;

    adresse = new QLineEdit;
    adresse->setReadOnly(true);
    vb->addWidget(adresse);

    affichage = new QTextEdit;
    vb->addWidget(affichage);

    splitter = new QSplitter;
    model = new QDirModel;
    vue = new QTreeView(splitter);
    vue->setModel(model);
    vue->setRootIndex(model->index("/home/ety"));
    vue->setRootIsDecorated(false);
    vb->addWidget(splitter);
    vb->addWidget(vue);
    liste = new QListView(splitter);
    liste->setModel(model);
    liste->setDragEnabled(true);
    vb->addWidget(liste);
    splitter->show();

    connect(vue, SIGNAL(clicked(QModelIndex)), liste, SLOT(setRootIndex(QModelIndex)));
    connect(vue, SIGNAL(clicked(QModelIndex)), this, SLOT(majAdresse(QModelIndex)));
    connect(liste, SIGNAL(doubleClicked(QModelIndex)), liste, SLOT(setRootIndex(QModelIndex)));
    connect(liste, SIGNAL(doubleClicked(QModelIndex)), vue, SLOT(setCurrentIndex(QModelIndex)));

    ouverture = new QPushButton("Ouvrir");
    connect(ouverture, SIGNAL(clicked()), this, SLOT(ouvrir()));
    vb->addWidget(ouverture);

    quitter = new QPushButton("Quitter");
    connect(quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    vb->addWidget(quitter);

    win->setLayout(vb);
}


void FenPrincipale::ouvrir()
{
    QString fn = QFileDialog::getOpenFileName(this, "Ouvrir", QString(), "fichier texte (*.txt)");
    if(!fn.isEmpty())
    {
        adresse->setText(fn);
        QRegExp rx("(\\/)"); // RegEx for / or \;
        QStringList query = fn.split(rx);
        QString nom = query[query.size()-1];
        affichage->append(nom);

    }
}

void FenPrincipale::majAdresse(QModelIndex ind)
{
    adresse->setText(ind.model()->objectName());

}
