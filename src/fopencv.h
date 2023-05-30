
#ifndef FOPENCV_H
#define FOPENCV_H
#include "../MSVC/14.35.32215/include/string"
#include "../opencv/build/include/opencv2/core.hpp"
#include "../opencv/build/include/opencv2/imgproc.hpp"
#include "../opencv/build/include/opencv2/photo.hpp"
#include "../opencv/build/include/opencv2/highgui.hpp"
#include "../opencv/build/include/opencv2/opencv.hpp"
#include "../MSVC/14.35.32215/include/iostream"
#include "../MSVC/14.35.32215/include/vector"

struct Coords {
	int x, y;
};

class fopencv
{
public:
	fopencv();
	~fopencv();
	cv::Vec3b getPixel(cv::Mat img, int x, int y);
	cv::Mat CreateMat(std::string path);
	void showImg(std::string path);
	cv::Mat DetectContours(cv::Mat img);
	void getContours(std::string pathImg);
	void showImgtest(std::string path);
	bool findImage(std::string tempimg,std::string backgroundimage, int&x, int&y);
	bool findMultipleImage(std::string tempimg,std::vector<Coords>&listcoords);
	bool checkImage(std::string tempimg);

private:
	
	
};
#endif
