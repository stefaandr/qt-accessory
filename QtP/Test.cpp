#include "Test.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QLCDNumber>
#include <QLineEdit>
#include <QLabel>
#include <boost/lambda/lambda.hpp>

#include "QtP.h"

// function used later on to format the text of a QLabel based on values in two spinboxes
QString twoValuesVerbose(int a0, int a1)
{
	return QString("Two values: %1 and %2").arg(a0).arg(a1);
}
	/// \TODO future work: support C++11 lambda

Test::Test(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout * v = new QVBoxLayout;

	// first row of layout consists of 5 spinboxes
	QSpinBox * sp[5];
	{
		QHBoxLayout * h = new QHBoxLayout;
		for (int i=0; i!=5; ++i)
			h->addWidget(sp[i] = new QSpinBox);
		v->addLayout(h);
	}
	// the second row contains 5 lcd displays
	QLCDNumber * lcd[5];
	{
		QHBoxLayout * h = new QHBoxLayout;
		for (int i=0; i!=5; ++i)
			h->addWidget(lcd[i] = new QLCDNumber);
		v->addLayout(h);
	}

	/* here we connect properties to one another, and perform functions on them on-the-fly */
	using namespace boost::lambda;
	// lcd[0] = sp[0] + sp[1]
	QtP(lcd[0]) << (QtP(sp[0]) + QtP(sp[1]));
	// lcd[1] = 10
	QtP(lcd[1]) << 10;
	// lcd[2] = sp[2] + sp[3] / sp[2]
	QtP(lcd[2]) << QtP(sp[2]).apply <int (int, int)> (_1 + _2 * _1, QtP(sp[3]));
	// lcd[3] = 4 + sp[3]
	QtP(lcd[3]) << 4 + QtP(sp[3]);
	// lcd[4] = - sp[4]
	QtP(lcd[4]) << -QtP(sp[4]);
		// NOTE: QtP is type-safe, but derives the type from the object type that you pass.
		// If QtP doesn't know that object type, it (currently) assumes int type and "value" property name
		// To specify it yourself, use QtPInt(myobj, "propname"), QtPDouble(myobj2, "otherpropname"), etc...

	// some examples on QString-typed properties
	{
		QHBoxLayout * h = new QHBoxLayout;
		QLineEdit * le0 = new QLineEdit; h->addWidget(le0);
		QLineEdit * le1 = new QLineEdit; h->addWidget(le1);
		QLabel * l = new QLabel; h->addWidget(l);
		QtP(l) << QtP(le0) + QString(" and also ") + QtP(le1);
		v->addLayout(h);
	}

	// and just because we hadn't had a function pointer here yet:
	{
		QLabel * display = new QLabel; v->addWidget(display);
		QtP(display) << QtP(sp[0]).apply(twoValuesVerbose, QtP(sp[1]));
	}

	setLayout(v);
}
