#include "area.h"

Area::Area(QGraphicsItem* parent): Chart(parent), _series(QList<QLineSeries*>()){
    setAnimationOptions(QChart::SeriesAnimations);
    legend()->hide();
}
/**
 * @brief Area::setSeries
 * @param table
 * @param indexes : lista di indici della tabella indici che partono da 0;
 * @param parseDirection
 */
void Area::setSeries(QTableWidget* table, const QModelIndexList& indexes, Flags parseDirection){
    clearData();
    switch(parseDirection){
        case(Flags::ROW):{

            for(int i=indexes.last().row(); i>=indexes.first().row();i--){
                QLineSeries *series = new QLineSeries();
                int pC=0;
                for(int j=indexes.first().column(); j<=indexes.last().column();j++){
                    QTableWidgetItem* item = table->item(i, j);
                    if(item && item->text()!="") {
                        series->append(++pC,item->text().toInt());
                    }
                }
                if(series->count() > 0) _series.append(series);
                else delete series;
            }
        }
        break;
        case(Flags::COLUMN):{
            for(int j=indexes.last().column(); j>=indexes.first().column();j--){
                QLineSeries *series = new QLineSeries();
                int pC=0;
                for(int i=indexes.first().row(); i<=indexes.last().row();i++){
                    QTableWidgetItem* item = table->item(i, j);
                    if(item) *series << QPointF(++pC,item->text().toInt());
                }
                if(series->count() > 0) _series.append(series);
            }
        }
        break;
        default:
            //Lancia eccezioni
        break;
    }
    refresh();
}

void Area::clearData(){
    // It will only destroy pointers, not the objects behind them (same with removeAt() of course). Delete needs to be called explicitely on each item or, as already said, qDeleteAll() can be used.
    removeAllSeries();
    _series.clear();
}

void Area::refresh(){
    removeAllSeries();
    QPen pen(0x059605);
    pen.setWidth(3);
    for(auto it=_series.begin(); it!=_series.end(); it++){
        if((*it)->count() > 1){
            QAreaSeries *series = new QAreaSeries(*it);
            (*it)->setPen(pen);
            addSeries(series);
        }
    }
    createDefaultAxes();
}
