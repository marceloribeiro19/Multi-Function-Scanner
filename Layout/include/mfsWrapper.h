#ifndef MFSWRAPPER_H
#define MFSWRAPPER_H

#include <QObject>
//#include "/home/pedro/Desktop/Pthreads/MFS/mfs.h"
class MFS;

class MFSWrapper : public QObject {
    Q_OBJECT

public:
    MFSWrapper();
    ~MFSWrapper();

    static MFSWrapper& getInstance();

public slots:
    void emitUpdateLCDSignal(double value);

signals:
    void updateLCDSignal(double value);

private:
    MFS* instance;
};



#endif // MFSWRAPPER_H
