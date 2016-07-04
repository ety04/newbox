#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QSplitter>

class FenPrincipale : public QMainWindow
{
    Q_OBJECT
public:
    FenPrincipale();
    FenPrincipale(int w, int h);

private:
    QPushButton* quitter;
    QTextEdit* affichage;
    QLineEdit* adresse;
    QPushButton* ouverture;

    QTreeView* vue;
    QListView* liste;
    QDirModel* model;
    QSplitter* splitter;

signals:

public slots:
    void ouvrir();
    void majAdresse(QModelIndex ind);
};

#endif // FENPRINCIPALE_H
