#include <OVR_CAPI.h>
#include <iostream>
#include <thread>
#include <fstream>

using namespace std;

void HeadTrackingApplication(void);

int main(void) {
	cout << "running app" << endl;
	HeadTrackingApplication();
		
	system("pause");
	return 0;
}
 
void HeadTrackingApplication(void){
	ofstream myfile;
	myfile.open("headtrackingdata.txt");

	ovrResult result = ovr_Initialize(nullptr);
	if (OVR_FAILURE(result))
		return;

	ovrSession session;
	ovrGraphicsLuid luid;
	result = ovr_Create(&session, &luid);
	if (OVR_FAILURE(result)) {
		ovr_Shutdown();
		return;
	}
	ovrHmdDesc desc = ovr_GetHmdDesc(session);
	ovrSizei resolution = desc.Resolution;

	// orientation data
	while (true) {
		ovrTrackingState ts;
		ts = ovr_GetTrackingState(session, ovr_GetTimeInSeconds(), ovrTrue);
		
		if (ts.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked)){
			ovrPosef pose = ts.HeadPose.ThePose;
			ovrQuatf orient = pose.Orientation;

			cout << "Orientation data:" <<endl;
			cout << "x: " << orient.x << endl;
			cout << "y: " << orient.y << endl;
			cout << "z: " << orient.z << endl;

			//writing to the file 
			myfile << orient.x << endl;
			myfile << orient.y << endl;
			myfile << orient.z << endl;
			myfile << endl;

			this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
	ovr_Destroy(session);
	ovr_Shutdown();
}
