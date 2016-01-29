#ifndef DELETECOURSE_H
#define DELETECOURSE_H

#include <QDialog>

// Forward declarations
class QPushButton;
class QLabel;
class QComboBox;

/// Class for handling the course deletion dialog of the program
/**
 * Class does the grunt work of course deletion and provides a dynamic
 * list of what can be deleted 
 */
class DeleteCourse : public QDialog
{
	// Meta object compiler macro
	Q_OBJECT
	
	public:
		/// Constructor for the DeleteCourse class
		DeleteCourse(QWidget* parent = 0);
		
		/// Resetter for the class
		void reset(QLabel* courseName1, QLabel* courseName2, QLabel* courseName3, QLabel* courseName4, QLabel* courseName5);
		
	signals:
		void deleteSend(const QString&);
		
	private slots:
		void deleteClicked();
		
	private:
		/// Labeller variable
		QLabel *courseLabeller;
		
		/// Combo box for a dynamic list of courses
		QComboBox *courseList;
		
		/// Variables for our buttons
		QPushButton *deleteButton;
		QPushButton *cancelButton;
};

#endif
