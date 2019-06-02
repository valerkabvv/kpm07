#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H


#include<QtGui>
#include"Graph.h"
#include"Dijkstra.h"
#include"rasterwindow.h"

class GraphVisualization:public rasterWindow
{
private:
    weighted_digraph g;

    void render(QPainter* p) override;
    void drawArrow(QPainter* p,QPoint x1, QPoint x2);

public:
    GraphVisualization(weighted_digraph &gr);

};



#endif // GRAPHWIDGET_H
