#ifndef ZLED_H
#define ZLED_H

//#include <QGraphicsItem>
#include <QPainter>
#include <QPainterPath>

class ZLed
{
public:
  ZLed();
  ZLed(QPoint point, QColor color=Qt::red, bool lit=true, int diameter=80);
  ~ZLed();

  void Render(QPainter &painter);

private:
  void Dimension(void);
  QPoint center;

  QRect bezelRect;
  QPainterPath bezelPath;
  QLinearGradient bezelGradient;

  int bezelDiameter;
  int bezelWidth;

  QRect ledRect;
  QPainterPath ledPath;
  QRadialGradient ledGradient;

  QColor ledColor;
  QColor ledColorLow;
  bool ledLit;

  QPoint focalPoint;
};

#endif // ZLED_H
