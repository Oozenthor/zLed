#include "zled.h"

ZLed::ZLed()
{

}

ZLed::ZLed(QPoint point, QColor color, bool lit, int diameter)
{
  center = point;
  ledColor = color;
  ledLit = lit;
  bezelDiameter = diameter;

  Dimension();
}

ZLed::~ZLed()
{

}

void ZLed::Dimension()
{
  // Bezel width
  bezelWidth = bezelDiameter / 6;

  // Bezel bounding rectangle
  QPoint bezelTopLeft = QPoint(center.x() - (bezelDiameter / 2), center.y() - (bezelDiameter / 2));
  QSize bezelSize = QSize(bezelDiameter, bezelDiameter);
  bezelRect = QRect(bezelTopLeft, bezelSize);

  // Bezel outline path
  bezelPath.moveTo(center);
  bezelPath.arcTo(bezelRect, 0, 360);

  // Bezel shading
  bezelGradient = QLinearGradient(bezelRect.topRight(), bezelRect.bottomLeft());
  bezelGradient.setColorAt(0.0, QColor(Qt::darkGray));
  bezelGradient.setColorAt(1.0, QColor(Qt::black));

  // LED bounding rectangle
  int ledDiameter = bezelDiameter - (bezelWidth * 2);
  QPoint ledTopLeft = QPoint(center.x() - (ledDiameter / 2), center.y() - (ledDiameter / 2));
  QSize ledSize = QSize(ledDiameter, ledDiameter);
  ledRect = QRect(ledTopLeft, ledSize);

  // LED outline path
  ledPath.moveTo(center);
  ledPath.arcTo(ledRect, 0, 360);

  // LED "Bright spot"
  focalPoint = QPoint(center.x() + (bezelDiameter / 8), center.y() - (bezelDiameter / 8));
}

void ZLed::Render(QPainter &painter)
{
  // Set LED color intensities
  if (!ledLit) {
    ledColor.setHsv(ledColor.hue(), ledColor.saturation(), ledColor.value()*0.2);
  }
  ledColorLow.setHsv(ledColor.hue(), ledColor.saturation(), ledColor.value()*0.4);

  // Set LED gradients
  ledGradient = QRadialGradient(focalPoint, ledRect.width());
  ledGradient.setColorAt(0.0, ledColor);
  ledGradient.setColorAt(1.0, ledColorLow);

  // Draw everything
  painter.setRenderHint(QPainter::Antialiasing);

  painter.setPen(Qt::NoPen);

  painter.setBrush(bezelGradient);
  painter.drawPath(bezelPath);

  painter.setBrush(ledGradient);
  painter.drawPath(ledPath);
}

