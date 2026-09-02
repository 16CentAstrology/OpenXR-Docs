/*
** Copyright (c) 2017-2026 The Khronos Group Inc.
**
** SPDX-License-Identifier: Apache-2.0
*/

XrInstance instance; // previously initialized
XrSystemId systemId; // previously initialized
XrSession session;   // previously initialized

// The function pointers are previously initialized using
// xrGetInstanceProcAddr.
PFN_xrEnumerateCameraCapabilityTypesBD xrEnumerateCameraCapabilityTypesBD;          // previously initialized
PFN_xrGetCameraSupportedCapabilitiesBD xrGetCameraSupportedCapabilitiesBD;          // previously initialized
PFN_xrCreateCameraDeviceAsyncBD xrCreateCameraDeviceAsyncBD;                        // previously initialized
PFN_xrCreateCameraDeviceCompleteBD xrCreateCameraDeviceCompleteBD;                  // previously initialized
PFN_xrEnumerateAvailableCamerasBD xrEnumerateAvailableCamerasBD;                    // previously initialized
PFN_xrCreateCameraCaptureSessionAsyncBD xrCreateCameraCaptureSessionAsyncBD;        // previously initialized
PFN_xrCreateCameraCaptureSessionCompleteBD xrCreateCameraCaptureSessionCompleteBD;  // previously initialized
PFN_xrBeginCameraCaptureBD xrBeginCameraCaptureBD;                                  // previously initialized
PFN_xrAcquireCameraImageBD xrAcquireCameraImageBD;                                  // previously initialized
PFN_xrGetCameraImageDataBD xrGetCameraImageDataBD;                                  // previously initialized
PFN_xrReleaseCameraImageBD xrReleaseCameraImageBD;                                  // previously initialized
PFN_xrEndCameraCaptureBD xrEndCameraCaptureBD;                                      // previously initialized
PFN_xrDestroyCameraCaptureSessionBD xrDestroyCameraCaptureSessionBD;                // previously initialized
PFN_xrDestroyCameraDeviceBD xrDestroyCameraDeviceBD;                                // previously initialized
PFN_xrPollFutureEXT xrPollFutureEXT;                                                // previously initialized

void waitUntilReady(XrFutureEXT future)
{
    XrFuturePollInfoEXT pollInfo;
	pollInfo.type = XR_TYPE_FUTURE_POLL_INFO_EXT;
    XrFuturePollResultEXT pollResult;
	pollResult.type = XR_TYPE_FUTURE_POLL_RESULT_EXT;

    pollInfo.future = future;
    do
    {
        // sleep(1);
        CHK_XR(xrPollFutureEXT(instance, &pollInfo, &pollResult));
    } while (pollResult.state != XR_FUTURE_STATE_READY_EXT);
}
