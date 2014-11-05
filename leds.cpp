#include "leds.h"
#include "ui_leds.h"

LEDs::LEDs(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::LEDs)
{
  ui->setupUi(this);
  toggle = true;

  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(cycleLeds()));
  timer->start(500);
}

LEDs::~LEDs()
{
  delete ui;
}

void LEDs::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);

  QPainter painter(this);
/*
  ZLed redLed(QPoint(50, 50), Qt::red, toggle );
  redLed.Render(painter);
  ZLed greenLed(QPoint(150, 50), Qt::green, toggle );
  greenLed.Render(painter);
  ZLed blueLed(QPoint(250, 50), Qt::blue, toggle );
  blueLed.Render(painter);

  ZLed whiteLed(QPoint(50, 150), Qt::white, toggle );
  whiteLed.Render(painter);
  ZLed cyanLed(QPoint(150, 150), Qt::cyan, toggle );
  cyanLed.Render(painter);
  ZLed magentaLed(QPoint(250, 150), Qt::magenta, toggle );
  magentaLed.Render(painter);

  ZLed yellowLed(QPoint(50, 250), Qt::yellow, toggle );
  yellowLed.Render(painter);
  ZLed lightGrayLed(QPoint(150, 250), Qt::lightGray, toggle );
  lightGrayLed.Render(painter);
*/

  int x, y, col;

  for(y=0; y<3; y++) {
    for(x=0; x<3; x++) {
      col = 6 + qrand() % 7;
      if (col == 6) {
        col = 3; //white
      }
      ZLed Led(QPoint(50+x*80, 50+y*80), (Qt::GlobalColor)(col), qrand() % 2, 70);
//      ZLed Led(QPoint(50+x*85, 50+y*85), QColor((127 + qrand() % 128), (127 + qrand() % 128), (127 + qrand() % 128)), qrand() % 2);
      Led.Render(painter);
    }
  }
}

void LEDs::on_toggleButton_clicked()
{
  if (toggle) {
    timer->stop();
  } else {
    timer->start();
  }
  toggle = !toggle;
  QWidget::update();
}

void LEDs::cycleLeds()
{
  QWidget::update();
}
