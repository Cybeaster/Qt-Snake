#include "snakewindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Snakewindow w;
	w.show();
	return a.exec();
}
