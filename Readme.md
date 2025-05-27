# 📷 FlirMultiCamera

C++ Library to record synchronized videos and images using [synchronizable Flir Cameras](https://flir.custhelp.com/app/answers/detail/a_id/3385/~/flir-cameras---trigger-vs.-sync-vs.-record-start) on Ubuntu. Also contains python bindings.

![System Setup](content/4cams.gif)


### 🧪 Tested with 
* Spinnaker-2.4.0.143-Ubuntu20.04-amd64-pkg.tar.gz
* 5x Flir Grasshopper GS3-U3-32S-4C

---

### 📜 Citation

If you use this software, please use the GitHub **“Cite this repository”** button at the top(-right) of this page.

---

### Requirements

* USB Card to handle all the video input
* Synchronization cable that connects master cameras Trigger Pin to the Slave cameras input pins.
* In [our case](TODO), we use `Line2` on the Master and `Line3` for the Slave cameras.


---

### Prerequisites

1. Download and install the [Spinnaker SDK](https://www.teledynevisionsolutions.com/products/spinnaker-sdk/?model=Spinnaker%20SDK&vertical=machine%20vision&segment=iisflir ). Make sure that you can run Spinview and that you can get a stable video of each camera.
2. Declare the following environment variables:

```bash
FLIR_MASTER_LINE #Cable line of Master Output i.e. "Line2"
FLIR_SLAVE_LINE #Cable line of Slave Input i.e. "Line3"
FLIR_CAMERA_SERIAL_NUMBERS #Comma separable list of serial numbers, i.e. "19037266,19246521,20174578,19338645,19421325"
FLIR_CAMERA_COUNT #Number of elements in the list above, i.e. 5
FLIR_MASTER_CAM_SERIAL #Serial number of the Master camera i.e. "20174578"
FLIR_TOP_CAM_SERIAL #Serial number of the setups top camera (used to set lower gain)
```

### Installation

Execute this build & installation script:

```bash
./build_install.sh
```

To install the static library, enter your sudo password when asked.

---

### Executables and Exmples

The script generates the following executables. 

To save a synchronized image for each camera run: `./build/record_synchronized_frame`. 

To record synchronized videos, run: `./build/record_synchronized_videos`

You can specify the camera settings by passing a `<your-settings>.json` to each executable as first argument:
```bash
 ./build/record_synchronized_frame /home/docker/modules/FlirMultiCamera/cfg/1024x768.json
 ```
See the json scheme in `./cfg`. 

For the video executable you can further specify the number of frames by passing them as second argument:

```bash
./build/record_synchronized_videos /home/docker/workspace/build/dependencies/FlirMultiCamera/cfg/1024x768.json 40
```

Otherwise the executables will assume the default configuration 1024x768.json and a default frame number of 30. 

You can specify the **savepath** of your images/videos in the the config. If `save_dir` is an empty string it will chose the ./outputs folder as default.  

**Python** example: 
```bash
./src/apps/get_images.py
```