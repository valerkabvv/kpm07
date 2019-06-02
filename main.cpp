#include"Graph.h"
#include"Dijkstra.h"
#include"Edge.h"
#include<iostream>
#include <QPoint>
#include <QtGui>
#include"graphwidget.h"
#include "rasterwindow.h"

int main(int argc, char *argv[])
{
    weighted_digraph g(5);
    g.add_edge(edge(0, 1, 1));
    g.add_edge(edge(0, 3, 2));
    g.add_edge(edge(0, 4, 1));
    g.add_edge(edge(1, 3, 1));
    g.add_edge(edge(2, 1, 1));
    g.add_edge(edge(3, 0, 1));
    g.add_edge(edge(4, 2, 1));
    g.add_edge(edge(3, 2, 1));
    g.add_edge(edge(3, 4, 1));

     DijkstraSP d(g, 2);

     cout << d.get_dist(0)<<" " << d.get_dist(1) <<" "<< d.get_dist(2)<<" " << d.get_dist(3)<<" " << d.get_dist(4);

     QGuiApplication app(argc, argv);

     GraphVisualization graph(g);
     graph.show();
     return app.exec();
}

