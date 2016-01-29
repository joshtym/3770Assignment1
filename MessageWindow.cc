#include "MessageWindow.h"
#include <QtGui>

MessageWindow::MessageWindow(QWidget* parent, const QString& message) : QDialog(parent)
{
	warningMessage = new QLabel(message);
	QLabel* emptySpace = new QLabel("");
	confirmButton = new QPushButton("Ok");
	
	QHBoxLayout *buttons = new QHBoxLayout;
	QVBoxLayout *primaryLayout = new QVBoxLayout;
	
	connect(confirmButton, SIGNAL(clicked()), this, SLOT(close()));
	
	buttons->addWidget(emptySpace);
	buttons->addWidget(confirmButton);
	buttons->addWidget(emptySpace);
	
	primaryLayout->addWidget(warningMessage);
	primaryLayout->addLayout(buttons);
	setLayout(primaryLayout);
}
