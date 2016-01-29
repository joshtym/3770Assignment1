#include <QtGui>
#include "MessageWindow.h"

MessageWindow::MessageWindow(QWidget* parent, const QString& message) : QDialog(parent)
{
	// Message initializer
	warningMessage = new QLabel(message);
	
	// Confirmation button initializer
	confirmButton = new QPushButton("Ok");
	
	// Let's initialize a variable to make some empty space around the button
	QLabel* emptySpace = new QLabel("");
	
	// Our layout initializer
	QHBoxLayout *buttons = new QHBoxLayout;
	QVBoxLayout *primaryLayout = new QVBoxLayout;
	
	// Connection to close the box when the user confirms
	connect(confirmButton, SIGNAL(clicked()), this, SLOT(close()));
	
	// Populate the button layout
	buttons->addWidget(emptySpace);
	buttons->addWidget(confirmButton);
	buttons->addWidget(emptySpace);
	
	// Populate the primary layout
	primaryLayout->addWidget(warningMessage);
	primaryLayout->addLayout(buttons);
	
	// Set the layout to the primary layout
	setLayout(primaryLayout);
}
