#ifndef OCR_H
#define OCR_H
#include "fopencv.h"
#include "../MSVC/14.35.32215/include/string"
#include "../MSVC/14.35.32215/include/fstream"
#include "../tesseract/include/tesseract/baseapi.h"
#include "../MSVC/14.35.32215/include/iostream"
#include "../MSVC/14.35.32215/include/regex"
using namespace cv;
using namespace std;
using namespace tesseract;
class ocr
{
	public:
        ocr();
        ~ocr();
       bool detectText(string targetWord,int x,int y);
	private:
        string outText, imPath = "./img/screenshot.png";
        Mat im;
        ofstream file;
        tesseract::TessBaseAPI* api;
};
#endif

