#ifndef SNAKEWINDOW_H
#define SNAKEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <snakehead.h>
#include <snakebody.h>
#include <QDebug>
#include <QList>
#include <fruit.h>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class Snakewindow; }
QT_END_NAMESPACE

class Snakewindow : public QMainWindow
{
		Q_OBJECT

	public:
		Snakewindow(QWidget *parent = nullptr);
		~Snakewindow();
		void movebodies(QPointF);
		void makebody();
	private slots:
		void on_Startgame_clicked();

	public slots:
		void timeevent();
		void hasbeeneaten();
		void collisioncheck();
		void Gameover();

	signals:
	void eaten();

	private:
		int score;
		QTimer *timerf;
		QTimer *timer;
		Snakehead* head;
		QList<Snakebody*> bodies;
		QPointF point;
		QGraphicsScene *scene;
		Ui::Snakewindow *ui;
		Fruit* fruit;
};
#endif // SNAKEWINDOW_H
