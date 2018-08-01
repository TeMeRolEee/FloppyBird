#include <QtWidgets>
#include "Bird.h"
#include "Pipe.h"
#include "Game.h"


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    //qDebug()  << "Hellobello";

    QGraphicsView view;
    view.setWindowTitle("FloppyBird");

    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view.setFixedSize(600,600);
    view.setBackgroundBrush(QPixmap("backgroundv2.jpg").scaled(600,600));

    QGraphicsScene scene;
    scene.setSceneRect(view.geometry());
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
/*
    auto *floppy = new Bird();
    floppy->setPos(0,300);
    scene.addItem(floppy);
*/

/*
    auto *pipe1 = new Pipe(200);
    pipe1->setPos(view.width()-pipe1->boundingRect().width(),view.height()-pipe1->boundingRect().height());
    scene.addItem(pipe1);

    auto *pipe2 = new Pipe(200);
    pipe2->setPos(view.width()-pipe2->boundingRect().width(),0);
    scene.addItem(pipe2);
*/
    view.setScene(&scene);
    view.show();

    Game game(scene);
    app.installEventFilter(&game);

    //QTimer timer;
    //QObject::connect(&timer, &QTimer::timeout,&scene, &QGraphicsScene::advance);
    //timer.start(1000 / 60);

    return app.exec();
}