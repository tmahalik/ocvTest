#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;


// all of this works such as it is
// so  I just needed to exclude the ffmpeg stuff
// when I built opencv

int main()
{
    
    VideoCapture camera;
    camera.open(0);
    cv::namedWindow("Webcam", cv::WINDOW_AUTOSIZE);
    // this will contain the image from the webcam
    cv::Mat frame;
    // capture the next frame from the webcam
    if( !camera.isOpened())
    {
        cout << "can't open camera " << endl;
        exit(-1);
    }
    while(true)
    {
        // show the image on the window
        camera >> frame;
        cv::imshow("Webcam", frame);
        // wait (10ms) for a key to be pressed
        if (cv::waitKey(10) >= 0)
            break;
    }
    return 0;
}
