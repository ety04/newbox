#include <QApplication>
#include "fenprincipale.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale fenetre(800, 600);

    fenetre.show();
    return app.exec();
}

