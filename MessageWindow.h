#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QDialog>

// Forward declaration
class QPushButton;
class QLabel;

/// Class for handling message dialogs of the program
/**
 * Class does the grunt work of course deletion and provides a dynamic
 * list of what can be deleted 
 */
class MessageWindow : public QDialog
{
	// Meta object compiler macro
	Q_OBJECT
	
	public:
		/// Constructor for the Message Window
		MessageWindow(QWidget* parent = 0, const QString& message = "Error");
		
	private:
		/// Message of the box
		QLabel *warningMessage;
		
		/// Confirmation button to exit
		QPushButton *confirmButton;
};

#endif
