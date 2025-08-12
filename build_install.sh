#!/bin/bash

export FLIR_MASTER_LINE="Line2" #Cable line of Master Output i.e. "Line2"
export FLIR_SLAVE_LINE="Line3" #Cable line of Slave Input i.e. "Line3"
export FLIR_CAMERA_SERIAL_NUMBERS="20202480,19246523" #Comma separable list of serial numbers, i.e. "19037266,19246521,20174578,19338645,19421325"
export FLIR_CAMERA_COUNT=2 #Number of elements in the list above, i.e. 5
export FLIR_MASTER_CAM_SERIAL="20202480" #Serial number of the Master camera i.e. "20174578"
export FLIR_TOP_CAM_SERIAL="20202480" #Serial number of the setups top camera (used to set lower gain)

rm -rf build; mkdir build

cd build

cmake ..

make -j$(nproc)

sudo make install
