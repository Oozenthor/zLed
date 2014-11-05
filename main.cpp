#include "leds.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  LEDs w;
  w.show();

  return a.exec();
}
