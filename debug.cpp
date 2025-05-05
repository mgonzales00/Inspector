#include "debug.h"

Debug::Debug(QString title, QString text)
{
    QMessageBox msgBox;

    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.exec();
}
