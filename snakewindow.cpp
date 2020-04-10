#include "snakewindow.h"
#include "ui_snakewindow.h"
#include <snakehead.h>
#include <snakebody.h>
#include <random>
Snakewindow::Snakewindow(QWidget *parent): QMainWindow(parent), ui(new Ui::Snakewindow)
{

	bodies.prepend(new Snakebody());
	timerf = new QTimer();
	fruit = new Fruit(this);
	timer = new QTimer();
	scene = new QGraphicsScene(0,0,800,800);
	head = new Snakehead(this);
	ui->setupUi(this);
	fruit->setPos(scene->width() / 2, scene->height() / 2);
	ui->Score->setPalette(Qt::red);
	ui->Snakeview->setScene(scene);
	ui->Snakeview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui->Snakeview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	scene->addItem(fruit);
	scene->addItem(head);
	scene->addItem(bodies.front());

	connect(timer,SIGNAL(timeout()),this,SLOT(timeevent()));
	connect(this,SIGNAL(eaten()),this,SLOT(hasbeeneaten()));
	connect(timerf,SIGNAL(timeout()),this,SLOT(collisioncheck()));


}


Snakewindow::~Snakewindow()
{
	delete ui;
}

void Snakewindow::movebodies(QPointF prevpos)
{
	for (size_t t = 0;t < bodies.size() - 1;t++)
		{
				bodies[t]->setPos(bodies[t+1]->pos());
		}
	bodies.last()->setPos(prevpos);

}

void Snakewindow::makebody()
{
	Snakebody* body = new Snakebody(this);
	bodies.prepend(body);
	body->setPos(bodies.last()->pos());
	scene->addItem(body);
}





void Snakewindow::on_Startgame_clicked()
{
	score = 0;
	timerf->start(100);
	scene->setFocusItem(head);
	timer->start(100);
	ui->Startgame->close();
}






void Snakewindow::timeevent()
{
		QPointF prevpos = head->pos();
	if(head->getdirection() == Snakehead::DOWN)
		{
			head->setPos(head->pos().x(),head->pos().y() + 50);
		}
	if(head->getdirection() == Snakehead::UP)
		{
			head->setPos(head->pos().x(),head->pos().y() - 50);
		}
	if(head->getdirection() == Snakehead::LEFT)
		{
			head->setPos(head->pos().x() - 50,head->pos().y());
		}
	if(head->getdirection() == Snakehead::RIGHT)
		{
			head->setPos(head->pos().x() + 50,head->pos().y());
		}
		movebodies(prevpos);



}

void Snakewindow::hasbeeneaten()
{
	fruit->setPos(random() % (int)(scene->width()),random() % (int)scene->height());
	makebody();
}

void Snakewindow::collisioncheck()
{

	if(head->collidesWithItem(fruit))
		{
			score++;
			ui->Score->display(score);
			emit hasbeeneaten();
		//	qDebug()<<"COLISION";
		}

	//for(size_t t = 0;t < bodies.size() - 1;t++)
		{
		//	if(head->collidesWithItem(bodies[t]))
		//	emit Gameover();
		}

}

void Snakewindow::Gameover()
{
timer->stop();
}






