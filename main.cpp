#include "bridge.h"
#include "mainwindow.h"
#include <QApplication>
#include <QTimer>
#include <QWebChannel>
#include <QWebEngineView>
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  MainWindow w;
  w.show();

  return a.exec();
}
