#ifndef ADDCOURSE_H
#define ADDCOURSE_H

#include <QDialog>

class QPushButton;
class QLabel;
class QComboBox;
class QLineEdit;

class AddCourse : public QDialog
{
	Q_OBJECT
	
	public:
		AddCourse(QWidget* parent = 0);
		void reset();
		
	signals:
		void courseSend(const QString&, const QString&);
		
	private slots:
		void addClicked();
		void enableAddButton(const QString &);
		void enableAddButton(int);
		
	private:
		QLabel *courseLabeller;
		QLabel *letterLabeller;
		QComboBox *letterGrade;
		QLineEdit *courseName;
		QPushButton *addButton;
		QPushButton *cancelButton;
};

#endif
