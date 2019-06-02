#include"graphwidget.h"
#include"rasterwindow.h"
#include"Graph.h"
#include"Edge.h"
#include"Dijkstra.h"
#include<vector>
#include<math.h>
#define PI 3.14159265358979323
#define SHARPNESS 0.25
#define arrow_len 20

using namespace std;

void GraphVisualization::drawArrow(QPainter *p, QPoint x1, QPoint x2)
{
    p->setPen(QColor(0,255,0));
    p->drawLine(x1,x2);
    QPoint arrow =x2-x1;
    //float arrow_len = sqrt(arrow.x()*arrow.x()+arrow.y()*arrow.y())/7;
    float angle = atan2(arrow.y(),arrow.x());


    QPoint arr[3] = {
            x2,
            QPoint(x2.x() - arrow_len * cos(angle - SHARPNESS),x2.y() - arrow_len * sin(angle - SHARPNESS)),
            QPoint(x2.x() - arrow_len * cos(angle + SHARPNESS),x2.y() - arrow_len * sin(angle + SHARPNESS))
        };
    p->setPen(QColor(0,0,0));
    p->setBrush(QColor(0,0,0));
    p->drawConvexPolygon(arr,3);
}

void GraphVisualization::render(QPainter* p)
{
    vector<QPoint> vertex(g.get_v());

    p->translate(width() / 2, height() / 2);
    p->setPen(QColor(0,255,0));


    for(int i=0;i<g.get_v();i++)
    {
        vertex[i]=QPoint(100*cos((2*PI*i/g.get_v())),100*sin((2*PI*i/g.get_v())));
    }

    for (int i=0;i<g.get_v();i++)
    {
        vector<edge> vec = g.adjency_to(i);
        for(vector<edge>::iterator it = vec.begin(); it != vec.end(); it++)
            drawArrow(p,vertex[it->from()],vertex[it->to()]);
            //p->drawLine(vertex[it->from()],vertex[it->to()]);
    }

     p->setBrush(QColor(0,255,0));

    for(int i=0;i<g.get_v();i++){
        p->drawEllipse(vertex[i],5,5);
    }

//    p->setRenderHint(QPainter::Antialiasing);
//    p->setBrush(QColor(0,0,0));
//    p->save();
//    p->setPen(QColor(0,255,0));


}

GraphVisualization::GraphVisualization(weighted_digraph &gr)
{
    setTitle("Это граф");
    resize(500,500);
    g = gr;
}
