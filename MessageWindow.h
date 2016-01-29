#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QDialog>

class QPushButton;
class QLabel;

class MessageWindow : public QDialog
{
	Q_OBJECT
	
	public:
		MessageWindow(QWidget* parent = 0, const QString& message = "Error");
		
	private:
		QLabel *warningMessage;
		QPushButton *confirmButton;
};

#endif
