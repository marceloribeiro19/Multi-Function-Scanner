#include "mfsWrapper.h"


MFSWrapper::MFSWrapper() {}

MFSWrapper::~MFSWrapper() {}

MFSWrapper& MFSWrapper::getInstance() {
    static MFSWrapper instance;
    return instance;
}

void MFSWrapper::emitUpdateLCDSignal(double value) {
    emit updateLCDSignal(value);
}
