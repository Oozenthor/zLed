#ifndef LEDS_H
#define LEDS_H

#include <QDialog>
#include <QPainter>
#include <QTimer>

#include "zled.h"

namespace Ui {
class LEDs;
}

class LEDs : public QDialog
{
  Q_OBJECT

public:
  explicit LEDs(QWidget *parent = 0);
  ~LEDs();

protected:
  void paintEvent(QPaintEvent *event);

private slots:
  void on_toggleButton_clicked();
  void cycleLeds();

private:
  Ui::LEDs *ui;
  bool toggle;
  QTimer *timer;
};

#endif // LEDS_H
