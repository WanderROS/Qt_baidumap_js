#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTimer>
#include <QWebChannel>
#include <QWebEngineView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
private slots:
  void setflag(bool);
  void timerout();

private:
  Ui::MainWindow *ui;
  bool loadflag;
  float flat;
  float longl;
  QWebEngineView *pEngView;
};

#endif // MAINWINDOW_H
