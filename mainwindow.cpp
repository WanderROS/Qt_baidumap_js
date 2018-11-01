#include "mainwindow.h"
#include "bridge.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QUrl>
#include <QWebChannel>
#include <QWebEngineView>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  loadflag = false;
  flat = 116;
  longl = 39;
  pEngView = new QWebEngineView(this);
  pEngView->setMinimumSize(800, 600);
  QWebChannel *channel = new QWebChannel;
  channel->registerObject("bridge", (QObject *)bridge::instance());
  pEngView->page()->setWebChannel(channel);
  pEngView->setContextMenuPolicy(Qt::NoContextMenu);
  pEngView->page()->load(QUrl("qrc:/test.html"));

  pEngView->show();
  QObject::connect(pEngView, SIGNAL(loadFinished(bool)), this,
                   SLOT(setflag(bool)));
  QTimer *timer = new QTimer(this);
  QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timerout()));
  timer->start(1000);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::setflag(bool t) { loadflag = t; }

void MainWindow::timerout() {

  if (loadflag == true) {
    flat += 0.01;
    longl += 0.01;
    pEngView->page()->runJavaScript(
        QString("theLocationl(%1,%2)").arg(flat).arg(longl));
  }
}
