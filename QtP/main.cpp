#include <QApplication>

#include "Test.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Test myTest;
	myTest.show();

	a.exec();
}
